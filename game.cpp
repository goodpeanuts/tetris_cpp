#include "game.h"

namespace gm
{
    bool running;
    Piece one_piece;
    Matrix playfield;
    Matrix frame;
    std::chrono::microseconds duration;

    void init()
    {
        running = true;
        one_piece = pick();
        playfield = Matrix(10, std::vector<int>(22, 0));
        frame = playfield;
        one_piece.set_playfield(std::make_shared<Matrix>(playfield));
        duration = 500ms;
    }

    Piece pick()
    {
        // TODO: random take preview queue
        return Piece(L, 4, 20, 0);
    }

    void render()
    {
        auto backup = frame;
        frame = playfield;
        auto [x, y] = one_piece.get_position();
        try
        {
            for (auto i:iota(0, 4))
            {
                auto [dx, dy] = one_piece.get_mino(i);
                frame.at(x + dx).at(y + dy) = one_piece.get_color();
            }

            // display shadow piece
            while (one_piece.test(x, --y));
            y ++;
            for (auto i : iota(0, 4))
            {
                auto [dx, dy] = one_piece.get_mino(i);

                if (frame.at(x + dx).at(y + dy) == 0)
                    frame.at(x + dx).at(y + dy) = 0 - one_piece.get_color();
            }
        }
        catch(const std::out_of_range& e)
        {
            frame = backup;
            std::cerr << "Error: Array index out of range - " << e.what() << std::endl;
        }
    }

    void update()
    {
        render();
        if (ut::timer(duration))
        {
            one_piece.down();
        }
    }

    void quit()
    {
        running = false;
    }
    void rotate()
    {
        one_piece.rotate();
    }
    void left()
    {
        one_piece.left();
    }
    void right()
    {
        one_piece.right();
    }
    void down()
    {
        one_piece.down();
    }

} // namespace gm

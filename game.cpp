#include "game.h"

namespace gm
{
    bool running;
    bool locking;
    Matrix playfield;
    Piece one_piece;
    Matrix frame;
    std::chrono::microseconds duration;

    void init()
    {
        srand(std::time(0));
        running = true;
        locking = false;
        playfield = Matrix(22, std::vector<int>(10, 0));
        one_piece = pick();
        frame = playfield;
        duration = 500ms;
    }

    Piece pick()
    {
        static std::vector<Tetromino> bag = {I, J, L, O, S, T, Z};
        Piece p(bag[rand() % 7], 4, 20, 0);
        return std::move(p);
    }

    void render()
    {
        auto backup = frame;
        frame = playfield;
        auto [x, y] = one_piece.get_position();
        try
        {
            for (auto i : iota(0, 4))
            {
                auto [dx, dy] = one_piece.get_mino(i);
                frame.at(y + dy).at(x + dx) = one_piece.get_color();
            }

            // display shadow piece
            while (one_piece.test(x, --y))
                ;
            y++;
            for (auto i : iota(0, 4))
            {
                auto [dx, dy] = one_piece.get_mino(i);

                if (frame.at(y + dy).at(x + dx) == 0)
                    frame.at(y + dy).at(x + dx) = 0 - one_piece.get_color();
            }
        }
        catch (const std::out_of_range &e)
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
            if (one_piece.down())
            {
                return;
            }

            if (locking)
            {
                lock();
                clear();

                // must pick after clear update playfield
                one_piece = pick();
                locking = false;
            }
            else {
                locking = true;
            }
        }
    }

    void lock()
    {
        auto [x, y] = one_piece.get_position();
        try
        {
            for (auto i : iota(0, 4))
            {
                auto [dx, dy] = one_piece.get_mino(i);
                playfield.at(y + dy).at(x + dx) = one_piece.get_color();
            }
        }
        catch (const std::out_of_range &e)
        {
            std::cerr << "Error: Array index out of range - " << e.what() << std::endl;
        }
    }

    void clear()
    {
        for (auto it = playfield.begin(); it != playfield.end(); ++it)
        {
            bool full;
            for (auto cell : *it)
            {
                if (cell == 0)
                {
                    full = false;
                    break;
                }
            }
            if (full)
            {
                it = playfield.erase(it);
                playfield.push_back(std::vector<int>(it->size(), 0));
                --it;
            }
        }
    }

    void quit()
    {
        running = false;
    }
    bool rotate()
    {
        return one_piece.rotate();
    }
    bool left()
    {
        return one_piece.left();
    }
    bool right()
    {
        return one_piece.right();
    }
    bool down()
    {
        return one_piece.down();
    }

    void drop()
    {
        while (one_piece.down())
            ;
        locking = true;
    }

} // namespace gm

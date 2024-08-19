#include "piece.h"
#include "game.h"

namespace gm
{
    bool Piece::test(int ox, int oy) const
    {
        assert(sp_playfield != nullptr);
        for (int i = 0; i < 4; ++i)
        {
            auto [dx, dy] = get_mino(i);

            if (ox + dx < 0 || ox + dx > (*sp_playfield)[0].size() - 1 || oy + dy < 0 || oy + dy > (*sp_playfield).size() - 1)
                return false;

            if ((*sp_playfield)[oy + dy][ox + dx] > 0)
                return false;
        }
        return true;
    }

    std::pair<int, int> Piece::get_mino(int i) const
    {
        assert(i >= 0 && i <= 3);
        if (i == 0)
            return {0, 0};
        return tetro_set[index][i];
    }

    std::pair<int, int> Piece::get_position() const
    {
        return {x, y};
    }

    int Piece::get_color() const
    {
        return status ? tetro_set[index][0].second : 0 - tetro_set[index][0].second;
    }

    bool Piece::left()
    {
        return move(-1, 0);
    }

    bool Piece::right()
    {
        return move(1, 0);
    }

    bool Piece::rotate()
    {
        int new_index = (index + 1) % 4;
        Piece new_piece(tetro_set, x, y, new_index);
        if (new_piece.test(x, y))
        {
            index = new_index;
            return true;
        }
        return false;
    }

    bool Piece::move(int dx, int dy)
    {
        if (test(x + dx, y + dy))
        {
            x += dx;
            y += dy;
            return true;
        }
        return false;
    }

    Piece::Piece(Tetromino &t, int x0, int y0, int i, int status) : tetro_set(t), x(x0), y(y0), index(i), sp_playfield(std::make_shared<Matrix>(playfield)), status(status)
    {
    }
    bool Piece::down()
    {
        return move(0, -1);
    }
    void Piece::set_playfield(std::shared_ptr<Matrix> p)
    {
        sp_playfield = p;
    }
    void Piece::set_shadow_status()
    {
        this->status = 0;
    }
} // namespace gm

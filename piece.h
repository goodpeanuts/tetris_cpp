#pragma once
#include "tetromino.h"

namespace gm
{
    class Piece
    {
    private:
        Tetromino tetro_set;
        int index; // 0 R 2 L
        int x, y;
        std::shared_ptr<Matrix> sp_playfield;

        bool move(int dx, int dy);

    public:
        int status;
        Piece() = default;
        Piece(Tetromino &t, int x0, int y0, int i, int status = 1);

        std::pair<int, int> get_mino(int i) const;
        std::pair<int, int> get_position() const;
        int get_color() const;
        bool left();
        bool right();
        bool rotate();
        bool down();
        void set_playfield(std::shared_ptr<Matrix> p); // deprecated
        void set_shadow_status();
        bool test(int ox, int oy) const;

        // ~Piece();
    };
} // namespace gm

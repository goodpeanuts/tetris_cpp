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

        void move(int dx, int dy);
    public:
        Piece() = default;
        Piece(Tetromino& t, int x0, int y0, int i);

        std::pair<int, int> get_mino(int i);
        std::pair<int, int> get_position();
        int get_color();
        void left();
        void right();
        void rotate();
        void down();
        void set_playfield(std::shared_ptr<Matrix> p);
        bool test(int ox, int oy);

        // ~Piece();
    };
} // namespace gm

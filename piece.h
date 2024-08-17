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
    public:
        Piece(Tetromino& t, int x0, int y0, int i);
        ~Piece();
    };
} // namespace gm

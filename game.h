#pragma once
#include "tetromino.h"
// #include "piece.h"

namespace gm
{
    extern bool running;
    // extern Piece one_piece;
    extern int row, col;
    extern Tetromino cur;
    extern int cur_index;
    
    void init();
    void quit();
    void rotate();
    void left();
    void right();
    void down();
} // namespace gm
#pragma once
#include "tetromino.h"
#include "piece.h"
#include "utils.h"

namespace gm
{
    extern bool running;
    extern Piece one_piece;
    extern Matrix playfield;
    extern Matrix frame;
    extern std::chrono::microseconds duration;
    // extern int row, col;
    // extern Tetromino cur;
    // extern int cur_index;
    
    void init();
    Piece pick();
    void render();
    void update();
    void quit();
    void rotate();
    void left();
    void right();
    void down();
} // namespace gm
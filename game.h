#pragma once
#include "tetromino.h"
#include "piece.h"
#include "utils.h"

namespace gm
{
    extern bool running;
    extern bool locking;
    extern Piece one_piece;
    extern Matrix playfield;
    extern Matrix frame;
    extern std::queue<Tetromino> incoming;
    extern std::chrono::microseconds duration;
    // extern int row, col;
    // extern Tetromino cur;
    // extern int cur_index;
    
    void init();
    Piece pick();
    void render();
    void update();
    void lock();
    void clear();
    void quit();
    bool rotate(int i);
    bool left();
    bool right();
    bool down();
    void drop();

    void preview();
    void load_field();

    void fill(Matrix& m, const Piece& p);
} // namespace gm
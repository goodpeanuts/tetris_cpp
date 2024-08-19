#pragma once
#include "tetromino.h"
#include "piece.h"
#include "utils.h"

namespace gm
{
    extern bool running;
    extern bool ending;
    extern bool reseting;
    extern bool locking;
    extern bool holding;
    extern bool helping;
    extern Piece one_piece;
    extern Matrix playfield;
    extern Matrix frame;
    extern std::queue<Tetromino> incoming;
    extern std::chrono::microseconds duration;
    extern Tetromino hold_piece;
    extern int score, level, lines;
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
    void hold();
    void reset();
    void help();

    void preview();
    void load_field();

    void level_upgrade();

    void fill(Matrix& m, const Piece& p);
} // namespace gm
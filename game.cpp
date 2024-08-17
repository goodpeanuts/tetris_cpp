#include "game.h"

namespace gm
{
    bool running;
    int row, col;
    int cur_index;
    Tetromino cur;

    void init()
    {
        running = true;
        row = 2;
        col = 15;
        cur_index = 1;
        cur = Z;
    }

    void quit()
    {
        running = false;
    }
    void rotate()
    {
        // cur = rotate(cur);
        cur_index = (cur_index + 1) % 4;
    }
    void left()
    {
        col --;
    }
    void right()
    {
        col ++;
    }

    void down()
    {
        row ++;
    }

} // namespace gm

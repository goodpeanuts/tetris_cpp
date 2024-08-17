#pragma once
#include "define.h"
#include "tetromino.h"
/**
 *  ui: layout
 *  dw: drat  | gm: game logic | ut: utils
 *  tc: terminal control
 * 
 */

namespace dw
{
    void windows(int top, int left, int width, int heigh, std::string title);
    
    /// display tetromino 1
    // void tetromino(gm::Tetromino& t, int top, int left);

    void tetromino(gm::Tetromino& t, int top, int left, int index);
} // namespace dw

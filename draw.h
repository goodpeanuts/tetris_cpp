#pragma once
#include "define.h"
#include "tetromino.h"
#include "terminal.h"
#include "utils.h"

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

    void tetromino(Tetromino& t, int top, int left, int index);
    void frame(Matrix& frame, int top, int left);
    void preview(std::queue<Tetromino> incoming, int top, int left);
    void hold(Tetromino &h, int top, int left);

    void draw_in_matrix(Matrix& m, int top, int left, Matrix* buffer = nullptr, std::string blank = "  ");
} // namespace dw

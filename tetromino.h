#pragma once
#include "define.h"
#include "color.h"

namespace gm
{
    extern std::map<int, Color> tetro_color;
    /// Tetromino 1
    // using Tetromino = std::vector<std::vector<int>>;
    // extern Tetromino I, J, L, O, S, T, Z;
    // Tetromino rotate(Tetromino &t);
    
    extern Tetromino I, J, L, O, S, T, Z;
    extern Offset offset, offset_i, offset_o;
} // namespace gm

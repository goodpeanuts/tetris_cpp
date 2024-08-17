#pragma once
#include "define.h"
#include "color.h"

namespace gm
{
    extern std::map<int, Color> tetro_color;
    /// Tetromino 1
    // using Tetromino = std::vector<std::vector<int>>;
    // extern Tetromino I, J, L, O, S, T, Z;

    using Tetromino = std::array<std::array<std::pair<int, int>, 4>, 4>;
    extern Tetromino I, J, L, O, S, T, Z;
    Tetromino rotate(Tetromino &t);
} // namespace gm

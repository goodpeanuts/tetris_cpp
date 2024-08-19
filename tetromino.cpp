#include "tetromino.h"

namespace gm
{
    // I J L O S T Z
    // 1 2 3 4 5 6 7
    /// ----------- Tetrmino 1 -------------------
    // std::map<int, Color> tetro_color {
    //     {1, Color::Cyan},
    //     {2, Color::Blue},
    //     {3, Color::Orange},
    //     {4, Color::Yellow},
    //     {5, Color::Green},
    //     {6, Color::Purple},
    //     {7, Color::Red},
    // };

    // Tetromino I{{
    //     {0, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 0},
    //     {0, 1, 1, 1, 1},
    //     {0, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 0},
    // }};

    // Tetromino J{{
    //     {2, 0, 0},
    //     {2, 2, 2},
    //     {0, 0, 0},
    // }};

    // Tetromino L{{
    //     {0, 0, 3},
    //     {3, 3, 3},
    //     {0, 0, 0},
    // }};

    // Tetromino O{{
    //     {0, 4, 4},
    //     {0, 4, 4},
    //     {0, 0, 0},
    // }};

    // Tetromino S{{
    //     {0, 5, 5},
    //     {5, 5, 0},
    //     {0, 0, 0},
    // }};

    // Tetromino T{{
    //     {0, 6, 0},
    //     {6, 6, 6},
    //     {0, 0, 0},
    // }};

    // Tetromino Z{{
    //     {7, 7, 0},
    //     {0, 7, 7},
    //     {0, 0, 0},
    // }};

    // Tetromino rotate(Tetromino &t)
    // {
    //     Tetromino result(t.size(), std::vector<int>(t.size(), 0));

    //     // t[i][j] = t'[j][size - 1 - i];
    //     for (int i = 0; i < t.size(); ++i)
    //     {
    //         for (int j = 0; j < t[0].size(); ++j)
    //         {
    //             if (t[i][j])
    //                 result[j][t.size() - i - 1] = t[i][j];
    //         }
    //     }

    //     return std::move(result);
    // }

    // --------------------

    Tetromino I{{
        {{{'I', (int)Color::Cyan}, {-1, 0}, {1, 0}, {2, 0}}},  // O
        {{{'I', (int)Color::Cyan}, {0, 1}, {0, -1}, {0, -2}}}, // R
        {{{'I', (int)Color::Cyan}, {-2, 0}, {-1, 0}, {1, 0}}}, // 2
        {{{'I', (int)Color::Cyan}, {0, 2}, {0, 1}, {0, -1}}},  // L
    }};

    Tetromino J{{
        {{{'J', (int)Color::Blue}, {-1, 1}, {-1, 0}, {1, 0}}},  // O
        {{{'J', (int)Color::Blue}, {1, 1}, {0, 1}, {0, -1}}},   // R
        {{{'J', (int)Color::Blue}, {-1, 0}, {1, 0}, {1, -1}}},  // 2
        {{{'J', (int)Color::Blue}, {0, 1}, {-1, -1}, {0, -1}}}, // L
    }};

    Tetromino L{{
        {{{'L', (int)Color::Orange}, {-1, 0}, {1, 0}, {1, 1}}},   // O
        {{{'L', (int)Color::Orange}, {0, 1}, {0, -1}, {1, -1}}},  // R
        {{{'L', (int)Color::Orange}, {-1, -1}, {-1, 0}, {1, 0}}}, // 2
        {{{'L', (int)Color::Orange}, {-1, 1}, {0, 1}, {0, -1}}},  // L
    }};

    Tetromino O{{
        {{{'O', (int)Color::Yellow}, {0, 1}, {1, 1}, {1, 0}}},     // O
        {{{'O', (int)Color::Yellow}, {0, -1}, {1, 0}, {1, -1}}},   // R
        {{{'O', (int)Color::Yellow}, {-1, -1}, {-1, 0}, {0, -1}}}, // 2
        {{{'O', (int)Color::Yellow}, {-1, 1}, {-1, 0}, {0, 1}}},   // L
    }};

    Tetromino S{{
        {{{'S', (int)Color::Green}, {-1, 0}, {0, 1}, {1, 1}}},   // O
        {{{'S', (int)Color::Green}, {0, 1}, {1, 0}, {1, -1}}},   // R
        {{{'S', (int)Color::Green}, {-1, -1}, {0, -1}, {1, 0}}}, // 2
        {{{'S', (int)Color::Green}, {-1, 1}, {-1, 0}, {0, -1}}}, // L
    }};

    Tetromino T{{
        {{{'T', (int)Color::Purple}, {-1, 0}, {0, 1}, {1, 0}}},  // O
        {{{'T', (int)Color::Purple}, {0, 1}, {1, 0}, {0, -1}}},  // R
        {{{'T', (int)Color::Purple}, {-1, 0}, {1, 0}, {0, -1}}}, // 2
        {{{'T', (int)Color::Purple}, {-1, 0}, {0, 1}, {0, -1}}}, // L
    }};

    Tetromino Z{{
        {{{'Z', (int)Color::Red}, {-1, 1}, {0, 1}, {1, 0}}},   // O
        {{{'Z', (int)Color::Red}, {1, 1}, {1, 0}, {0, -1}}},   // R
        {{{'Z', (int)Color::Red}, {-1, 0}, {0, -1}, {1, -1}}}, // 2
        {{{'Z', (int)Color::Red}, {-1, -1}, {-1, 0}, {0, 1}}}, // L
    }};
    // Tetromino

    Offset offset{{
        {{{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}}},       // O
        {{{0, 0}, {+1, 0}, {+1, -1}, {0, +2}, {+1, +2}}}, // R
        {{{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}}},       // 2
        {{{0, 0}, {-1, 0}, {-1, -1}, {0, +2}, {-1, +2}}}, // L
    }};

    Offset offset_i{{
        {{{0, 0}, {-1, 0}, {+2, 0}, {-1, 0}, {+2, 0}}},    // O
        {{{-1, 0}, {0, 0}, {0, 0}, {0, +1}, {0, -2}}},     // R
        {{{-1, +1}, {+1, +1}, {-2, +1}, {+1, 0}, {-2, 0}}},// 2
        {{{0, +1}, {0, +1}, {0, +1}, {0, -1}, {0, +2}}},   // L
    }};

    Offset offset_o{{
        {{{0, 0}}},   // O
        {{{0, -1}}},  // R
        {{{-1, -1}}}, // 2
        {{{-1, 0}}},  // L
    }};
} // namespace gm

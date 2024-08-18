#pragma once
#include "define.h"
#include <string>

namespace ut
{
    int fps();
    std::string utf32_to_utf8(std::u32string str);
    int b2c(int);
    bool timer(std::chrono::microseconds sec);
} // namespace ut

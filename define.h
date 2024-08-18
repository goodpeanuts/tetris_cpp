#pragma once
#include <iostream>
#include <chrono>
#include <string>
#include <thread>
#include <map>
#include <functional>
#include <locale>
#include <codecvt>
#include <vector>
#include <memory>
#include <cassert>
#include <ranges>
#include <sstream>
#include <ostream>

#include <termios.h>

using namespace std::chrono_literals;

#define KEY_Q 'q'
#define KEY_W 'w'
#define KEY_A 'a'
#define KEY_S 's'
#define KEY_D 'd'

using Matrix = std::vector<std::vector<int>>;
using Tetromino = std::array<std::array<std::pair<int, int>, 4>, 4>;
using std::ranges::views::iota;
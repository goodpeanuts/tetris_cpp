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
#include <queue>
#include <fstream>

#include <termios.h>

using namespace std::chrono_literals;

#define KEY_Q 'q'
#define KEY_W 'w'
#define KEY_A 'a'
#define KEY_S 's'
#define KEY_D 'd'
#define KEY_Z 'z'
#define KEY_X 'x'
#define KEY_C 'c'
#define KEY_SPACE ' '

using Matrix = std::vector<std::vector<int>>;
using Tetromino = std::vector<std::vector<std::pair<int, int>>>;
using Offset = std::vector<std::vector<std::pair<int, int>>>;
using std::ranges::views::iota;
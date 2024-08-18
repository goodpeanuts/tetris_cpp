#pragma once
#include "define.h"

namespace tc
{
    void move_to(int row, int col, std::ostream &os = std::cout);
    void set_front_color(int id, std::ostream &os = std::cout);
    void set_back_color(int id, std::ostream &os = std::cout);
    void clean_screen(std::ostream &os = std::cout);
    void reset_color(std::ostream &os = std::cout);
    void hide_cursor(std::ostream &os = std::cout);
    void show_cursor(std::ostream &os = std::cout);
}
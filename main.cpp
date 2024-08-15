#include <iostream>
#include <thread>
#include <chrono>
#include "terminal.h"

using namespace std::chrono_literals;

int main() {

    // tc::move_to(5, 10);
    // tc::set_front_color(84);
    // std::cout << "hello world";
    // tc::move_to(10, 1);

    tc::hide_cursor();
    int i = 1;
    while (true) {
        tc::clean_screen();
        tc::move_to(i ++, 10);
        tc::set_back_color(15);
        std::cout<< " ";
        tc::reset_color();
        std::cout << std::flush;
        std::this_thread::sleep_for(1s);
    }
    return 0;
}
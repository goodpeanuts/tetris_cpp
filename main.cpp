#include <iostream>
#include <thread>
#include <chrono>
#include "terminal.h"
#include "utils.h"
#include "draw.h"
using namespace std::chrono_literals;

void init() 
{
    tc::clean_screen();
    tc::hide_cursor();
    dw::windows(1, 1, 9, 6, "Hold");
    dw::windows(1, 10, 12, 22, "Tetris");
    dw::windows(7, 1, 9, 16, "Status");
    dw::windows(1, 1, 9, 6, "Info");
    dw::windows(1, 22, 8, 18, "Next");
}

void loop() 
{
    int i = 1;
    while (true) {
        tc::move_to(10, 4);
        std::cout << "FPS:" << ut::fps();

        tc::move_to(5, 10);
        tc::set_back_color(15);
        std::cout<< " ";
        tc::reset_color();
        std::cout << std::flush;
        std::this_thread::sleep_for(100ms);
    }
}

void exit() 
{
    tc::show_cursor();
    tc::reset_color();
}
 
int main() 
{
    init();
    loop();
    exit();
    return 0;
}
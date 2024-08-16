#include "define.h"
#include "terminal.h"
#include "utils.h"
#include "draw.h"
#include "control.h"
#include "game.h"

void init() 
{
    tc::hide_cursor();
    gm::init();
    gm::start_listener();
}

void loop() 
{
    int i = 1;
    while (gm::running) {
        tc::clean_screen();
        dw::windows(1, 1, 9, 6, "Hold");
        dw::windows(1, 10, 12, 22, "Tetris");
        dw::windows(7, 1, 9, 16, "Status");
        dw::windows(1, 1, 9, 6, "Info");
        dw::windows(1, 22, 8, 18, "Next");

        tc::move_to(10, 4);
        std::cout << "FPS:" << ut::fps();

        tc::move_to(gm::row, ut::b2c(gm::col));
        tc::set_back_color(15);
        std::cout<< "  ";
        tc::reset_color();

        std::cout << std::flush;
        std::this_thread::sleep_for(100ms);
    }
}

void exit() 
{
    tc::show_cursor();
    tc::reset_color();
    tc::clean_screen();
    tc::move_to(1, 1);
    tc::set_front_color(9);
    std::cout << "Bye!\n";
}
 
int main() 
{
    init();
    loop();
    exit();
    return 0;
}
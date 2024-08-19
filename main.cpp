#include "define.h"
#include "terminal.h"
#include "utils.h"
#include "draw.h"
#include "control.h"
#include "game.h"
#include <stdexcept>

void init()
{
    tc::hide_cursor();
    gm::init();
    gm::start_listener();

    tc::clean_screen();
    dw::windows(1, 1, 9, 6, "Hold");
    dw::windows(1, 10, 12, 22, "Tetris");
    dw::windows(7, 1, 9, 16, "Status");
    dw::windows(19, 22, 8, 4, "Info");
    dw::windows(1, 22, 8, 18, "Next");
    // setbuf(stdout, nullptr);
}

void loop()
{
    int i = 1;
    while (gm::running)
    {
        gm::update();

        tc::move_to(10, 4);
        std::cout << "FPS:" << ut::fps();
        tc::move_to(12, 4);
        std::cout << "Level:" << gm::level;
        tc::move_to(13, 4);
        std::cout << "Score:" << gm::score;
        tc::move_to(14, 4);
        std::cout << "Lines:" << gm::lines;

        if (gm::ending)
        {
            dw::windows(9, 12, 8, 3, "");
            tc::move_to(10, ut::b2c(13));
            tc::set_back_color((int)Color::Red);
            std::cout << " Game Over!";
        }

        dw::frame(gm::frame, 2, 11);
        dw::preview(gm::incoming, 2, 23);
        dw::hold(gm::hold_piece, 2, 2);

        tc::reset_color();

        std::cout << std::flush;
        // std::this_thread::sleep_for(10ms);
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
    freopen("../error.log", "a", stderr);
    init();
    loop();
    exit();
    return 0;
}
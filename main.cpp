#include "define.h"
#include "terminal.h"
#include "utils.h"
#include "draw.h"
#include "control.h"
#include "game.h"
#include "window.h"
#include <stdexcept>

void init()
{
    tc::hide_cursor();
    gm::init();
    gm::start_listener();
    tc::clean_screen();
    ui::show_windows();
    ui::show_help_info();
    // setbuf(stdout, nullptr);
}

void loop()
{
    int i = 1;
    while (gm::running)
    {
        gm::update();
        ui::show_info();
        ui::show_game();
        std::this_thread::sleep_for(10ms);
    }
}

void exit()
{
    tc::show_cursor();
    ui::exit_message();
    tc::reset_color();
}

int main()
{
    freopen("../error.log", "a", stderr);
    init();
    loop();
    exit();
    return 0;
}
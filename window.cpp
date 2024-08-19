#include "window.h"
#include "game.h"

namespace ui
{
    void show_windows()
    {
        dw::windows(1, 1, 9, 6, "Hold");
        dw::windows(1, 10, 12, 22, "Tetris");
        dw::windows(7, 1, 9, 16, "Status");
        dw::windows(19, 22, 8, 4, "Info");
        dw::windows(1, 22, 8, 18, "Next");
    }

    void show_info()
    {
        tc::reset_color();
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

        if (gm::helping)
        {
            tc::move_to(9, ut::b2c(12));
            std::cout << "Help Info:    ";
            tc::move_to(10, ut::b2c(12));
            std::cout << "Rotate [w]    ";
            tc::move_to(11, ut::b2c(12));
            std::cout << "Left   [a]    ";
            tc::move_to(12, ut::b2c(12));
            std::cout << "Right  [d]    ";
            tc::move_to(13, ut::b2c(12));
            std::cout << "Down   [s]    ";
            tc::move_to(14, ut::b2c(12));
            std::cout << "Drop   [space]";
            tc::move_to(15, ut::b2c(12));
            std::cout << "Hold   [c]    ";
            tc::move_to(15, ut::b2c(12));
            std::cout << "Rest   [r]    ";
        }
    }

    void show_game()
    {
        dw::frame(gm::frame, 2, 11);
        dw::preview(gm::incoming, 2, 23);
        dw::hold(gm::hold_piece, 2, 2);
        tc::reset_color();
        std::cout << std::flush;
    }

    void exit_message()
    {
        tc::clean_screen();
        tc::move_to(1, 1);
        tc::set_front_color(9);
        std::cout << "Bye!\n";
    }

    void show_help_info()
    {
        tc::reset_color();
        tc::move_to(21, ut::b2c(24));
        std::cout << "Help [h] ";
    }
} // namespace ui

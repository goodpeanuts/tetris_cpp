#include "control.h"
#include "define.h"
#include "game.h"

namespace gm
{
    char command;

    std::map<char, std::function<void()>> comm_func {
        {KEY_Q, command_quit},
        {KEY_W, command_rotate},
        {KEY_A, command_left},
        {KEY_S, command_down},
        {KEY_D, command_right}
    };

    char getch()
    {
        char c;
        struct termios old, cur;
        tcgetattr(0, &cur);
        old = cur;
        cfmakeraw(&cur);
        tcsetattr(0, 0, &cur);
        c = getchar();
        tcsetattr(0, 0, &old);
        return c;
    }

    void key_event()
    {
        while (running)
        {
            command = getch();
            if (comm_func.find(command) == comm_func.end())
            {
                command_default_op();
            } else {
                comm_func[command]();
            }
        }
    }
    void start_listener()
    {
        std::thread t(key_event);
        t.detach();
    }
    void command_quit()
    {
        quit();
    }
    void command_rotate()
    {
        rotate();
    }
    void command_left()
    {
        left();
    }
    void command_right()
    {
        right();
    }
    void command_down()
    {
        down();
    }
    void command_default_op()
    {
    }
} // namespace gm

#pragma once


namespace gm
{
    extern char command;

    char getch();
    void key_event();
    void start_listener();

    void command_quit();
    void command_rotate_R();
    void command_rotate_L();
    void command_rotate_2();
    void command_left();
    void command_right();
    void command_down();
    void command_drop();
    void command_hold();
    void command_reset();
    void command_help();
    void command_default_op();
} // namespace gm

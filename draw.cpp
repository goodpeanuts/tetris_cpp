#include "draw.h"

namespace dw
{
    const std::u32string style1 = U" ┌┐└┘│─";
    const std::u32string style2 = U" ┏┓┗┛┃━";
    const std::u32string style3 = U" ╔╗╚╝║═";
    const std::u32string style4 = U" ╭╮╰╯│─";
    const std::u32string cur_stytle = style1;

    void windows(int top, int left, int width, int height, std::string title)
    {
        if (width < 2 || height < 2)
            return;

        // top
        tc::move_to(top, ut::b2c(left));
        for (int col = 0; col < width; ++col)
        {
            if (col == 0)
                std::cout << ut::utf32_to_utf8({cur_stytle[0], cur_stytle[1]});
            else if (col == width - 1)
                std::cout << ut::utf32_to_utf8({cur_stytle[2]});
            else
                std::cout << ut::utf32_to_utf8({cur_stytle[6], cur_stytle[6]});
        }

        // bottom
        tc::move_to(top + height - 1, ut::b2c(left));
        for (int col = 0; col < width; ++col)
        {
            if (col == 0)
                std::cout << ut::utf32_to_utf8({cur_stytle[0], cur_stytle[3]});
            else if (col == width - 1)
                std::cout << ut::utf32_to_utf8({cur_stytle[4]});
            else
                std::cout << ut::utf32_to_utf8({cur_stytle[6], cur_stytle[6]});
        }

        // left
        for (int row = 1; row < height - 1; row++)
        {
            tc::move_to(top + row, ut::b2c(left));
            std::cout << ut::utf32_to_utf8({cur_stytle[0], cur_stytle[5]});
        }

        // right
        for (int row = 1; row < height - 1; row++)
        {
            tc::move_to(top + row, ut::b2c(left + width - 1));
            std::cout << ut::utf32_to_utf8({cur_stytle[5]});
        }

        // title
        if (title.length() > width)
            return;
        tc::move_to(top, ut::b2c(left) + (width * 2 - title.length()) / 2);
        std::cout << title;
        return;
    }

    /// show tetrimino 1
    // void tetromino(gm::Tetromino &t, int top, int left)
    // {
    //     tc::move_to(top, ut::b2c(left));
    //     for (int i = 0; i < t.size(); ++i)
    //     {
    //         tc::move_to(top + i, ut::b2c(left));

    //         for (int j = 0; j < t[0].size(); ++j)
    //         {
    //             if (t[i][j] > 0)
    //             {
    //                 tc::set_back_color((int)gm::tetro_color[t[i][j]]);
    //                 std::cout << "  ";
    //             }
    //             else
    //             {
    //                 tc::reset_color();
    //                 std::cout << "  ";
    //             }
    //         }
    //     }
    //     return;
    // }

    void tetromino(Tetromino &t, int top, int left, int index)
    {
        tc::move_to(top, ut::b2c(left));
        tc::set_back_color(t[index][0].second);
        std::cout << "  ";
        for (auto p : t[index])
        {
            if (p.first > 'A')
                continue;
            // row = row - dy
            // col = col + dx
            tc::move_to(top - p.second, ut::b2c(left + p.first));
            std::cout << "  ";
        }
    }
    void frame(Matrix &frame, int top, int left)
    {
        std::ostringstream oss;
        static Matrix buffer(frame.size(), std::vector<int>(frame[0].size(), -1));
        int row, col;
        for (int x = 0; x < 10; ++x)
        {
            for (int y = 0; y < 20; ++y)
            {
                if (buffer[y][x] == frame[y][x])
                    continue;
                buffer[y][x] = frame[y][x];

                row = top + 20 - y - 1;
                col = left + x;
                tc::move_to(row, ut::b2c(col), oss);
                if (frame[y][x] > 0)
                {
                    tc::reset_color(oss);
                    tc::set_back_color(frame[y][x], oss);
                    oss << "  ";
                }
                else if (frame[y][x] < 0)
                {
                    tc::reset_color(oss);
                    tc::set_front_color(0 - frame[y][x], oss);
                    oss << "\u25e3\u25e5";
                }
                else
                {
                    tc::reset_color(oss);
                    oss << "\u30FB";
                }
            }
        }
        std::cout << oss.str();
    }
}
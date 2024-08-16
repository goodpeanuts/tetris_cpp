#include "draw.h"
#include "terminal.h"
#include "utils.h"

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
            std::cout << ut::utf32_to_utf8({cur_stytle[0], cur_stytle[5]});;
        }

        // right
        for (int row = 1; row < height - 1; row++)
        {
            tc::move_to(top + row, ut::b2c(left + width - 1));
            std::cout << ut::utf32_to_utf8({cur_stytle[5]});;
        }

        // title
        if (title.length() > width)
            return;
        tc::move_to(top, ut::b2c(left) + (width * 2 - title.length()) / 2);
        std::cout << title;
        return;
    }

}
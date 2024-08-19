#include "game.h"

namespace gm
{
    bool running;
    bool ending;
    bool locking;
    bool holding;
    int score, level, lines;
    Matrix playfield;
    Piece one_piece;
    Matrix frame;
    Tetromino hold_piece;
    std::queue<Tetromino> incoming;
    std::chrono::microseconds duration;

    void init()
    {
        srand(std::time(0));
        running = true;
        ending = false;
        locking = false;
        holding = false;
        score = lines = 0;
        playfield = Matrix(22, std::vector<int>(10, 0));
        level_upgrade();
        preview();
        // load_field(); // FIXME: why must put this before pick()
        one_piece = pick();
        frame = playfield;
    }

    Piece pick()
    {
        assert(incoming.size() > 0);
        Piece p(incoming.front(), 4, 20, 0);
        incoming.pop();
        
        // game over
        if (!p.test(4, 20))
            ending = true;

        preview();
        return std::move(p);
    }

    void render()
    {
        frame = playfield;
        fill(frame, one_piece);

        Piece shadow = one_piece;
        shadow.set_shadow_status();

        while (shadow.down())
            ;
        fill(frame, shadow);
    }

    void update()
    {
        if (ending)
            return;
        render();
        if (ut::timer(duration))
        {
            if (one_piece.down())
            {
                return;
            }

            if (locking)
            {
                lock();
                clear();
                level_upgrade();

                // must pick after clear update playfield
                one_piece = pick();
                locking = false;
                holding = false;
            }
            else
            {
                locking = true;
            }
        }
    }

    void lock()
    {
        fill(playfield, one_piece);
    }

    void clear()
    {
        int count = 0;
        for (auto it = playfield.begin(); it != playfield.end(); ++it)
        {
            bool full = true;
            for (auto cell : *it)
            {
                if (cell == 0)
                {
                    full = false;
                    break;
                }
            }
            if (full)
            {
                it = playfield.erase(it);
                playfield.push_back(std::vector<int>(it->size(), 0));
                --it;
                count++;
            }
        }
        switch (count)
        {
        case 1:
            score += 100 * level;
            break;
        case 2:
            score += 300 * level;
            break;
        case 3:
            score += 500 * level;
            break;
        case 4:
            score += 800 * level;
            break;
        default:
            break;
        }
        lines += count;
    }

    void quit()
    {
        running = false;
    }
    bool rotate(int i)
    {
        return one_piece.rotate(i);
    }
    bool left()
    {
        return one_piece.left();
    }
    bool right()
    {
        return one_piece.right();
    }
    bool down()
    {
        if (one_piece.down())
            score += 1;
        return one_piece.down();
    }

    void drop()
    {
        while (one_piece.down())
            score += 2;
        locking = true;
    }

    void hold()
    {
        if (holding)
            return;
        if (hold_piece.empty())
        {
            hold_piece = one_piece.get_tetromino();
            one_piece = pick();
        }
        else
        {
            auto tmp = hold_piece;
            hold_piece = one_piece.get_tetromino();
            one_piece = Piece(tmp, 4, 20, 0);
        }
        holding = true;
    }

    void preview()
    {
        static std::vector<Tetromino> bag = {I, J, L, O, S, T, Z};
        int index;
        while (incoming.size() < 5)
        {
            index = rand() % bag.size();
            incoming.push(bag[index]);
            bag.erase(bag.begin() + index);
            if (bag.size() == 0)
                bag = {I, J, L, O, S, T, Z};
        }
    }

    void load_field()
    {
        std::ifstream fs("tetris.map");
        assert(fs.is_open());
        std::string line;
        for (auto &row : playfield | std::ranges::views::take(20) | std::ranges::views::reverse)
        {
            getline(fs, line);
            for (auto i : iota(0, 10))
            {
                if (line[i] == '1')
                    row[i] = (int)Color::Grey;
            }
        }
        fs.close();
    }
    void level_upgrade()
    {
        level = lines / 10 + 1;
        duration = (std::chrono::milliseconds)(int)std::pow((0.8 - ((level - 1) * 0.007)), level - 1) * 1000;
    }
    void fill(Matrix &m, const Piece &p)
    {
        auto [x, y] = p.get_position();
        try
        {
            for (auto i : iota(0, 4))
            {
                auto [dx, dy] = p.get_mino(i);
                if (m.at(y + dy).at(x + dx) == 0)
                    m.at(y + dy).at(x + dx) = p.get_color();
            }
        }
        catch (const std::out_of_range &e)
        {
            std::cerr << "[Error]: [game.cpp fill] Array index out of range - " << e.what() << std::endl;
        }
    }
} // namespace gm

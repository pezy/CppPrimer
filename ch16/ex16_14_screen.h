#ifndef CP5_EX16_14_SCREEN_H_
#define CP5_EX16_14_SCREEN_H_

#include <algorithm>
#include <iostream>
#include <string>

using pos = std::string::size_type;
template <pos, pos> class Screen;

template <pos H, pos W> std::istream& operator>>(std::istream&, Screen<H, W>&);

template <pos H, pos W>
std::ostream& operator<<(std::ostream&, const Screen<H, W>&);

template <pos H, pos W> class Screen {
    friend std::istream& operator>><H, W>(std::istream&, Screen<H, W>&);
    friend std::ostream& operator<<<H, W>(std::ostream&, const Screen<H, W>&);

public:
    Screen() = default;
    Screen(char c) : contents(H * W, c) {}

    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const { return contents[r * W + c]; }
    inline Screen& move(pos r, pos c);
    inline Screen& set(char ch);
    inline Screen& set(pos r, pos c, char ch);

private:
    pos cursor = 0;
    std::string contents;
};

template <pos H, pos W>
std::istream& operator>>(std::istream& is, Screen<H, W>& s)
{
    std::string input;
    is >> input;
    for (char ch : input) s.set(ch);
    return is;
}

template <pos H, pos W>
std::ostream& operator<<(std::ostream& os, const Screen<H, W>& s)
{
    for (pos r = 0; r != H; ++r) {
        for (pos c = 0; c != W; ++c) {
            os << s.get(r, c);
        }
        os << std::endl;
    }
    return os;
}

template <pos H, pos W> inline Screen<H, W>& Screen<H, W>::move(pos r, pos c)
{
    cursor = r * W + c;
    return *this;
}

template <pos H, pos W> inline Screen<H, W>& Screen<H, W>::set(char ch)
{
    contents[cursor++] = ch;
    cursor = std::min(cursor, H * W);
    return *this;
}

template <pos H, pos W>
inline Screen<H, W>& Screen<H, W>::set(pos r, pos c, char ch)
{
    contents[r * W + c] = ch;
    return *this;
}

#endif // CP5_EX16_14_SCREEN_H_

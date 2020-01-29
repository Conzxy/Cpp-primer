//
//ex7_24.h
//
//created by tsubaki-san on 20/1/29
//

#ifndef EX7_24_H
#define EX7_24_H

#include <string>

class Screen {
public:
    using pos = std::string::size_type;

    Screen() = default; // 1
    Screen(pos ht, pos wd) :height(ht), width(wd), contents(ht* wd, ' ') { } // 2
    Screen(pos ht, pos wd, char c) :height(ht), width(wd), contents(ht* wd, c) { } // 3

    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const { return contents[r * width + c]; }

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

#endif
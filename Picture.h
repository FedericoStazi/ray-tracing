//
// Created by federico on 30/04/2020.
//

#ifndef CPP_GRAPHICS_PICTURE_H
#define CPP_GRAPHICS_PICTURE_H


#include <vector>
#include "Aspect/RGB.h"

class Picture {

private:
    int height, width;
    std::vector<std::vector<RGB>> pixels;

public:

    Picture(int height, int width);

    [[nodiscard]] int get_height() const {return height;}
    [[nodiscard]] int get_width() const {return width;}

    void set_pixel(int h, int w, RGB c);
    RGB get_pixel(int h, int w) const;

};


#endif //CPP_GRAPHICS_PICTURE_H

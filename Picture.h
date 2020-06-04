//
// Created by federico on 30/04/2020.
//

#ifndef CPP_GRAPHICS_PICTURE_H
#define CPP_GRAPHICS_PICTURE_H


#include <vector>
#include "Aspect/RGB.h"

///Class used to store an image
class Picture {

public:

    struct PixelOutOfBounds: public std::exception {
        [[nodiscard]] const char * what () const noexcept override {
            return "The pixel is out of the image boundaries";
        }
    };

    [[nodiscard]] int get_height() const {
        return height;
    }

    [[nodiscard]] int get_width() const {
        return width;
    }

    void set_pixel(int h, int w, RGB c) {
        if (h >= 0 && w >= 0 && h < height && w < width)
            pixels[h][w] = c;
        else
            throw PixelOutOfBounds();
    }

    [[nodiscard]] RGB get_pixel(int h, int w) const {
        return (h >= 0 && w >= 0 && h < height && w < width) ? pixels[h][w] : RGB(0, 0, 0);
    }

    Picture(int height, int width)
        : height(height),
          width(width),
          pixels(std::vector<std::vector<RGB>>(height, std::vector<RGB>(width, RGB(0, 0, 0)))) {}

private:

    int height, width;
    std::vector<std::vector<RGB>> pixels;

};


#endif //CPP_GRAPHICS_PICTURE_H

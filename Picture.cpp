//
// Created by federico on 30/04/2020.
//

#include "Picture.h"

Picture::Picture(int height, int width) : height(height), width(width),
                                    pixels(std::vector<std::vector<RGB>>(height, std::vector<RGB>(width, RGB(0, 0, 0)))) {}

void Picture::set_pixel(int h, int w, RGB c) {
  if (h >= 0 && w >= 0 && h < height && w < width)
    pixels[h][w] = c;
}

RGB Picture::get_pixel(int h, int w) const {
  return (h >= 0 && w >= 0 && h < height && w < width) ? pixels[h][w] : RGB(0, 0, 0);
}

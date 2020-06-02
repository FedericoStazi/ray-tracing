//
// Created by federico on 02/06/2020.
//

#ifndef CPP_GRAPHICS_HEATMAP_H
#define CPP_GRAPHICS_HEATMAP_H


#include "Picture.h"

class HeatMap {

private:
    int height, width;
    std::vector<std::vector<RGB>> pixels;

public:
    HeatMap(int height, int width);

    void add(int i, int j, int val);
    void set(int i, int j, int val);

    Picture linear_heat_map();
    Picture log_heat_map();

};


#endif //CPP_GRAPHICS_HEATMAP_H

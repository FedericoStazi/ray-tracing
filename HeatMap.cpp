//
// Created by federico on 02/06/2020.
//

#include "HeatMap.h"

HeatMap::HeatMap(int height, int width) : height(height), width(width),
                                          pixels(std::vector<std::vector<RGB>>(height, std::vector<RGB>(width, RGB(0, 0, 0)))) {}

Picture HeatMap::linear_heat_map() {
    return Picture(0, 0);
}

Picture HeatMap::log_heat_map() {
    return Picture(0, 0);
}

void HeatMap::add(int i, int j, int val) {

}

void HeatMap::set(int i, int j, int val) {

}

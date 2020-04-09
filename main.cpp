//
// Created by federico on 09/04/2020.
//

#include <functional>
#include <iostream>
#include <cmath>
#include "Geometry/Vector3.h"

int main() {


    Vector3 v(
            TimeFunction([](double t) {return cos(t);}),
            TimeFunction([](double t) {return sin(t);}),
            TimeFunction([](double t) {return t;})
            );

    v.time(0);

}

//
// Created by federico on 09/04/2020.
//

#include <iostream>
#include <cmath>
#include "Utils/TimeGeometry/TimeVector3.h"
#include "Utils/TimeGeometry/TimeUnitVector3.h"
#include "Utils/TimeGeometry/TimeVector2.h"
#include "Utils/Geometry/Line.h"

int main() {

    TimeVector2 v2(
            TimeFunction([](double t) {return cos(t);}),
            TimeFunction([](double t) {return sin(t);})
    );

    Vector2 a = Vector2(v2.time(0).rotate(0, 0, M_PI).scale(2));

    Line l;

    std::cout<<l.distance(a, 0);

}

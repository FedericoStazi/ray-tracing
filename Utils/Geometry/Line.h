//
// Created by federico on 10/04/2020.
//

#ifndef CPP_GRAPHICS_LINE_H
#define CPP_GRAPHICS_LINE_H


#include "Vector3.h"
#include "UnitVector3.h"
#include "../TimeGeometry/TimeUnitVector3.h"

class Line {

private:

    TimeVector3 position;
    TimeUnitVector3 direction;

public:

    Line(TimeVector3 position, TimeUnitVector3 direction);
    Line(const Vector3& position, const UnitVector3& direction);
    Line();

    [[nodiscard]] Vector3 get_position(double time) const;
    [[nodiscard]] UnitVector3 get_direction(double time) const;

    [[nodiscard]] double distance (const TimeVector3& vector, double time) const;
    [[nodiscard]] double distance (const Vector3& vector, double time) const;
    [[nodiscard]] double distance (const Line& line, double time) const;

    [[nodiscard]] std::string to_string(double time) const;


};


#endif //CPP_GRAPHICS_LINE_H

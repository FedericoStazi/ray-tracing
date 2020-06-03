//
// Created by federico on 10/04/2020.
//

#ifndef CPP_GRAPHICS_LINE_H
#define CPP_GRAPHICS_LINE_H


#include "../BaseGeometry/Vector3.h"
#include "../BaseGeometry/UnitVector3.h"
#include "../TimeGeometry/TimeUnitVector3.h"

class TimeVector3;
class Line {

private:

    TimeVector3 location;
    TimeUnitVector3 direction;

public:

    Line(TimeVector3 location, TimeUnitVector3 direction);
    Line(const Vector3& location, const UnitVector3& direction);
    Line();

    [[nodiscard]] Vector3 get_location(float time) const;
    [[nodiscard]] UnitVector3 get_direction(float time) const;

    [[nodiscard]] float distance (const Vector3& vector, float time) const;
    [[nodiscard]] float distance (const TimeVector3& vector, float time) const;

    [[nodiscard]] Vector3 evaluate (float k, float time) const;

    static Line between_points(const Vector3& a, const Vector3& b);

    [[nodiscard]] std::string to_string(float time) const;

};


#endif //CPP_GRAPHICS_LINE_H

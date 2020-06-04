//
// Created by federico on 10/04/2020.
//

#ifndef CPP_GRAPHICS_LINE_H
#define CPP_GRAPHICS_LINE_H


#include "../BaseGeometry/Vector3.h"
#include "../BaseGeometry/UnitVector3.h"
#include "../TimeGeometry/TimeUnitVector3.h"

class TimeVector3;

///Line expressed as a + k * b, where a,b are vectors (location and direction respectively). k can be any real number
class Line {

public:

    [[nodiscard]] inline Vector3 get_location(float time) const {
        return location.time(time);
    }

    [[nodiscard]] inline UnitVector3 get_direction(float time) const {
        return direction.time(time);
    }

    ///Minimum distance between a point and the line
    float inline distance(const Vector3& vector, float time) const {
        return get_direction(time).cross(vector - (get_location(time))).norm();
    }

    ///Minimum distance between a point and the line
    float inline distance(const TimeVector3& vector, float time) const {
        return distance(vector.time(time), time);
    }

    ///Evaluate the line at k
    ///(The line is expressed as a + k*b, where a,b are vectors and k is a scalar)
    Vector3 evaluate(float k, float time) const {
        return get_location(time) + (get_direction(time) * k);
    }

    std::string to_string(float time) const {
        return "("+get_location(time).to_string()+","+get_direction(time).to_string()+")";
    }

    ///Static function returning the line between two points
    static Line between_points(const Vector3& a, const Vector3& b) {
        return Line(static_cast<TimeVector3>(a),static_cast<TimeUnitVector3>(static_cast<Vector3>((b - a).normalized())));
    }

    Line(TimeVector3 location, TimeUnitVector3 direction) : location(std::move(location)), direction(std::move(direction)) {}

    Line(const Vector3& location, const UnitVector3& direction) : location(location), direction(direction) {}

    Line() : Line(TimeVector3(), TimeUnitVector3()){}
    
private:

    TimeVector3 location;
    TimeUnitVector3 direction;

};


#endif //CPP_GRAPHICS_LINE_H

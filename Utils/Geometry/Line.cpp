//
// Created by federico on 10/04/2020.
//

#include "Line.h"

#include <utility>


Line::Line(TimeVector3 location, TimeUnitVector3 direction) : location(std::move(location)), direction(std::move(direction)) {}

Line::Line(const Vector3& location, const UnitVector3& direction) : location(location), direction(direction) {}

Line::Line() : Line(TimeVector3(), TimeUnitVector3()){}

Vector3 Line::get_location(double time) const {
    return location.time(time);
}

UnitVector3 Line::get_direction(double time) const {
    return direction.time(time);
}

double Line::distance(const Vector3& vector, double time) const {
    Vector3 translated_vector = vector.subtract(get_location(time));
    return get_direction(time).cross_product(translated_vector).magnitude();
}

double Line::distance(const TimeVector3& vector, double time) const {
    return distance(vector.time(time), time);
}

std::string Line::to_string(double time) const {
    return "("+get_location(time).to_string()+","+get_direction(time).to_string()+")";
}


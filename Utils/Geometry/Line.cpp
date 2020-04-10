//
// Created by federico on 10/04/2020.
//

#include "Line.h"

#include <utility>


Line::Line(TimeVector3 position, TimeUnitVector3 direction) : position(std::move(position)), direction(std::move(direction)) {}

Line::Line(const Vector3& position, const UnitVector3& direction) : position(position), direction(direction) {}

Line::Line() : Line(TimeVector3(), TimeUnitVector3()){}

Vector3 Line::get_position(double time = 0) const {
    return position.time(time);
}

UnitVector3 Line::get_direction(double time = 0) const {
    return direction.time(time);
}

double Line::distance(const TimeVector3& vector, double time = 0) const {
    return distance(vector.time(time), time);
}

double Line::distance(const Vector3& vector, double time = 0) const {
    Vector3 translated_vector = vector.add(get_position().scale(-1));
    return get_direction(time).cross_product(translated_vector).magnitude();
}

double Line::distance(const Line& line, double time = 0) const {
    return Line::distance(line.get_position(time), time);
}


std::string Line::to_string(double time = 0) const {
    return "("+get_position(time).to_string()+","+get_direction(time).to_string()+")";
}


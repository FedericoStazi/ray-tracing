//
// Created by federico on 10/04/2020.
//

#include "Line.h"

#include <utility>


Line::Line(TimeVector3 location, TimeUnitVector3 direction) : location(std::move(location)), direction(std::move(direction)) {}

Line::Line(const Vector3& location, const UnitVector3& direction) : location(location), direction(direction) {}

Line::Line() : Line(TimeVector3(), TimeUnitVector3()){}

Vector3 Line::get_location(float time) const {
    return location.time(time);
}

UnitVector3 Line::get_direction(float time) const {
    return direction.time(time);
}

float Line::distance(const Vector3& vector, float time) const {
    Vector3 translated_vector = vector - (get_location(time));
    return get_direction(time).cross(translated_vector).norm();
}

float Line::distance(const TimeVector3& vector, float time) const {
    return distance(vector.time(time), time);
}

Vector3 Line::evaluate(float k, float time) const {
    return get_location(time) + (get_direction(time) * k);
}

std::string Line::to_string(float time) const {
    return "("+get_location(time).to_string()+","+get_direction(time).to_string()+")";
}

Line Line::between_points(const Vector3& a, const Vector3& b) {
    return Line(static_cast<TimeVector3>(a),static_cast<TimeUnitVector3>(static_cast<Vector3>((b - a).normalized())));
}


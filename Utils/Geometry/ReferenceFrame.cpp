//
// Created by federico on 10/04/2020.
//

#include "ReferenceFrame.h"

#include <utility>
#include "../BaseGeometry/Vector2.h"

ReferenceFrame::ReferenceFrame(TimeVector3 location, Basis orientation) : location(std::move(location)), orientation(std::move(orientation)) {}

ReferenceFrame::ReferenceFrame() : location(TimeVector3()), orientation(Basis()) {}

Vector3 ReferenceFrame::get_location(float time) const {
    return location.time(time);
}

Basis ReferenceFrame::get_orientation() const{
    return orientation;
}

Vector3 ReferenceFrame::to_ref_frame(const Vector3 &v, float time) const {
    return get_orientation().get_matrix(time) * (v - get_location(time));
}

Vector3 ReferenceFrame::to_ref_frame(const TimeVector3& v, float time) const {
    return to_ref_frame(v.time(time), time);
}

Line ReferenceFrame::to_ref_frame(const Line &l, float time) const {
    return Line(
            static_cast<TimeVector3>(to_ref_frame(l.get_location(time), time)),
            static_cast<TimeUnitVector3>(unit_to_ref_frame(l.get_direction(time), time))
            );
}

UnitVector3 ReferenceFrame::unit_to_ref_frame(const UnitVector3 &v, float time) const {
    return static_cast<UnitVector3>(ReferenceFrame(TimeVector3(0, 0, 0), get_orientation()).to_ref_frame(v, time));
}

UnitVector3 ReferenceFrame::unit_to_ref_frame(const TimeUnitVector3 &v, float time) const {
    return unit_to_ref_frame(v.time(time), time);
}

Vector3 ReferenceFrame::from_ref_frame(const Vector3 &v, float time) const {
    return get_orientation().get_matrix(time).inverse() * v + get_location(time);
}

Vector3 ReferenceFrame::from_ref_frame(const TimeVector3& v, float time) const {
    return from_ref_frame(v.time(time), time);
}

UnitVector3 ReferenceFrame::unit_from_ref_frame(const UnitVector3 &v, float time) const {
    return UnitVector3(ReferenceFrame(TimeVector3(0, 0, 0), get_orientation()).from_ref_frame(v, time));
}

UnitVector3 ReferenceFrame::unit_from_ref_frame(const TimeUnitVector3 &v, float time) const {
    return unit_from_ref_frame(v.time(time), time);
}

Vector2 ReferenceFrame::to_plane(const Vector3 &v, float time) const {
    return Vector2(to_ref_frame(v, time));
}

Vector2 ReferenceFrame::to_plane(const TimeVector3& v, float time) const {
    return Vector2(to_ref_frame(v, time));
}

Vector3 ReferenceFrame::from_plane(const Vector2 &v, float time) const {
    return from_ref_frame(v, time);
}

Vector3 ReferenceFrame::from_plane(const TimeVector2& v, float time) const {
    return from_ref_frame(v, time);
}

float ReferenceFrame::k_intersection(const Line& line, float time) const {
    return
            get_orientation().get_z_base(time).dot(get_location(time) - line.get_location(time)) /
            get_orientation().get_z_base(time).dot(line.get_direction(time));
}

Vector2 ReferenceFrame::point_intersection(const Line& line, float time) const {
    return to_plane(line.evaluate(k_intersection(line, time), time), time);
}



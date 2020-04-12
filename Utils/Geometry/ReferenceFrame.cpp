//
// Created by federico on 10/04/2020.
//

#include "ReferenceFrame.h"

#include <utility>
#include "../BaseGeometry/Vector2.h"

ReferenceFrame::ReferenceFrame(TimeVector3 location, Basis orientation) : location(std::move(location)), orientation(std::move(orientation)) {}

ReferenceFrame::ReferenceFrame() : location(TimeVector3()), orientation(Basis()) {}

Vector3 ReferenceFrame::get_location(double time) const {
    return location.time(time);
}

Basis ReferenceFrame::get_orientation() const{
    return orientation;
}

Vector3 ReferenceFrame::to_ref_frame(const Vector3 &v, double time) const {
    return Vector3(
            v.subtract(get_location(time)).dot_product(get_orientation().get_x_base(time)),
            v.subtract(get_location(time)).dot_product(get_orientation().get_y_base(time)),
            v.subtract(get_location(time)).dot_product(get_orientation().get_z_base(time))
    );
}

Vector3 ReferenceFrame::to_ref_frame(const TimeVector3& v, double time) const {
    return to_ref_frame(v.time(time), time);
}

Line ReferenceFrame::to_ref_frame(const Line &l, double time) const {
    return Line(
            TimeVector3(to_ref_frame(l.get_location(time), time)),
            TimeUnitVector3(UnitVector3(unit_to_ref_frame(l.get_direction(time), time)))
            );
}

UnitVector3 ReferenceFrame::unit_to_ref_frame(const UnitVector3 &v, double time) const {
    return UnitVector3(ReferenceFrame(TimeVector3(0, 0, 0), get_orientation()).to_ref_frame(v, time));
}

UnitVector3 ReferenceFrame::unit_to_ref_frame(const TimeUnitVector3 &v, double time) const {
    return unit_to_ref_frame(v.time(time), time);
}

Vector3 ReferenceFrame::from_ref_frame(const Vector3 &v, double time) const {

    ReferenceFrame non_translated_ref_frame(TimeVector3(0, 0, 0), get_orientation());

    Basis origin_to_ref_frame (
                TimeUnitVector3(UnitVector3(non_translated_ref_frame.to_ref_frame(Vector3(1, 0, 0), time))),
                TimeUnitVector3(UnitVector3(non_translated_ref_frame.to_ref_frame(Vector3(0, 1, 0), time))),
                TimeUnitVector3(UnitVector3(non_translated_ref_frame.to_ref_frame(Vector3(0, 0, 1), time)))
            );

    return Vector3(
            v.dot_product(origin_to_ref_frame.get_x_base(time)),
            v.dot_product(origin_to_ref_frame.get_y_base(time)),
            v.dot_product(origin_to_ref_frame.get_z_base(time))
    ).add(get_location(time));
}

Vector3 ReferenceFrame::from_ref_frame(const TimeVector3& v, double time) const {
    return from_ref_frame(v.time(time), time);
}

UnitVector3 ReferenceFrame::unit_from_ref_frame(const UnitVector3 &v, double time) const {
    return UnitVector3(ReferenceFrame(TimeVector3(0, 0, 0), get_orientation()).from_ref_frame(v, time));
}

UnitVector3 ReferenceFrame::unit_from_ref_frame(const TimeUnitVector3 &v, double time) const {
    return unit_from_ref_frame(v.time(time), time);
}

Vector2 ReferenceFrame::to_plane(const Vector3 &v, double time) const {
    return Vector2(to_ref_frame(v, time));
}

Vector2 ReferenceFrame::to_plane(const TimeVector3& v, double time) const {
    return Vector2(to_ref_frame(v, time));
}

Vector3 ReferenceFrame::from_plane(const Vector2 &v, double time) const {
    return from_ref_frame(v, time);
}

Vector3 ReferenceFrame::from_plane(const TimeVector2& v, double time) const {
    return from_ref_frame(v, time);
}

double ReferenceFrame::k_intersection(const Line& line, double time) const {
    return
            get_orientation().get_z_base(time).dot_product(get_location(time).subtract(line.get_location(time))) /
            get_orientation().get_z_base(time).dot_product(line.get_direction(time));
}

Vector2 ReferenceFrame::point_intersection(const Line& line, double time) const {
    return to_plane(line.get_location(time).add(line.get_direction(time).scale(k_intersection(line, time))), time);
}



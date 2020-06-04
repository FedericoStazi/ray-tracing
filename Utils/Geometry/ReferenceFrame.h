//
// Created by federico on 10/04/2020.
//

#ifndef CPP_GRAPHICS_REFERENCEFRAME_H
#define CPP_GRAPHICS_REFERENCEFRAME_H


#include "../BaseGeometry/Vector3.h"
#include "Basis.h"
#include "Line.h"
#include "../BaseGeometry/Vector2.h"
#include "../TimeGeometry/TimeVector2.h"

class Basis;

/// Represents a reference, that has an origin and three basis referred to the original reference frame
/// Can be used to represent a plane, where the x and y axis are axis of the plane, and the z axis is the upwards normal
class ReferenceFrame {

public:

    [[nodiscard]] Vector3 inline get_location(float time) const {
        return location.time(time);
    }
    [[nodiscard]] Basis inline get_orientation() const{
        return orientation;
    }

    ///Returns the coordinates of the vector in this reference frame
    [[nodiscard]] Vector3 inline to_ref_frame(const Vector3 &v, float time) const {
        return get_orientation().get_matrix(time) * (v - get_location(time));
    }

    ///Returns the coordinates of the vector in this reference frame
    [[nodiscard]] Vector3 inline to_ref_frame(const TimeVector3& v, float time) const {
        return to_ref_frame(v.time(time), time);
    }

    ///Returns the coordinates of the vector in this reference frame
    [[nodiscard]] Line inline to_ref_frame(const Line &l, float time) const {
        return Line(
            static_cast<TimeVector3>(to_ref_frame(l.get_location(time), time)),
            static_cast<TimeUnitVector3>(unit_to_ref_frame(l.get_direction(time), time))
        );
    }

    ///Returns the coordinates of the unit vector in this reference frame, but the position is not considered
    ///(This means that the unit vector is simply rotated, and remains a unit vector)
    [[nodiscard]] UnitVector3 inline unit_to_ref_frame(const UnitVector3 &v, float time) const {
        return static_cast<UnitVector3>(ReferenceFrame(
            TimeVector3(0, 0, 0),
            get_orientation()
            ).to_ref_frame(v, time));
    }

    ///Returns the coordinates of the unit vector in this reference frame, but the position is not considered
    ///(This means that the unit vector is simply rotated, and remains a unit vector)
    [[nodiscard]] UnitVector3 inline unit_to_ref_frame(const TimeUnitVector3 &v, float time) const {
        return unit_to_ref_frame(v.time(time), time);
    }

    ///Returns the coordinates of the vector from this reference frame to the original one
    [[nodiscard]] Vector3 inline from_ref_frame(const Vector3 &v, float time) const {
        return get_orientation().get_matrix(time).inverse() * v + get_location(time);
    }

    ///Returns the coordinates of the vector from this reference frame to the original one
    [[nodiscard]] Vector3 inline from_ref_frame(const TimeVector3& v, float time) const {
        return from_ref_frame(v.time(time), time);
    }

    ///Returns the coordinates of the unit vector from this reference frame to the original one, but the position is not considered
    ///(This means that the unit vector is simply rotated, and remains a unit vector)
    [[nodiscard]] UnitVector3 inline unit_from_ref_frame(const UnitVector3 &v, float time) const {
        return UnitVector3(ReferenceFrame(TimeVector3(0, 0, 0), get_orientation()).from_ref_frame(v, time));
    }

    ///Returns the coordinates of the unit vector from this reference frame to the original one, but the position is not considered
    ///(This means that the unit vector is simply rotated, and remains a unit vector)
    [[nodiscard]] UnitVector3 inline unit_from_ref_frame(const TimeUnitVector3 &v, float time) const {
        return unit_from_ref_frame(v.time(time), time);
    }

    /// Returns the coordinates of the point on this plane
    /// The vector must lie on the plane
    [[nodiscard]] Vector2 inline to_plane(const Vector3 &v, float time) const {
        return Vector2(to_ref_frame(v, time).zero_z());
    }

    /// Returns the coordinates of the point on this plane
    /// The vector must lie on the plane
    [[nodiscard]] Vector2 inline to_plane(const TimeVector3& v, float time) const {
        return Vector2(to_ref_frame(v, time).zero_z());
    }

    /// Returns the coordinates of a point on this plane in the original reference frame
    [[nodiscard]] Vector3 inline from_plane(const Vector2 &v, float time) const {
        return from_ref_frame(v, time);
    }

    /// Returns the coordinates of a point on this plane in the original reference frame
    [[nodiscard]] Vector3 inline from_plane(const TimeVector2& v, float time) const {
        return from_ref_frame(v, time);
    }

    /// Returns the point of intersection of the line with the plane, expressed as the scalar k
    /// The line is expressed as a + k*b, and the value returned is such that a + k*b is the intersection
    [[nodiscard]] float inline k_intersection(const Line& line, float time) const {
        return
            get_orientation().get_z_base(time).dot(get_location(time) - line.get_location(time)) /
            get_orientation().get_z_base(time).dot(line.get_direction(time));
    }

    /// Returns the point of intersection of the line with the plane, in the plane coordinates
    [[nodiscard]] Vector2 inline point_intersection(const Line& line, float time) const {
        return to_plane(line.evaluate(k_intersection(line, time), time), time);
    }

    ReferenceFrame(TimeVector3 location, Basis orientation)
        : location(std::move(location)),
          orientation(std::move(orientation)) {}

    ReferenceFrame() : location(TimeVector3()), orientation(Basis()) {}

private:

    TimeVector3 location;
    Basis orientation;

};


#endif //CPP_GRAPHICS_REFERENCEFRAME_H

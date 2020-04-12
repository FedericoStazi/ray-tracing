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

class ReferenceFrame {

private:

    TimeVector3 location;
    Basis orientation;

public:

    ReferenceFrame(TimeVector3 location, Basis orientation);
    ReferenceFrame();

    [[nodiscard]] Vector3 get_location(double time) const;
    [[nodiscard]] Basis get_orientation() const;

    [[nodiscard]] Vector3 to_ref_frame(const Vector3& v, double time) const;
    [[nodiscard]] Vector3 to_ref_frame(const TimeVector3& v, double time) const;
    [[nodiscard]] Line to_ref_frame(const Line& l, double time) const;

    [[nodiscard]] UnitVector3 unit_to_ref_frame(const UnitVector3& v, double time) const;
    [[nodiscard]] UnitVector3 unit_to_ref_frame(const TimeUnitVector3& v, double time) const;

    [[nodiscard]] Vector3 from_ref_frame(const Vector3& v, double time) const;
    [[nodiscard]] Vector3 from_ref_frame(const TimeVector3& v, double time) const;

    // v must lie on the plane xy
    [[nodiscard]] Vector2 to_plane(const TimeVector3& v, double time) const;
    [[nodiscard]] Vector2 to_plane(const Vector3& v, double time) const;

    [[nodiscard]] Vector3 from_plane(const TimeVector2& v, double time) const;
    [[nodiscard]] Vector3 from_plane(const Vector2& v, double time) const;

    [[nodiscard]] double k_intersection(const Line& line, double time) const;
    [[nodiscard]] Vector2 point_intersection(const Line& line, double time) const;

};


#endif //CPP_GRAPHICS_REFERENCEFRAME_H

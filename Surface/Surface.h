//
// Created by federico on 11/04/2020.
//

#ifndef CPP_GRAPHICS_SURFACE_H
#define CPP_GRAPHICS_SURFACE_H


#include "../Entity.h"
#include "../Aspect/Aspect.h"

class Surface : public Entity{

private:

    Aspect aspect;
    std::vector<Vector2> points;

protected:

    Surface(const ReferenceFrame &referenceFrame, const Aspect &aspect);

    [[nodiscard]] const Aspect &get_aspect() const;

    void add(const Vector2& point);

public:

    virtual std::vector<std::pair<double, Color>> intersections(const Line & ray, double time);


};


#endif //CPP_GRAPHICS_SURFACE_H

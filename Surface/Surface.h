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

protected:

    std::vector<Vector2> points;

    Surface(const ReferenceFrame &referenceFrame, const Aspect &aspect);

    [[nodiscard]] const Aspect &get_aspect() const;

public:

    virtual std::vector<std::pair<double, Color>> intersections(Line ray, double time) = 0;


};


#endif //CPP_GRAPHICS_SURFACE_H

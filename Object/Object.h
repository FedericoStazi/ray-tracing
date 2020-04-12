//
// Created by federico on 11/04/2020.
//

#ifndef CPP_GRAPHICS_OBJECT_H
#define CPP_GRAPHICS_OBJECT_H


#include <utility>
#include <vector>
#include <set>
#include "../Aspect/Color.h"
#include "../Utils/Geometry/Line.h"
#include "../Entity.h"
#include "../Surface/Surface.h"
#include "../Light/Light.h"

class Object : public Entity {

private:

    std::set<Surface*> surfaces;

protected:

    explicit Object(const ReferenceFrame &referenceFrame);

    void add(Surface * surface);

public:

    std::vector<std::pair<double, Surface *>> intersections(const Line& ray, double time);

};


#endif //CPP_GRAPHICS_OBJECT_H

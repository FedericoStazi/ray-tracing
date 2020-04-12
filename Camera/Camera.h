//
// Created by federico on 11/04/2020.
//

#ifndef CPP_GRAPHICS_CAMERA_H
#define CPP_GRAPHICS_CAMERA_H


#include <string>
#include "../Scene.h"
#include "../Entity.h"

class Camera : public Entity {

private:

    Scene scene;

protected:

    Camera(const ReferenceFrame &referenceFrame, const Scene &scene);

public:

    [[nodiscard]] const Scene get_scene() const;

    UnitVector3 get_direction(double time);

    virtual std::string picture(int height, int width, double time) = 0;

};


#endif //CPP_GRAPHICS_CAMERA_H

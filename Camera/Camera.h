//
// Created by federico on 11/04/2020.
//

#ifndef CPP_GRAPHICS_CAMERA_H
#define CPP_GRAPHICS_CAMERA_H


#include <string>
#include "../Scene.h"
#include "../Entity.h"
#include "../Picture.h"

class Camera : public Entity {

private:

    Scene scene;

protected:

    Camera(const ReferenceFrame &referenceFrame, Scene scene);
    Camera(const Vector3 &position, const Vector3 &point, Scene scene);

public:

    [[nodiscard]] Scene get_scene() const;

    UnitVector3 get_direction(double time);

    virtual Picture picture(int height, int width, double time) = 0;

};


#endif //CPP_GRAPHICS_CAMERA_H

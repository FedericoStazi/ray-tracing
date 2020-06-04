//
// Created by federico on 11/04/2020.
//

#ifndef CPP_GRAPHICS_CAMERA_H
#define CPP_GRAPHICS_CAMERA_H


#include <string>
#include "../Scene.h"
#include "../Entity.h"
#include "../Picture.h"

///Parent class of all cameras
class Camera : public Entity {

public:

    [[nodiscard]] Scene inline get_scene() const {
        return scene;
    }

    [[nodiscard]] UnitVector3 inline get_direction(float time) const {
        return static_cast<UnitVector3>(get_reference_frame().get_orientation().get_z_base(time) * (-1));
    }

    virtual Picture picture(int height, int width, float time) = 0;

    virtual Color cast_ray(Vector2 position, float time) const = 0;

protected:

    Camera(const ReferenceFrame &referenceFrame, Scene scene) : Entity(referenceFrame), scene(std::move(scene)) {}

    Camera(const Vector3 &position, const Vector3 &point, Scene scene)
        : Camera(generate_reference_frame(position, point),
          std::move(scene)) {}

private:

    ReferenceFrame generate_reference_frame(const Vector3 &position, const Vector3 &point);

    Scene scene;

};


#endif //CPP_GRAPHICS_CAMERA_H

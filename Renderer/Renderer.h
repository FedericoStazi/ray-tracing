//
// Created by federico on 02/06/2020.
//

#ifndef CPP_GRAPHICS_RENDERER_H
#define CPP_GRAPHICS_RENDERER_H

#include "../Picture.h"
#include "../Camera/Camera.h"

// TODO make virtual and use design strategy
class Camera;
class Renderer {

public:
    explicit Renderer(Camera& camera) : camera(camera) {};
    [[nodiscard]] Picture picture(int height, int width, double time) const;

private:
    Camera& camera;

};


#endif //CPP_GRAPHICS_RENDERER_H

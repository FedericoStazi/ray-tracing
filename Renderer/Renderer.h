//
// Created by federico on 02/06/2020.
//

#ifndef CPP_GRAPHICS_RENDERER_H
#define CPP_GRAPHICS_RENDERER_H

#include "../Picture.h"
#include "../Camera/Camera.h"

class Camera;

///This class manages rendering, meaning that it chooses how to cast rays into the scene in a performing way
class Renderer {

public:

    ///Render a picture given height and width
    [[nodiscard]] Picture picture(int height, int width, float time) const;

    explicit Renderer(Camera& camera) : camera(camera) {};

private:

    Camera& camera;

};


#endif //CPP_GRAPHICS_RENDERER_H

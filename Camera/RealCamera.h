//
// Created by federico on 13/04/2020.
//

#ifndef CPP_GRAPHICS_REALCAMERA_H
#define CPP_GRAPHICS_REALCAMERA_H

#include <string>
#include "Camera.h"
#include "../Picture.h"
#include "../Renderer/Renderer.h"

class RealCamera : public Camera {

private:

    int _reflections = 1;
    int _first_samples = 20;

    //Camera characteristics
    float sensor_size = 3.5;
    float focal_length = 5;
    float lens_distance = 5.16748;
    float aperture_size = 5;
    float aperture_distance = 10;
    float shutter_speed = 0.005;

    static int additional_samples(float k) {
        return (int) k + (int) (100.0 * sqrt(k));
    }

    const Renderer renderer;

public:

    RealCamera(const ReferenceFrame &referenceFrame, const Scene &scene);
    RealCamera(const Vector3 &position, const Vector3 &point, Scene scene);

    RealCamera(const ReferenceFrame &referenceFrame, const Scene &scene, float sensor_size, float focal_length,
               float lens_distance, float aperture_size, float aperture_distance);

    void set_sensor_size(float sensor_size);
    void set_focal_length(float focal_length);
    void set_lens_distance(float lens_distance);
    void set_aperture_size(float aperture_size);
    void set_aperture_distance(float aperture_distance);
    void set_shutter_speed(float shutter_speed);

    float get_focal_plane_distance() const;
    float get_focal_plane_size() const;

    Picture picture(int height, int width, float time) override;
    Color cast_ray(Vector2 position, float time);

};


#endif //CPP_GRAPHICS_REALCAMERA_H

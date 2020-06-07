//
// Created by federico on 13/04/2020.
//

#ifndef CPP_GRAPHICS_REALCAMERA_H
#define CPP_GRAPHICS_REALCAMERA_H

#include <string>
#include "Camera.h"
#include "../Picture.h"
#include "../Renderer/Renderer.h"

///Camera class with realistic parameters
class RealCamera : public Camera {

public:

    void set_sensor_size(float _sensor_size) {
        sensor_size = _sensor_size;
    }

    void set_focal_length(float _focal_length) {
        focal_length = _focal_length;
    }

    void set_lens_distance(float _lens_distance) {
        lens_distance = _lens_distance;
    }

    void set_aperture_size(float _aperture_size) {
        aperture_size = _aperture_size;
    }

    void set_aperture_distance(float _aperture_distance) {
        aperture_distance = _aperture_distance;
    }

    void set_shutter_speed(float _shutter_speed) {
        shutter_speed = _shutter_speed;
    }

    [[nodiscard]] float inline get_focal_plane_distance() const {
        return (lens_distance * focal_length / (lens_distance - focal_length) ) - aperture_distance;
    }

    [[nodiscard]] float inline get_focal_plane_size() const {
        return get_focal_plane_distance() * sensor_size / lens_distance;
    }

    [[nodiscard]] Picture picture(int height, int width, float time) override {
        return renderer.picture(height, width, time);
    }

    Color cast_ray(Vector2 position, float time) const override;

    RealCamera(const ReferenceFrame &referenceFrame, const Scene &scene)
        : Camera(referenceFrame, scene),
          renderer(Renderer(*this)) {}

    RealCamera(const Vector3 &position, const Vector3 &point, Scene scene)
        : Camera(position, point, std::move(scene)),
          renderer(Renderer(*this)) {}

    RealCamera(const ReferenceFrame &referenceFrame,
               const Scene &scene,
               float sensor_size,
               float focal_length,
               float lens_distance,
               float aperture_size,
               float aperture_distance)
        : Camera(referenceFrame, scene),
          sensor_size(sensor_size),
          focal_length(focal_length),
          lens_distance(lens_distance),
          aperture_size(aperture_size),
          aperture_distance(aperture_distance),
          renderer(Renderer(*this)) {}

private:

    int _reflections = 3;

    //Camera characteristics
    float sensor_size = 3.5;
    float focal_length = 5;
    float lens_distance = 5.16748;
    float aperture_size = 5;
    float aperture_distance = 10;
    float shutter_speed = 0.005;

    const Renderer renderer;

};


#endif //CPP_GRAPHICS_REALCAMERA_H

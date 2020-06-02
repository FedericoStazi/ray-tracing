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
    double sensor_size = 3.5;
    double focal_length = 5;
    double lens_distance = 5.16748;
    double aperture_size = 5;
    double aperture_distance = 10;
    double shutter_speed = 0.005;

    static int additional_samples(double k) {
        return (int) k + (int) (100.0 * sqrt(k));
    }

    const Renderer renderer;

public:

    RealCamera(const ReferenceFrame &referenceFrame, const Scene &scene);
    RealCamera(const Vector3 &position, const Vector3 &point, Scene scene);

    RealCamera(const ReferenceFrame &referenceFrame, const Scene &scene, double sensor_size, double focal_length,
               double lens_distance, double aperture_size, double aperture_distance);

    void set_sensor_size(double sensor_size);
    void set_focal_length(double focal_length);
    void set_lens_distance(double lens_distance);
    void set_aperture_size(double aperture_size);
    void set_aperture_distance(double aperture_distance);
    void set_shutter_speed(double shutter_speed);

    double get_focal_plane_distance() const;
    double get_focal_plane_size() const;

    Picture picture(int height, int width, double time) override;
    Picture picture_old(int height, int width, double time);

    std::pair<Color, double> cast_n_rays(int height, int width, int j, int i, double time, int n);
    Color cast_ray(Vector2 position, double time);

};


#endif //CPP_GRAPHICS_REALCAMERA_H

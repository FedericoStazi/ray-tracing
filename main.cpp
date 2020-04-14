//
// Created by federico on 09/04/2020.
//

#include <iostream>
#include <cmath>
#include <fstream>
#include <chrono>
#include "Utils/TimeGeometry/TimeVector3.h"
#include "Utils/TimeGeometry/TimeUnitVector3.h"
#include "Utils/TimeGeometry/TimeVector2.h"
#include "Utils/Geometry/Basis.h"
#include "Utils/Geometry/ReferenceFrame.h"
#include "Scene.h"
#include "Object/Ball.h"
#include "Object/Object2D.h"
#include "Object/Cube.h"
#include "Light/SimpleLight.h"
#include "Aspect/RGB.h"
#include "Surface/Square.h"
#include "Camera/RealCamera.h"

void print_picture(const std::string& picture, const std::string& file = (std::string) "pic.ppm", bool open = false) {

    std::ofstream out(file);
    out<<picture<<std::endl;

    if (open) {
        std::string command = "xdg-open " + file;
        system(command.c_str());
    }

    auto end = std::chrono::system_clock::now();
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::cout<< "printed " + file + " " + std::ctime(&end_time) + "\n";

}

int main() {

    // Set of object aspects

    Aspect aspect1(RGB(255, 209, 241).from_rgb(), Color(0.5, 0.5, 0.5), Color(0.05, 0.05, 0.05), 5);
    Aspect aspect2(RGB(226, 209, 255).from_rgb(), Color(0.5, 0.5, 0.5), Color(0.5, 0.5, 0.5), 5);
    Aspect aspect3(RGB(181, 2, 88).from_rgb(), Color(0.1, 0.1, 0.1), Color(0, 0, 0), 2);
    Aspect aspect4(RGB(140, 230, 64).from_rgb(), Color(0.5, 0.5, 0.5), Color(0, 0, 0), 10);

    // Scene elements

    Scene scene;

    scene.add(new Ball (ReferenceFrame(TimeVector3(
            TimeFunction([=](double t){ return 100*t;}),
            TimeFunction(-10),
            TimeFunction(0)
            ), Basis()), aspect4, 10));

    scene.add(new Ball (ReferenceFrame(TimeVector3(0, 10, -200), Basis()), aspect3, 30));

    scene.add(new Object2D(ReferenceFrame(TimeVector3(0, -20, -70), Basis(
            TimeUnitVector3(1, 0, 0),
            TimeUnitVector3(0, 0, 1),
            TimeUnitVector3(0, -1, 0)
            )), new Square(ReferenceFrame(TimeVector3(0, 0, 0), Basis()), aspect2, 400)));

    scene.add(new Cube(ReferenceFrame(TimeVector3(-30, 20, -100), Basis()), aspect1, 40));

    scene.add(new SimpleLight(ReferenceFrame(TimeVector3(0, 100, 0), Basis()), Color(0.5, 0.5, 0.5)));

    scene.add(new SimpleLight(ReferenceFrame(TimeVector3(50, 10, 100), Basis()), Color(0.5, 0.5, 0.5)));

    // Cameras

    // Regular picture
    RealCamera c1(Vector3(30, 10, 150), Vector3(0, 0, 0), scene);
    c1.set_aperture_size(0.05);
    c1.set_shutter_speed(0.01);
    print_picture(c1.picture(500, 500, 0), "picture1.ppm");

    // High aperture (f1) picture
    RealCamera c2(Vector3(30, 10, 150), Vector3(0, 0, 0), scene);
    c2.set_aperture_size(5);
    c2.set_shutter_speed(0.01);
    print_picture(c2.picture(500, 500, 0), "picture2.ppm");

    // Low shutter speed picture
    RealCamera c3(Vector3(30, 10, 150), Vector3(0, 0, 0), scene);
    c3.set_aperture_size(0.05);
    c3.set_shutter_speed(0.1);
    print_picture(c3.picture(500, 500, 0), "picture3.ppm");

    // High aperture and low shutter speed picture
    RealCamera c4(Vector3(30, 10, 150), Vector3(0, 0, 0), scene);
    c4.set_aperture_size(5);
    c4.set_shutter_speed(0.1);
    print_picture(c4.picture(500, 500, 0), "picture4.ppm");

}

//
// Created by federico on 09/04/2020.
//

#include <iostream>
#include <cmath>
#include <fstream>
#include <chrono>
#include "Utils/BaseGeometry/Constants.h"
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
#include "Surface/OpenCylinder.h"
#include "Object/Cylinder.h"

void print_picture(const Picture& picture, const std::string& file = (std::string) "pic.ppm", bool open = false) {

    std::string str;

    for (int j=0; j<picture.get_height(); j++) {
      for (int i = 0; i < picture.get_width(); i++)
        str += picture.get_pixel(j, i).to_string();
      str += "\n";
    }

    std::ofstream out(file);
    str = "P3\n"+std::to_string(picture.get_height())+" "+std::to_string(picture.get_width())+"\n255\n" + str;
    out<<str<<std::endl;

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

    Aspect aspect1(RGB(20, 100, 200).from_rgb(), Color(0.5, 0.5, 0.5), Color(0.5, 0.5, 0.5), 5);
    Aspect aspect2(RGB(150, 150, 150).from_rgb(), Color(0.5, 0.5, 0.5), Color(0.5, 0.5, 0.5), 5);
    Aspect aspect3(RGB(181, 2, 88).from_rgb(), Color(0.1, 0.1, 0.1), Color(0, 0, 0), 2);
    Aspect aspect4(RGB(140, 230, 64).from_rgb(), Color(0.5, 0.5, 0.5), Color(0, 0, 0), 10);

    // Scene elements

    Scene scene;

    scene.add(new Ball (ReferenceFrame(TimeVector3(
            TimeFunction(new std::function<float(float)>([](float t){ return 100*t;})),
            TimeFunction(-10.0f),
            TimeFunction(0.0f)
            ), Basis()), aspect4, 10));

    scene.add(new Ball (ReferenceFrame(TimeVector3(0, 10, -200), Basis()), aspect3, 30));

    scene.add(new Object2D(ReferenceFrame(TimeVector3(0, -20, -70), Basis(
            TimeUnitVector3(1, 0, 0),
            TimeUnitVector3(0, 0, 1),
            TimeUnitVector3(0, -1, 0)
            )), new Square(ReferenceFrame(TimeVector3(0, 0, 0), Basis()), aspect2, 400)));

    scene.add(new Cube(ReferenceFrame(TimeVector3(-60, 20, -80), Basis()), aspect1, 40));

    scene.add(new Cylinder(ReferenceFrame(TimeVector3(20,40,-250), Basis(
        TimeUnitVector3(0, 0, 1),
        TimeUnitVector3(1, 0, 0),
        TimeUnitVector3(0, 1, 0)
    )), aspect4, 50, 50));

    scene.add(new Cylinder(ReferenceFrame(TimeVector3(25,0,-40), Basis(
        TimeUnitVector3(0, 0, 1),
        TimeUnitVector3(sqrt(0.5f), -sqrt(0.5f), 0),
        TimeUnitVector3(sqrt(0.5f), sqrt(0.5f), 0)
    )), aspect3, 10, 20));

    scene.add(new SimpleLight(ReferenceFrame(TimeVector3(0, 50, 30), Basis()), Color(0.5, 0.5, 0.5)));

    scene.add(new SimpleLight(ReferenceFrame(TimeVector3(50, 10, -100), Basis()), Color(0.5, 0.5, 0.5)));

    // Cameras

    // Regular picture
    RealCamera c1(Vector3(30, 10, 150), Vector3(0, 0, 0), scene);
    c1.set_aperture_size(0.1);
    c1.set_shutter_speed(0);
    std::string name = "pic"+std::to_string(clock());
    print_picture(c1.picture(500, 500, 0), name);
    //system(("xdg-open "+name).c_str());
/*
    // High aperture (f1) picture
    RealCamera c2(Vector3(30, 10, 150), Vector3(0, 0, 0), scene);
    c2.set_aperture_size(5);
    c2.set_shutter_speed(0.01);
    print_picture(c2.picture(500, 500, 0), "picture2.ppm");

    // Low shutter speed picture
    RealCamera c3(Vector3(30, 10, 150), Vector3(0, 0, 0), scene);
    c3.set_aperture_size(0.01);
    c3.set_shutter_speed(0.1);
    print_picture(c3.picture(500, 500, 0), "picture3.ppm");

    // High aperture and low shutter speed picture
    RealCamera c4(Vector3(30, 10, 150), Vector3(0, 0, 0), scene);
    c4.set_aperture_size(5);
    c4.set_shutter_speed(0.1);
    print_picture(c4.picture(500, 500, 0), "picture4.ppm");
*/
}

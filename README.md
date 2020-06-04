# cpp_graphics
C++ graphics library using Ray Tracing

Based on Phong's and Lambertian's shading

# Main features

- Objects have coordinates that can be described as functions of time

- The camera's shutter and aperture can be modified

- Virtual classes allow simple creation of new objects for the scene

# Optimizations

- Objects are inscribed in a sphere. If the ray does not touch the sphere, the expensive intersection computation is not performed


- If an object's coordinates are not a function of time, they are optimized, making scenes with just a few moving objects much faster

- More rays are casted on pixels were rays casted so far have an higher variation

- Multithreading is used to improve performance

# Results

This is an high resolution image (500x500) created in ~5hrs on a regular laptop:

This is a lower resolution image (250x250) with an object really close to the camera:

This is the heatmap of the number of rays for each pixel, showing where more rays were casted:

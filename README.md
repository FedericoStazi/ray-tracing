# cpp_graphics
C++ graphics library using Ray Tracing

Based on Phong's and Lambertian's shading

# Main features

- Objects have coordinates as functions of time

- The camera's shutter and aperture can be modified

# Optimizations

- Objects are inscribed in a sphere. If the ray does not touch the sphere, the intersection is not calculated at all

- Functions of time can be a lambda or a float  if the function is constant, and have a caching optimization

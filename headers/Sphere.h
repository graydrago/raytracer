#pragma once

//#include <glm/vec2.hpp>
//#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <SDL2/SDL.h>

#include "GeometricObject.h"

class Sphere : public GeometricObject {
    //private:
    public:
        glm::vec3 center;
        double radius;
        //static const double kEpsilon; // See chapter 16

        Sphere() : center({0, 0, 0}), radius(1) {}
        Sphere(glm::vec3 c, double r) : center(c), radius(r) {}
        Sphere(Sphere &s) : center(s.center), radius(s.radius) {}
        Sphere& operator=(Sphere &r) {
            if (&r == this) return *this;
            center = r.center;
            radius = r.radius;
            return *this;
        }
        ~Sphere() {};

        virtual bool hit(const Ray& ray, double& tmin, ShadeRec& sr) {
            using namespace glm;

            vec2 c{center.x, center.y};
            vec2 r(ray.o.x, ray.o.y);
            vec2 d = r - c;
            if (glm::length(d) <= radius) {
                return true;
            } else {
                return false;
            }
        }
};

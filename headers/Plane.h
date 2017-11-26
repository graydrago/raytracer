#pragma once

#include "GeometricObject.h"

class Plane : public GeometricObject {
    private:
        glm::vec3 point;
        glm::vec3 normal;
        static const double kEpsilon; // See chapter 16

    public:

        Plane() : GeometricObject(), point(0), normal(0, 1, 0) {}
        Plane(glm::vec3 p, glm::vec3 n) : point(p), normal(n) {}
        Plane(Plane &r) : point(r.point), normal(r.normal) {}
        Plane& operator=(Plane &r) {
            if (&r == this) return *this;
            point = r.point;
            normal = r.normal;
            return *this;
        }
        ~Plane() {};

        bool hit(const Ray& ray, double& tmin, ShadeRec& sr) {
          return false;
        }
};

#pragma once

#include <glm/vec3.hpp>

class Ray {
    public:
        glm::vec3 o;  // origin
        glm::vec3 d;  // direction

        Ray() :
          o(0, 0, 0),
          d(0, 0, 1) {}


        Ray(glm::vec3 origin, glm::vec3 direction) :
          o(origin),
          d(direction) {}


        Ray(Ray &r) :
          o(r.o),
          d(r.d) {}


        Ray& operator=(Ray &r) {
            if (&r == this) return *this;
            o = r.o;
            d = r.d;
            return *this;
        }


        ~Ray() {};
};

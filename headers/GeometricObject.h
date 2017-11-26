#pragma once

#include <glm/vec3.hpp>

#include "Ray.h"

class ShadeRec;
class GeometricObject {
    public:
        glm::vec3 color;

        virtual bool hit(const Ray& ray, double& tmin, ShadeRec& sr) = 0;
};

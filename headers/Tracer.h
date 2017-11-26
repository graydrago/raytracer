#pragma once

#include <glm/vec3.hpp>

#include "Ray.h"

class World;

class Tracer {
    protected:
        World* world_ptr;

    public:
        Tracer() : world_ptr(nullptr) {}
        Tracer(World* w_ptr) : world_ptr(w_ptr) {};
        virtual glm::vec3 trace_ray(const Ray& /*ray*/) const { return glm::vec3{0, 0, 0}; };

        virtual ~Tracer() {}
};

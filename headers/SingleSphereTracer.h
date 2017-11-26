#pragma once

#include <glm/vec3.hpp>

#include "World.h"
#include "Tracer.h"
#include "ShadeRec.h"

class World;

class SingleSphereTracer : public Tracer {
    public:
        SingleSphereTracer() : Tracer() {}
        SingleSphereTracer(World* w_ptr) : Tracer(w_ptr) {};
        virtual ~SingleSphereTracer() {}

        virtual glm::vec3 trace_ray(const Ray& ray) const {
            ShadeRec sr(*world_ptr);
            double t;
            if (world_ptr->sphere.hit(ray, t, sr)) {
                return {1, 0, 0};
            } else {
                return {0, 0, 0};
            }

        };
};

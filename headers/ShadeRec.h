#pragma once

#include <glm/vec3.hpp>

class World;
class ShadeRec {
    public:
        bool hit_an_object;         // did the ray hit an object?
        glm::vec3 local_hit_point;  // world coordinate of hit point
        glm::vec3 normal;           // normal at hit point
        glm::vec3 color;
        World& w;                   // world reference for shading

        ShadeRec(World& world);
        ShadeRec(const ShadeRec& sr);
        ShadeRec& operator=(const ShadeRec& sr);

        ~ShadeRec() {};
};

#include "../headers/ShadeRec.h"
#include "../headers/World.h"

ShadeRec::ShadeRec(World& world) :
    hit_an_object(false),
    local_hit_point(0),
    normal(0),
    color(1),
    w(world) {}

ShadeRec::ShadeRec(const ShadeRec& sr) :
    hit_an_object(sr.hit_an_object),
    local_hit_point(sr.local_hit_point),
    normal(sr.normal),
    color(sr.color),
    w(sr.w) {}

ShadeRec& ShadeRec::operator=(const ShadeRec& sr) {
    if (&sr == this) return *this;
    hit_an_object = sr.hit_an_object;
    local_hit_point = sr.local_hit_point;
    normal = sr.normal;
    color = sr.color;
    w = sr.w;
    return *this;
}

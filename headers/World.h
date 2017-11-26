#pragma once

#include <SDL2/SDL.h>
#include <stdexcept>

#include "ViewPlane.h"
#include "Sphere.h"
#include "Tracer.h"

class World {
    public:
        ViewPlane vp;
        glm::vec3 background_color;
        Sphere sphere;
        Tracer* tracer;
        SDL_Window* window;
        SDL_Renderer* renderer;


        World() {};


        virtual ~World() {
          delete tracer;
          SDL_DestroyRenderer(renderer);
          SDL_DestroyWindow(window);
        }


        void build();
        void render_scene();
        void open_window(int hres, int vres);
        void display_pixel(int row, int vres, glm::vec3 pixel_color) const;
        void poll_event();
};

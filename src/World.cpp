#include "../headers/World.h"
#include "../headers/SingleSphereTracer.h"

void World::build() {
    vp.hres = 200;
    vp.vres = 200;
    vp.s = 1;
    background_color = glm::vec3{0};
    tracer = new SingleSphereTracer(this);

    sphere.center = glm::vec3{0.0, 0.0, 0.0};
    //SDL_Log("%f", sphere.center.x);
    sphere.radius = 85;
};


void World::render_scene() {
    SDL_Log("render_scene");
    glm::vec3 pixel_color;
    Ray ray;
    double zw = 100;
    double x, y;

    open_window(vp.hres, vp.vres);
    ray.d = glm::vec3(0, 0, -1);

    for (int r = 0; r < vp.hres; r++) {
        for (int c = 0; c < vp.vres; c++) {
            x = vp.s * (c - 0.5 * (vp.hres - 1.0));
            y = vp.s * (r - 0.5 * (vp.vres - 1.0));
            ray.o = glm::vec3(x, y, zw);
            pixel_color = tracer->trace_ray(ray);
            display_pixel(c, r, pixel_color);
        }
    }

    poll_event();
}


void World::open_window(int hres, int vres) {
    SDL_Log("open_window");
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("Unable to init SDL: %s", SDL_GetError());
        throw new std::runtime_error("");
    }

    window = SDL_CreateWindow(
        "Ray Tracer",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        hres, vres,
        SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        SDL_Log("Unable to create window: %s", SDL_GetError());
        throw new std::runtime_error("");
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        SDL_Log("Unable to create renderer: %s", SDL_GetError());
        throw new std::runtime_error("");
    }

}


void World::display_pixel(int row, int col, glm::vec3 pixel_color) const {
    SDL_SetRenderDrawColor(renderer, pixel_color.r*255, pixel_color.g*255, pixel_color.b*255, 255);
    SDL_RenderDrawPoint(renderer, col, row);
}


void World::poll_event() {
    SDL_Event event;
    bool play = true;
  
    SDL_RenderPresent(renderer);
    while (play) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                {
                    play = false;
                    break;
                }

                case SDL_KEYDOWN:
                {
                    switch (event.key.keysym.sym) {
                        case SDLK_q:
                        {
                            play = false;
                            break;
                        }
                    }
                }
            }
        }

        //SDL_SetRenderDrawColor(renderer, 0, 0, 0, 1);
        //SDL_RenderClear(renderer);
        //SDL_RenderPresent(renderer);
    }
}


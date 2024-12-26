#include "AnimationSecurity.h"
#include <iostream>

AnimationSecurity::AnimationSecurity(const std::string& name, int x, int y, int width, int height)
    : name(name), x(x), y(y), width(width), height(height), window(nullptr), renderer(nullptr), texture(nullptr)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "Error initializing SDL: " << SDL_GetError() << std::endl;
        exit(1);
    }


    window = SDL_CreateWindow(name.c_str(), x, y, width, height, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "Error creating window: " << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(1);
    }


    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cerr << "Error creating renderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        exit(1);
    }


    texture = loadTexture("path/to/image.png");
    if (texture == nullptr) {
        std::cerr << "Error loading texture: " << SDL_GetError() << std::endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        exit(1);
    }
}

AnimationSecurity::~AnimationSecurity() {
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

SDL_Texture* AnimationSecurity::loadTexture(const std::string& path) {
    SDL_Surface* surface = SDL_LoadBMP(path.c_str());
    if (surface == nullptr) {
        std::cerr << "Error loading image: " << SDL_GetError() << std::endl;
        return nullptr;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (texture == nullptr) {
        std::cerr << "Error creating texture: " << SDL_GetError() << std::endl;
        return nullptr;
    }

    return texture;
}

void AnimationSecurity::draw() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_Rect destRect = { x, y, width, height };
    SDL_RenderCopy(renderer, texture, nullptr, &destRect);

    SDL_RenderPresent(renderer);
}

void AnimationSecurity::update() {

    x += 1;

    draw();
}
#include "Habit.h"
using namespace std;

Habit::Habit(const std::string& name, const std::string& description, SDL_Texture* texture, int healthEffect, int staminaEffect) : name(name), description(description), texture(texture), healthEffect(healthEffect), staminaEffect(staminaEffect) {}
Habit::~Habit() {
    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
}
void Habit::render(SDL_Renderer* renderer, int x, int y) {
    if (texture != nullptr) {
        SDL_Rect dstRect = { x, y, 1280, 720 };
        SDL_RenderCopy(renderer, texture, nullptr, &dstRect);
    }
}
#include "Security.h"
#include "Map.h"
#include <SDL.h>
#include <iostream>
#include <algorithm>

Security::Security(const std::string& name, int habit, int endurance, int age, int health, int startX, int startY, Map* m)
    : name(name), age(age), habit(habit), endurance(endurance), health(health), speed(4), renderer(nullptr), characterTexture(nullptr), map(m) {
    playerRect = { startX, startY, CELL_SIZE, CELL_SIZE };

    if (!loadTexture("Security.bmp")) {
        std::cerr << "Error loading texture for Security!" << std::endl;
    }
}

Security::Security(SDL_Renderer* renderer, Map* map, int startX, int startY)
    : renderer(renderer), map(map), characterTexture(nullptr), speed(4), health(100) {
    playerRect = { startX, startY, CELL_SIZE, CELL_SIZE };

    if (!loadTexture("Security.bmp")) {
        std::cerr << "Error loading texture for Security!" << std::endl;
    }
}

Security::~Security() {
    if (characterTexture) {
        SDL_DestroyTexture(characterTexture);
    }
}

void Security::MoveTo(const Uint8* keystate) {
    SDL_Rect oldRect = playerRect;

    if (keystate[SDL_SCANCODE_W]) {
        playerRect.y -= speed;
    }
    if (keystate[SDL_SCANCODE_S]) {
        playerRect.y += speed;
    }
    if (keystate[SDL_SCANCODE_A]) {
        playerRect.x -= speed;
    }
    if (keystate[SDL_SCANCODE_D]) {
        playerRect.x += speed;
    }

    playerRect.x = std::max(0, playerRect.x);
    playerRect.y = std::max(0, playerRect.y);
    playerRect.x = std::min(static_cast<int>(playerRect.x), static_cast<int>(map->getWidth() - playerRect.w));
    playerRect.y = std::min(static_cast<int>(playerRect.y), static_cast<int>(map->getHeight() - playerRect.h));
    if (map->checkCollision(playerRect)) {
        playerRect = oldRect;
    }
}

void Security::TakeDamage(int damage) {
    health -= damage;
    if (health < 0) {
        health = 0;
    }
}

bool Security::isAlive() const {
    return health > 0;
}

void Security::Update() {
    const Uint8* keystate = SDL_GetKeyboardState(nullptr);
    MoveTo(keystate);

    if (!isAlive()) {
        onDeath();
    }
}

void Security::Render() {
    if (characterTexture) {
        SDL_RenderCopy(renderer, characterTexture, nullptr, &playerRect);
    }
    else {
        std::cerr << "Character texture is not loaded!" << std::endl;
    }
}

void Security::onDeath() {
    std::cout << "Security character has died." << std::endl;
}

bool Security::loadTexture(const std::string& filename) {
    SDL_Surface* surface = SDL_LoadBMP(filename.c_str());
    if (!surface) {
        std::cerr << "Error loading texture: " << SDL_GetError() << std::endl;
        return false;
    }

    characterTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (!characterTexture) {
        std::cerr << "Error creating texture: " << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}
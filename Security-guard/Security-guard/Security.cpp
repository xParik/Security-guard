#include "Security.h"
#include "Game.h"

Security::Security(SDL_Renderer* renderer) : renderer(renderer),
    characterTexture(nullptr),
    playerRect{ 0, 0, CELL_SIZE, CELL_SIZE },
    speed(4),
    health(100) // Initialize health
{
    loadTexture("security.bmp");
}

Security::~Security() {
    SDL_DestroyTexture(characterTexture);
}

void Security::MoveTo(const Uint8* keystate) {
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
}

void Security::TakeDamage(int damage) {
    health -= damage;
}

bool Security::isAlive() {
    return health > 0;
}

void Security::Update() {
}

void Security::Render() {
    SDL_RenderCopy(renderer, characterTexture, nullptr, &playerRect);
}

bool Security::loadTexture(const std::string& filename) {
    SDL_Surface* surface = SDL_LoadBMP(filename.c_str());
    if (surface == nullptr) {
        std::cerr << "Error loading texture: " << SDL_GetError() << std::endl;
        return false;
    }

    characterTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (characterTexture == nullptr) {
        std::cerr << "Error creating texture: " << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}
#include "Security.h"
#include "Game.h" 
#include "Map.h"
#include <SDL.h> 
#include <iostream>
using namespace std;

Security::Security(SDL_Renderer* renderer, Map* map)
    : renderer(renderer),
    map(map),
    characterTexture(nullptr),
    playerRect{ 0, 0, CELL_SIZE, CELL_SIZE },
    speed(4),
    health(100)
{
    loadTexture("Security.bmp");
}

Security::~Security() {
    SDL_DestroyTexture(characterTexture);
}

void Security::MoveTo(const Uint8* keystate) {
    // ��������� ������ �������
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

    // ��������� ������������ ����� �����������
    if (map->checkCollision(playerRect)) {
        // ���� ������������, ������������ �� ������ �������
        playerRect = oldRect;
    }
}

void Security::TakeDamage(int damage) {
    health -= damage;
}

bool Security::isAlive() {
    return health > 0; // �������� return 
}

void Security::Update() {
    // �������� ��������� ������
    const Uint8* keystate = SDL_GetKeyboardState(nullptr);

    // ���������� ���������
    MoveTo(keystate);

}

bool Security::isAlive() {
    return health > 0;
}


void Security::Render() {
    SDL_RenderCopy(renderer, characterTexture, nullptr, &playerRect);
}

void Security::onDeath() {
    // ��������� �������� ��� ������ ���������
    // ��������, ���������� ����� ������
}

bool Security::loadTexture(const std::string& filename) {
    SDL_Surface* surface = SDL_LoadBMP(filename.c_str());
    if (surface == nullptr) {
        std::cerr << "Error loading texture: " << SDL_GetError() << endl;
        return false; // �������� return 
    }

    characterTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (characterTexture == nullptr) {
        std::cerr << "Error creating texture: " << SDL_GetError() << endl;
        return false; // �������� return 
    }

    return true;
}
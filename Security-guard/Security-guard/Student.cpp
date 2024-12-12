#include "Student.h"
#include "Map.h"
#include "Item.h"
#include <iostream>
#include "SDL.h"
using namespace std;
Student::Student(SDL_Renderer* renderer, Map* map)
    : renderer(renderer),
    map(map),
    characterTexture(nullptr),
    playerRect{ 0, 0, CELL_SIZE, CELL_SIZE },
    speed(4),
    health(100)
{
    loadTexture("Student.bmp");
}

void Student::MoveTo(const Uint8* keystate)
{
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

    if (map->checkCollision(playerRect)) {
        playerRect = oldRect;
    }
}

void Student::TakeDamage(int damage)
{
    health -= damage;
}
bool  Student::onDeath() {
    return health < 0;
}
bool Student::isAlive()
{
    return health > 0;
}

void Student::Update()
{
    // Получаем состояние клавиш
    const Uint8* keystate = SDL_GetKeyboardState(nullptr);

    // Перемещаем персонажа
    MoveTo(keystate);

    // Проверяем, жив ли персонаж
    if (!isAlive()) {
        onDeath(); // Вызываем onDeath(), если персонаж умер
    }
}

void Student::Render()
{
    SDL_RenderCopy(renderer, characterTexture, nullptr, &playerRect);
}

bool Student::loadTexture(const std::string& filename)
{
    SDL_Surface* surface = SDL_LoadBMP(filename.c_str());
    if (surface == nullptr) {
        cerr << "Error loading texture: " << SDL_GetError() << endl;
        return false;  
    }

    characterTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (characterTexture == nullptr) {
        cerr << "Error creating texture: " << SDL_GetError() << endl;
        return false; 
    }

    return true;
}

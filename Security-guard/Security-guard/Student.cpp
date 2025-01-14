#include "Map.h" 
#include "Student.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <SDL_image.h>

Student::Student(const std::string& name, int health, int startX, int startY, SDL_Renderer* renderer, Map* map)
    : name(name), health(health), renderer(renderer), map(map), characterTexture(nullptr), speed(4) {
    playerRect = { startX, startY, CELL_SIZE, CELL_SIZE };

    if (!loadTexture("Student.bmp")) {
        std::cerr << "Error loading texture for Student!" << std::endl;
    }
    std::string items[] = { "Dudka", "Knife", "Gun", "Snus" };
    item = items[rand() % (sizeof(items) / sizeof(items[0]))];
}

Student::Student(SDL_Renderer* renderer, Map* map)
    : renderer(renderer), map(map), characterTexture(nullptr), playerRect{ 0, 0, CELL_SIZE, CELL_SIZE }, speed(4), health(100) {
    if (!loadTexture("Student.bmp")) {
        std::cerr << "Error loading texture for Student!" << std::endl;
    }

    std::string items[] = { "Dudka", "Knife", "Gun", "Snus" };
    item = items[rand() % (sizeof(items) / sizeof(items[0]))];
}

Student::~Student() {
    if (characterTexture) {
        SDL_DestroyTexture(characterTexture);
    }
}

void Student::MoveTo(const Uint8* keystate) {
    if (keystate[SDL_SCANCODE_UP]) {
        playerRect.y -= speed;
    }
    if (keystate[SDL_SCANCODE_DOWN]) {
        playerRect.y += speed;
    }
    if (keystate[SDL_SCANCODE_LEFT]) {
        playerRect.x -= speed;
    }
    if (keystate[SDL_SCANCODE_RIGHT]) {
        playerRect.x += speed;
    }

    // ѕроверка на границы карты
    if (playerRect.x < 0) playerRect.x = 0;
    if (playerRect.x + playerRect.w > map->getWidth()) playerRect.x = map->getWidth() - playerRect.w;
    if (playerRect.y < 0) playerRect.y = 0;
    if (playerRect.y + playerRect.h > map->getHeight()) playerRect.y = map->getHeight() - playerRect.h;
}

void Student::Update() {
    // «десь можно добавить логику обновлени€ состо€ни€ студента (например, проверки на здоровье)
}

void Student::Render() {
    if (characterTexture) {
        SDL_RenderCopy(renderer, characterTexture, nullptr, &playerRect);
    }
}

// ћетод дл€ загрузки текстуры
bool Student::loadTexture(const std::string& filename) {
    SDL_Surface* tempSurface = IMG_Load(filename.c_str());
    if (!tempSurface) return false;

    characterTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    return characterTexture != nullptr;
}
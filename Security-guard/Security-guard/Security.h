#pragma once
#include <SDL.h>
#include <string>
#include "Map.h"
#include <iostream>
class Security
{
private:
    int Habit;
    int Endurance;
    std::string Name;
    int Age;
    bool Move;
    Map* map;
    int speed;
    int health;
    int onDeath;
    SDL_Rect playerRect;
    SDL_Texture* characterTexture;
    SDL_Renderer* renderer;
public:
    Security(const std::string& name, int habit, int endurance, int age, int health, int startX, int startY, Map* m) :
        Name(name), Age(age), Habit(habit), Endurance(endurance), health(health), Move(true), map(m) {
        // Инициализируем playerRect 
        playerRect.x = startX;
        playerRect.y = startY;
        playerRect.w = CELL_SIZE;
        playerRect.h = CELL_SIZE;
    }

    void SetName(const std::string& newName) {
        Name = newName;
    }
    std::string GetName() const {
        return Name;
    }

    Security(SDL_Renderer* renderer, Map* map) :
        renderer(renderer),
        map(map),
        characterTexture(nullptr),
        playerRect{ 0, 0, CELL_SIZE, CELL_SIZE },
        speed(4),
        health(100)
    {
        loadTexture("Security.bmp");
    }

    void MoveTo(const Uint8* keystate);
    void TakeDamage(int damage);
    bool isAlive();
    void Update();
    void Render();
    void const onDeath();
    bool const loadTexture(const std::string& filename);
    const int CELL_SIZE = 32;

    bool const loadTexture(const std::string& filename) {
        SDL_Surface* surface = SDL_LoadBMP(filename.c_str());
        if (surface == nullptr) {
            std::cout << "Error loading texture: " << SDL_GetError() << endl;
            return;
        }
        characterTexture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
        if (characterTexture == nullptr) {
            std::cerr << "Error creating texture: " << SDL_GetError() << endl;
            return;
        }
    }
};
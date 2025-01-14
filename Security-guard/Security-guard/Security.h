#pragma once
#include <SDL.h>
#include <string>
#include <iostream>
#include <algorithm> 

class Map; // Предварительное объявление класса Map

const int CELL_SIZE = 32; // Определение CELL_SIZE

class Security {
private:
    SDL_Renderer* renderer;
    SDL_Texture* characterTexture;
    SDL_Rect playerRect;
    int speed;
    int health;
    std::string name;
    int age;
    int habit;     
    int endurance; 
    Map* map;     

    bool loadTexture(const std::string& filename);

public:
    Security(const std::string& name, int habit, int endurance, int age, int health, int startX, int startY, Map* m);
    Security(SDL_Renderer* renderer, Map* map, int startX, int startY);
    ~Security();

    void MoveTo(const Uint8* keystate);
    void TakeDamage(int damage);
    bool isAlive() const;
    void Update();
    void Render();
    void onDeath();
};
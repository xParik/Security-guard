#pragma once
#include <SDL.h>
#include <string>
using namespace std;
class Student {
private:
    string name;
    int health;
    int speed;
    SDL_Rect playerRect;
    SDL_Texture* characterTexture;
    SDL_Renderer* renderer;
    Map* map;

    const int CELL_SIZE = 32;

public:
    // Конструктор 
    Student(const string& name, int health, int startX, int startY, SDL_Renderer* renderer, Map* map);

    void MoveTo(const Uint8* keystate);
    void TakeDamage(int damage);
    bool isAlive();
    void Update();
    void Render();
    bool  onDeath();
 
    string GetName() const { return name; }
    int GetHealth() const { return health; }

    Student(SDL_Renderer* renderer, Map* map) :
        renderer(renderer),
        map(map),
        characterTexture(nullptr),
        playerRect{ 0, 0, CELL_SIZE, CELL_SIZE },
        speed(4),
        health(100)
    {
        loadTexture("Student.bmp");
    }

    bool loadTexture(const string& filename) {
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
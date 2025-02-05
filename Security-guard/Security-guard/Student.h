#pragma once
#include <SDL.h>
#include <string>

class Map; // Предварительное объявление класса Map

class Student {
private:
    std::string name;
    int health;
    int speed;
    SDL_Rect playerRect;
    SDL_Texture* characterTexture;
    SDL_Renderer* renderer;
    Map* map;
    std::string item; // Новый член для хранения предмета

    const int CELL_SIZE = 32;

public:
    Student(const std::string& name, int health, int startX, int startY, SDL_Renderer* renderer, Map* map);
    Student(SDL_Renderer* renderer, Map* map);
    ~Student();

    void MoveTo(const Uint8* keystate);
    void TakeDamage(int damage);
    bool isAlive() const;
    void Update();
    void Render();
    bool onDeath() const;

    std::string GetName() const { return name; }
    int GetHealth() const { return health; }
    std::string GetItem() const { return item; } // Метод для получения предмета
    const SDL_Rect& GetRect() const {
        return playerRect;
    }
private:
    bool loadTexture(const std::string& filename);
};
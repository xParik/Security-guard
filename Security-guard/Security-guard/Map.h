#ifndef MAP_H
#define MAP_H

#include "SDL.h"
#include <vector>
#include <string>

class Student;

class Map {
private:
    static const int MAP_HEIGHT = 10;
    static const int MAP_WIDTH = 20;
    static const int CELL_SIZE = 64;

    static int mapData[MAP_HEIGHT][MAP_WIDTH]; 
    SDL_Renderer* renderer;
    SDL_Rect guardRect;
    std::vector<Student> students;
    int width;
    int height;

    void drawCell(int x, int y, int type);
    void renderGuard(SDL_Renderer* renderer);
    void renderStudents(SDL_Renderer* renderer);

public:
    Map(SDL_Renderer* renderer);
    ~Map();

    void draw();
    void spawnRandomStudents(int count);
    bool checkCollision(const SDL_Rect& rect);
    int getWidth() const { return MAP_WIDTH; }
    int getHeight() const { return MAP_HEIGHT; }
};

#endif
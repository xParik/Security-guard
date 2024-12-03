#ifndef MAP_H
#define MAP_H
#include <SDL.h>
class Map {
private:
    SDL_Renderer* renderer; 
    const int MAP_HEIGHT = 10;
    const int MAP_WIDTH = 10;
    int const mapData[10][10] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 3, 1, 1, 1, 3, 1, 0, 1, 1},
        {1, 0, 3, 0, 1, 0, 3, 0, 0, 1},
        {1, 1, 1, 0, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 3, 1, 1, 0, 1},
        {1, 3, 1, 1, 1, 1, 1, 1, 2, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };
    const int CELL_SIZE = 32;
    Map();
    void renderer();
    void const drawCell(int x, int y, int type);
public:
    Map(SDL_Renderer* renderer);
    void draw();
    bool checkCollision(SDL_Rect playerRect);
    ~Map();
};
#endif
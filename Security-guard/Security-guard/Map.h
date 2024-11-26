#pragma once
#include <SDL.h>

class Map {
private:
    const SDL_Renderer* renderer; //  renderer  теперь константа 
    const int MAP_HEIGHT = 10;
    const int MAP_WIDTH = 10;
    int mapData[MAP_HEIGHT][MAP_WIDTH] = {
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

    // drawCell  теперь не-const
    void drawCell(int x, int y, int type);

public:
    Map(const SDL_Renderer* renderer); //  renderer  теперь константа 
    bool checkCollision(SDL_Rect rect) const;
    void render() const;
};
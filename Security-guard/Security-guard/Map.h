#pragma once
#include <SDL.h>
#include "Security.h"
using namespace std;

class Map {
private:
    SDL_Renderer* renderer;
    const int MAZE_HEIGHT = 10;
    const int MAZE_WIDTH = 10;
    int mazeData[MAZE_HEIGHT][MAZE_WIDTH] = {
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
    void drawCell(int x, int y, int type) const;
public:
    Map(SDL_Renderer* renderer);
    bool checkCollision(SDL_Rect rect) const;
    void render() const;
};
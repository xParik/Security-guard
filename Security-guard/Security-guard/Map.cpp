#include "Map.h"
#include <SDL.h>

Map::Map(SDL_Renderer* renderer) : renderer(renderer) {}
void Map::render() const {
    for (int y = 0; y < MAZE_HEIGHT; y++) {
        for (int x = 0; x < MAZE_WIDTH; x++) {
            drawCell(x, y, mazeData[y][x]);
        }
    }
}

bool Map::checkCollision(SDL_Rect rect) const {
    int left = rect.x;
    int top = rect.y;
    int right = rect.x + rect.w;
    int bottom = rect.y + rect.h;
    int gridX1 = left / CELL_SIZE;
    int gridY1 = top / CELL_SIZE;
    int gridX2 = right / CELL_SIZE;
    int gridY2 = top / CELL_SIZE;
    int gridX3 = left / CELL_SIZE;
    int gridY3 = bottom / CELL_SIZE;
    int gridX4 = right / CELL_SIZE;
    int gridY4 = bottom / CELL_SIZE;

    if (gridX1 < 0 || gridX1 >= MAZE_WIDTH || gridY1 < 0 || gridY1 >= MAZE_HEIGHT ||
        gridX2 < 0 || gridX2 >= MAZE_WIDTH || gridY2 < 0 || gridY2 >= MAZE_HEIGHT ||
        gridX3 < 0 || gridX3 >= MAZE_WIDTH || gridY3 < 0 || gridY3 >= MAZE_HEIGHT ||
        gridX4 < 0 || gridX4 >= MAZE_WIDTH || gridY4 < 0 || gridY4 >= MAZE_HEIGHT) {
        return true; 
    }

    for (int y = gridY1; y <= gridY4; y++) {
        for (int x = gridX1; x <= gridX4; x++) {
            if (x >= 0 && x < MAZE_WIDTH && y >= 0 && y < MAZE_HEIGHT && mazeData[y][x] == 1) {
                return true;
            }
        }
    }
    return false; 
}
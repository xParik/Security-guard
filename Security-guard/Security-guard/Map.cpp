#include "Map.h"
#include <SDL.h>

void Map::render() const {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            drawCell(x, y, mapData[y][x]);
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

    if (gridX1 < 0 || gridX1 >= MAP_WIDTH || gridY1 < 0 || gridY1 >= MAP_HEIGHT ||
        gridX2 < 0 || gridX2 >= MAP_WIDTH || gridY2 < 0 || gridY2 >= MAP_HEIGHT ||
        gridX3 < 0 || gridX3 >= MAP_WIDTH || gridY3 < 0 || gridY3 >= MAP_HEIGHT ||
        gridX4 < 0 || gridX4 >= MAP_WIDTH || gridY4 < 0 || gridY4 >= MAP_HEIGHT) {
        return true; 
    }

    for (int y = gridY1; y <= gridY3; y++) {
        for (int x = gridX1; x <= gridX3; x++) {
            if (mapData[y][x] == 1) { 
                return true;
            }
        }
    }
    return false; 
}
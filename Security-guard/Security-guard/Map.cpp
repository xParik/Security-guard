#include "Map.h"
#include <SDL.h>
#include "Student.h"
#include <cstdlib>
#include <ctime>

int Map::mapData[MAP_HEIGHT][MAP_WIDTH] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

Map::Map(SDL_Renderer* renderer)
    : renderer(renderer), width(MAP_WIDTH), height(MAP_HEIGHT) {
    srand(static_cast<unsigned>(time(0)));
    guardRect = { 1 * CELL_SIZE, 1 * CELL_SIZE, CELL_SIZE, CELL_SIZE };
}

Map::~Map() {}

void Map::drawCell(int x, int y, int type) {
    SDL_Rect cellRect = { x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE };
    switch (type) {
    case 0:
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        break;
    case 1:
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        break;
    case 2:
        SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
        break;
    }
    SDL_RenderFillRect(renderer, &cellRect);
}

void Map::draw() {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            drawCell(x, y, mapData[y][x]);
        }
    }
    renderGuard(renderer);
    renderStudents(renderer);
}


void Map::renderGuard(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &guardRect);
}

void Map::spawnRandomStudents(int count) {
    for (int i = 0; i < count; ++i) {
        int startX, startY;
        do {
            startX = rand() % width;
            startY = 1; 
        } while (mapData[startY][startX] != 0); 


        students.emplace_back("Student" + std::to_string(i + 1), 100, startX * CELL_SIZE, startY * CELL_SIZE, renderer, this);
    }
}

void Map::renderStudents(SDL_Renderer* renderer) {
    for (Student& student : students) {
        student.Render();
    }
}

bool Map::checkCollision(const SDL_Rect& playerRect) {
    for (const Student& student : students) {
        if (SDL_HasIntersection(&playerRect, &student.GetRect())) {
            return true;
        }
    }
    return false;
}
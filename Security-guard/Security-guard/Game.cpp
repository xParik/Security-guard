#include "Game.h"
#include "Security.h" 
#include <iostream>

Game::Game() : window(nullptr), renderer(nullptr) {
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Maze Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1020, 800, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer) {
        std::cerr << "Ошибка создания рендерера: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }

    Security* security = new Security(renderer, &Map, 0, 0);
}

Game::~Game()
{
}

void Game::Initialize()
{
}

void Game::Update()
{
}

void Game::Render()
{
}

void Game::HandleEvents()
{
}

void Game::AddStudent(Student* student)
{
}

void Game::AddSecurity(Security* security)
{
}

void Game::AddItem(Item* item)
{
}

void Game::AddHabit(Habit* habit)
{
}

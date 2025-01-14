#include "Game.h"

Game::Game() : window(nullptr), renderer(nullptr) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Main Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 640, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer) {
        std::cerr << "Ошибка создания рендерера: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }
}

Game::~Game()
{

}

void Game::run() {}

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

#include "Game.h"
#include <vector>
#include <iostream>
#include <SDL_image.h>

Game::Game() : window(nullptr), renderer(nullptr) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Ошибка инициализации SDL: " << SDL_GetError() << std::endl;
        return;
    }

    window = SDL_CreateWindow("Main Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 640, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Ошибка создания окна: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Ошибка создания рендерера: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }
}

bool Game::LoadTexture(const std::string& filePath) {
    SDL_Surface* tempSurface = SDL_LoadBMP("Menu.bmp");
    if (!tempSurface) {
        cerr << "Ошибка загрузки изображения" << SDL_GetError() << endl;
    }
    else {
        texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
        SDL_FreeSurface(tempSurface);
    }
    texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    if (!texture) {
        std::cerr << "Ошибка создания текстуры: " << SDL_GetError() << std::endl;
        return false;
    }
    return true;
}

void Game::RenderTexture() {
    if (texture) {
        SDL_RenderCopy(renderer, texture, nullptr, nullptr);
    }
}

Game::~Game() {
    if (texture) {
        SDL_DestroyTexture(texture);
    }
    if (renderer) {
        SDL_DestroyRenderer(renderer);
    }
    if (window) {
        SDL_DestroyWindow(window);
    }
    SDL_Quit();
}

void Game::run() {
    bool running = true;
    SDL_Event e;

    Initialize();

    while (running) {
        HandleEvents(e, running);

        Update();

        Render();
    }
}

void Game::Initialize() {
    // Инициализация игровых объектов (например, студенты, охрана, предметы и привычки)
    std::cout << "Инициализация игры..." << std::endl;
}

void Game::Update() {
    // Обновление состояния всех игровых объектов
    std::cout << "Обновление игры..." << std::endl;
}

void Game::Render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    RenderTexture(); // Отрисовка текстуры

    SDL_RenderPresent(renderer);
}

void Game::HandleEvents(SDL_Event& e, bool& running) {
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            running = false;
        }
    }
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

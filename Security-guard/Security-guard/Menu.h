#pragma once
#include <SDL.h>
#include <vector>
#include <string>
#include <iostream>
#include <SDL_ttf.h> // Не забудьте включить TTF заголовки
using namespace std;

class Menu {
private:
    SDL_Renderer* renderer;
    SDL_Texture* menuTexture;
    vector<SDL_Rect> itemRects;
    vector<string> itemTexts;
    int selectedItemIndex;

public:
    Menu(SDL_Renderer* renderer);
    ~Menu();

    void AddMenuItem(const string& text, int x, int y);
    void Draw();
    void HandleInput(const SDL_Event& event);
    bool IsMenuItemSelected(int index);
    bool loadTexture(const string& filename);
    SDL_Surface* createTextSurface(const string& text, SDL_Color color);

    void initMenuItems(); // Новый метод для инициализации пунктов меню
};
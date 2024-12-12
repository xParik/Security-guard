#pragma once
#include <SDL.h>
#include <vector>
#include <string>

class Menu {
public:
    Menu(SDL_Renderer* renderer);
    ~Menu();

    void AddMenuItem(const std::string& text, int x, int y);

    void Draw();
    void HandleInput(const SDL_Event& event);

    bool IsMenuItemSelected(int index);

private:
    SDL_Renderer* renderer;
    SDL_Texture* menuTexture;
    std::vector<SDL_Rect> itemRects;
    std::vector<std::string> itemTexts;
    int selectedItemIndex;

    bool loadTexture(const std::string& filename);
    SDL_Surface* createTextSurface(const std::string& text, SDL_Color color);
};
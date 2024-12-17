#include "Menu.h"
#include <SDL_ttf.h>
#include <iostream>
using namespace std;
Menu::Menu(SDL_Renderer* renderer) :
    renderer(renderer),
    menuTexture(nullptr),
    selectedItemIndex(-1)
{
    // Загружаем шрифт
    if (TTF_Init() == -1) {
        cerr << "TTF_Init Error: " << TTF_GetError() << endl;
        return;
    }
}

Menu::~Menu() {
    SDL_DestroyTexture(menuTexture);
    TTF_Quit();
}

void Menu::AddMenuItem(const string& text, int x, int y) {
    itemTexts.push_back(text);
    SDL_Rect rect = { x, y, 0, 0 };
    itemRects.push_back(rect);
}

void Menu::Draw() {
    if (menuTexture != nullptr) {
        SDL_RenderCopy(renderer, menuTexture, nullptr, nullptr);
    }

    for (size_t i = 0; i < itemTexts.size(); ++i) {
        SDL_Surface* textSurface = createTextSurface(itemTexts[i], { 255, 255, 255 }); 
        SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        SDL_FreeSurface(textSurface);

        if (textTexture == nullptr) {
            cerr << "Error creating text texture: " << SDL_GetError() << endl;
        }
        else {
            int textWidth, textHeight;
            SDL_QueryTexture(textTexture, nullptr, nullptr, &textWidth, &textHeight);
            itemRects[i].w = textWidth;
            itemRects[i].h = textHeight;
            SDL_RenderCopy(renderer, textTexture, nullptr, &itemRects[i]);
            SDL_DestroyTexture(textTexture);
        }
    }
}

void Menu::HandleInput(const SDL_Event& event) {
    if (event.type == SDL_MOUSEMOTION) {
        for (size_t i = 0; i < itemRects.size(); ++i) {
            if (SDL_PointInRect(&event.motion.point, &itemRects[i])) {
                selectedItemIndex = i;
                break;
            }
            else {
                selectedItemIndex = -1;
            }
        }
    }
    else if (event.type == SDL_MOUSEBUTTONDOWN) {
        if (selectedItemIndex != -1) {
            cout << "Выбран пункт: " << itemTexts[selectedItemIndex] << endl;
        }
    }
}

bool Menu::IsMenuItemSelected(int index) {
    return selectedItemIndex == index;
}

bool Menu::loadTexture(const string& filename) {
    SDL_Surface* surface = SDL_LoadBMP(filename.c_str());
    if (surface == nullptr) {
        cout << "Error loading texture: " << SDL_GetError() << endl;
        return false;
    }
    menuTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (menuTexture == nullptr) {
        cerr << "Error creating texture: " << SDL_GetError() << endl;
        return false;
    }
    return true;
}

SDL_Surface* Menu::createTextSurface(const string& text, SDL_Color color) {
    TTF_Font* font = TTF_OpenFont("arial.ttf", 24); //шрифт
    if (font == nullptr) {
        cerr << "Error loading font: " << TTF_GetError() << endl;
        return nullptr;
    }

    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
    TTF_CloseFont(font);

    if (surface == nullptr) {
        cerr << "Error rendering text: " << TTF_GetError() << endl;
        return nullptr;
    }

    return surface;
}
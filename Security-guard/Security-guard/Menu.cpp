#include "Menu.h"

Menu::Menu(SDL_Renderer* renderer) :
    renderer(renderer),
    menuTexture(nullptr),
    selectedItemIndex(-1)
{
    if (TTF_Init() == -1) {
        cerr << "TTF_Init Error: " << TTF_GetError() << endl;
        return;
    }
    initMenuItems(); 
}

Menu::~Menu() {
    SDL_DestroyTexture(menuTexture); 
    TTF_Quit(); 
}

void Menu::initMenuItems() {
    AddMenuItem("������ ����� ����", 100, 100);
    AddMenuItem("���������� ����", 100, 150);
    AddMenuItem("���������", 100, 200);
    AddMenuItem("�����", 100, 250);
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
        if (textSurface != nullptr) {
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
}

void Menu::HandleInput(const SDL_Event& event) {
    if (event.type == SDL_MOUSEMOTION) {
        SDL_Point mousePoint = { event.motion.x, event.motion.y };

        for (size_t i = 0; i < itemRects.size(); ++i) {
            if (SDL_PointInRect(&mousePoint, &itemRects[i])) {
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
            cout << "������ �����: " << itemTexts[selectedItemIndex] << endl;

            switch (selectedItemIndex) {
            case 0:
                cout << "������ ����� ����..." << endl;
                break;
            case 1:
                cout << "����������� ����..." << endl;
                break;
            case 2:
                cout << "���������..." << endl;
                break;
            case 3:
                cout << "����� �� ����..." << endl;
                break;
            default:
                break;
            }
        }
    }
}

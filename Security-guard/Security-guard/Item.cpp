#include "Item.h"
#include <SDL.h>
#include <iostream>
#include "Map.cpp"

Item::Item(const string& name,
    const string& description,
    const string* allowedEffects,
    int numAllowedEffects,
    const string* prohibitedEffects,
    int numProhibitedEffects) :
    name(name),
    description(description),
    numAllowedEffects(numAllowedEffects),
    numProhibitedEffects(numProhibitedEffects) {}

string Item::getName() const {
    return name;
}

string Item::getDescription() const {
    return description;
}

const string* Item::getAllowedEffects() const {
    return allowedEffects;
}

int Item::getNumAllowedEffects() const {
    return numAllowedEffects;
}

const string* Item::getProhibitedEffects() const {
    return prohibitedEffects;
}

int Item::getNumProhibitedEffects() const {
    return numProhibitedEffects;
}

void Item::draw(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

    SDL_Rect rect;
    rect.x = 100;
    rect.y = 100;
    rect.w = CELL_SIZE;
    rect.h = CELL_SIZE;

    SDL_RenderFillRect(renderer, &rect);

}
#pragma once
#include <string>
#include "SDL.h"
using namespace std;

class Habit
{
private:
	string name;
	string description;
	int healthEffect;
	int staminaEffect;
	SDL_Texture* texture;
public:
	Habit(const string& name, const string& description, SDL_Texture* texture, int healthEffect, int staminaEffect);
	~Habit();
	void render(SDL_Renderer* renderer, int x, int y);
	string getName() const;
	string Effect(int& health, int& stamina) const;
};
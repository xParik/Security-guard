#pragma once
#include <SDL.h>
#include <string>
#include "Map.h"
class Security
{
private:
	int Habit;
	int Endurance;
	std::string Name;
	int Age;
	bool Move;
	int Health;
	Map* map;;
public:
	Security(const std::string& name, int habit, int endurance, int age, int health, int startX, int startY, Map* m) :
		Name(name), Age(age), Habit(habit), Endurance(endurance), Health(health), Move(true) {}
	void SetName(const std::string& newName) {
		Name = newName;
		
	}
	std::string GetName() const {
			return Name;
	}
	void MoveTo(const Uint8* keystate);
	void TakeDamage(int damage);
	bool isAlive();
	void Update();
	void Render(SDL_Renderer * renderer);
	SDL_Rect rect;
};


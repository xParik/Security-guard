#pragma once
#include <SDL.h>
#include <string>
class Security
{
private:
	int Habit;
	int Endurance;
	std::string Name;
	int Age;
	bool Move;
	int Health;
public:
	Security(const std::string& name, int habit, int endurance, int age, int health) :
		Name(name), Age(age), Habit(habit), Endurance(endurance), Health(health), Move(true) {}
	void SetName(const std::string& newName) {
		Name = newName;
		
	}
	std::string GetName() const {
			return Name;
	}
	void MoveTo(int x, int y);
	void TakeDamage(int damage);
	bool isAlive();
	void Update();
	void Render(SDL_Renderer* renderer);
};


#pragma once
#include "Item.h"
#include "Security.h"
#include "Habit.h"
#include "Student.h"
#include <SDL.h>
#include <vector>
class Game
{
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	vector <Student*> students;
	vector <Security*> securitys;
	vector <Habit*> habits;
	vector <Item*> items;
public:
	Game();
	~Game();
	void Initialize();
	void Update();
	void Render();
	void HandleEvents();
	SDL_Window* GetWindow() const {
		return window;
	}
	SDL_Renderer* GetRenderer() const {
		return renderer;
	}
	const vector <Student*>& GetStudents() const {
		return students;
	}
	const vector <Security*>& GetSecuritys() const {
		return securitys;
	}
	const vector <Habit*>& GetHabits() const {
		return habits;
	}
	const vector <Item*>& GetItems() const {
		return items;
	}
	void AddStudent(Student* student);
	void AddSecurity(Security* security);
	void AddItem(Item* item);
	void AddHabit(Habit* habit);
};


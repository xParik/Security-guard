#pragma once
#include <string>
#include <SDL.h>
using namespace std;
class Habit
{
private:
	string Name;
	int Positivequalities;
	int Negativequalities;
public:
	Habit(const string& name, int positivequalities, int negativequalities) :
		Name(name), Positivequalities(positivequalities), Negativequalities(negativequalities) {}

	string getName() const {
		return Name;
	}
	int getPositivequalities() const {
		return Positivequalities;
	}
	int getNegativequalities() const {
		return Negativequalities;
	}
	void setName(const string& newName) {
		Name = newName;
	}
	void displayHabitInfo() const {}
	void setPositivequalities(int newPositivequalities) {
		Positivequalities = newPositivequalities;
	}
	void setNegativequalities(int newNegativequalities) {
		Negativequalities = newNegativequalities;
	}
	int getBalance() const {
		return Positivequalities - Negativequalities;
	}
};


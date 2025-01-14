#include "Habit.h"
#include <iostream>
#include <string>

Habit::Habit (const string& name, int positivequalities, int negativequalities) :	
	Name(name), Positivequalities(positivequalities), Negativequalities(negativequalities) {}

string Habit::getName() const {
    return Name;
}

int Habit::getPositivequalities() const {
    return Positivequalities;
}

int Habit::getNegativequalities() const {
    return Negativequalities;
}

void Habit::setName(const std::string& newName) {
    Name = newName;
}

void Habit::setPositivequalities(int newPositiveQualities) {
    Positivequalities = newPositiveQualities;
}

void Habit::setNegativequalities(int newNegativeQualities) {
    Negativequalities = newNegativeQualities;
}

void Habit::displayHabitInfo() const {
    cout << "Habit Name: " << Name << std::endl;
    cout << "Positive Qualities: " << Positivequalities << std::endl;
    cout << "Negative Qualities: " << Negativequalities << std::endl;
}
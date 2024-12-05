#include "Item.h"
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

Item::Item(const string& name, const string& description,
	const string* allowedEffects, int numAllowedEffects,
	const string* prohibitedEffects, int numProhibitedEffects,
	bool isTaken) :
	name(name), description(description),
	numAllowedEffects(numAllowedEffects), numProhibitedEffects(numProhibitedEffects), isTaken(false) {
	allowedEffects = new string[numAllowedEffects];
	prohibitedEffects = new string[numProhibitedEffects];
}

bool Item::takeItem() {
	if (!isTaken) {
		isTaken = true;
		cout << "You took the item" << name << endl;
		return true;
	}
	else {
		cout << "You have already taken the item" << name << endl;
		return false;
	}
}

bool Item::leaveItem() {
	if (!isTaken) {
		isTaken = false;
		cout << "You left the item" << name << endl;
		return true;
	}
	else {
		cout << "You haven't selected the item" << name << endl;
	}
}

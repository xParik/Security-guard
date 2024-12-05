#pragma once
#include <SDL.h>
#include <string>
using namespace std;

class Item {
private:
    string name;
    string description;
    string* allowedEffects; 
    string* prohibitedEffects;
    int numAllowedEffects;
    int numProhibitedEffects;
    bool isTaken;

public:
    Item(const string& name, const string& description,
        const string* allowedEffects, int numAllowedEffects,
        const string* prohibitedEffects, int numProhibitedEffects,
        bool isTaken) :
        name(name), description(description),
        numAllowedEffects(numAllowedEffects), numProhibitedEffects(numProhibitedEffects),isTaken(isTaken) {
        this->allowedEffects = new string[numAllowedEffects];
        this->prohibitedEffects = new string[numProhibitedEffects];

        for (int i = 0; i < numAllowedEffects; ++i) {
            this->allowedEffects[i] = allowedEffects[i];
        }
        for (int i = 0; i < numProhibitedEffects; ++i) {
            this->prohibitedEffects[i] = prohibitedEffects[i];
        }
    }

    ~Item() {
        delete[] allowedEffects;
        delete[] prohibitedEffects;
    }

    Item& operator=(const Item& other);

    bool takeItem();
    bool leaveItem();

    string getName() const { return name; }
    string getDescription() const { return description; }
    const string* getAllowedEffects() const { return allowedEffects; }
    int getNumAllowedEffects() const { return numAllowedEffects; }
    const string* getProhibitedEffects() const { return prohibitedEffects; }
    int getNumProhibitedEffects() const { return numProhibitedEffects; }
};
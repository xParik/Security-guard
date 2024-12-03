#pragma once
#include <SDL.h>
#include <string>
#include "Map.h"
#include <iostream>
using namespace std;
class Item {
public:
    string name;
    string description;
    string allowedEffects[10];
    string prohibitedEffects[10];
    int numAllowedEffects;
    int numProhibitedEffects;

    Item(const string& name,
        const string& description,
        const string* allowedEffects,
        int numAllowedEffects,
        const string* prohibitedEffects,
        int numProhibitedEffects) :
        name(name),
        description(description),
        numAllowedEffects(numAllowedEffects),
        numProhibitedEffects(numProhibitedEffects)
    {
        for (int i = 0; i < numAllowedEffects; i++) {
            this->allowedEffects[i] = allowedEffects[i];
        }
        for (int i = 0; i < numProhibitedEffects; i++) {
            this->prohibitedEffects[i] = prohibitedEffects[i];
        }
    }

    string getName() const {
        return name;
    }

    string getDescription() const {
        return description;
    }

    const string* getAllowedEffects() const {
        return allowedEffects;
    }

    int getNumAllowedEffects() const {
        return numAllowedEffects;
    }

    const string* getProhibitedEffects() const {
        return prohibitedEffects;
    }

    int getNumProhibitedEffects() const {
        return numProhibitedEffects;
    }
};
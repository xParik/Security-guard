#include "Item.h"
#include <iostream>
#include <string>

Item::Item(const string& name, const string& description,
    const string* allowedEffects, int numAllowedEffects,
    const string* prohibitedEffects, int numProhibitedEffects) :
    name(name), description(description),
    numAllowedEffects(numAllowedEffects), numProhibitedEffects(numProhibitedEffects) {}


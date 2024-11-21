#pragma once
#include <SDL.h>
#include "Map.h"
class Student
{
private:
	int ID;
	int Status;
	int Item;
public:
	Student(int ID, int Status, int Item) :
		ID(ID), Status(Status), Item(Item) {}
	int getID() const { return ID; }
	int getStatus() const { return Status; }
	int getItem() const { return Item; }
	void setStatus(int newStatus) { 
		Status = newStatus;
	}
	void setItem(int newItem) {
		Item = newItem;
	}
};


#pragma once
#include "Command.h"
class HandgrenadeCommand :
	public Command
{
private:
	vector<Room*> visitedRooms;
	map<Room*, Room::Direction> doorways;
public:
	HandgrenadeCommand();
	~HandgrenadeCommand();
	void Run(list<string>* parameters, Game* game);
	void GetMinimunEdge();
	void CollapseDoorways(Room* startRoom, int amount);
};


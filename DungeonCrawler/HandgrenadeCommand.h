#pragma once
#include "Command.h"
class HandgrenadeCommand :
	public Command
{
private:
	map<Room*, Room::Direction> doorways;
	vector<Room*> visitedRooms;
public:
	HandgrenadeCommand();
	~HandgrenadeCommand();
	void Run(list<string>* parameters, Game* game);
	void GetMinimunEdge();
	void CollapseDoorways(int amount);
};


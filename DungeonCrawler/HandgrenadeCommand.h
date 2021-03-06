#pragma once
#include "Command.h"
class HandgrenadeCommand :
	public Command
{
private:
	vector<Room*> visitedRooms;
	map<Room*, vector<Room::Direction>> doorways;
public:
	HandgrenadeCommand();
	~HandgrenadeCommand();
	void Run(list<string>* parameters, Game* game);
	void GetMinimunEdge();
	bool CollapseDoorways(Room* startRoom, int amount);
};


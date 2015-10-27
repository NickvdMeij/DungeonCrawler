#pragma once
#include "Command.h"
#include "Room.h"

class GoCommand : public Command
{
private:
	map<string, Room::Direction> directions;
public:
	GoCommand();
	~GoCommand();
	void Run(list<string>* parameters, Game* game);
};


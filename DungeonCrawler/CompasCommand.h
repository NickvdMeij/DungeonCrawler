#pragma once
#include "Command.h"
#include <vector>
#include <map>
#include "RandomInt.h"

class CompasCommand :
	public Command
{
private:
	vector<Room*> settledRooms;
	vector<Room*> unsettledRooms;
	map<Room*, Room*> predecessors;
	map<Room*, int> distance;
	RandomInt rnd;
public:
	CompasCommand();
	~CompasCommand();
	void Run(list<string>* parameters, Game* game);
	Room* getMinimum(vector<Room*> unsettledRooms);
	void findMinimalDistances(Room* room);
	int getShortestDistance(Room* room);
	bool isSettled(Room* room);
	int getDifficulty(Room* room);
	vector<Room*> getNeighbors(Room* room);

	void getPath(Room * stairRoom);

};


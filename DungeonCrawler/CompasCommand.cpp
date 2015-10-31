#include "stdafx.h"
#include "CompasCommand.h"
#include <sstream>



CompasCommand::CompasCommand()
{
}


CompasCommand::~CompasCommand()
{
}

void CompasCommand::Run(list<string>* parameters, Game * game)
{
	Room* startRoom = game->getPlayer()->getCurrentRoom();
	distance.insert(std::pair<Room*, int>(startRoom, 0));
	unsettledRooms.push_back(startRoom);
	while (!unsettledRooms.empty()) {
		Room* room = getMinimum(unsettledRooms);
		settledRooms.push_back(room);

		for (int i = 0; i < unsettledRooms.size(); i++) { //remove room from unsettledRooms
			if (unsettledRooms[i] == room) {
				unsettledRooms.erase(unsettledRooms.begin() + i);
			}
		}

		findMinimalDistances(room);
	}

	getPath(game->getLevel()->getStairRoom());
}

Room * CompasCommand::getMinimum(vector<Room*> unsettledRooms)
{
	Room* minimum = nullptr;
	for (Room* room : unsettledRooms) {
		if (minimum == nullptr) {
			minimum = room;
		}
		else {
			if (getShortestDistance(room) < getShortestDistance(minimum)) {
				minimum = room;
			}
		}
	}
	return minimum;
}

void CompasCommand::findMinimalDistances(Room * room)
{
	vector<Room*> adjecentRooms = getNeighbors(room);
	for (Room* adjecent : adjecentRooms) {
		if (getShortestDistance(adjecent) > getShortestDistance(room) + getDifficulty(adjecent)) {
			distance.insert(std::pair<Room*, int>(adjecent, getShortestDistance(room) + getDifficulty(adjecent)));
			predecessors.insert(std::pair<Room*, Room*>(adjecent, room));
			unsettledRooms.push_back(adjecent);
		}
	}
}

int CompasCommand::getShortestDistance(Room * room)
{
	int d = distance[room];
	if (d == NULL) {
		return 200000; //max value
	}
	else {
		return d;
	}
}

bool CompasCommand::isSettled(Room * room)
{
	return find(settledRooms.begin(), settledRooms.end(), room) != settledRooms.end();
}


//normaal lengte van edge. maar bij ons difficulty van kamer
int CompasCommand::getDifficulty(Room * room)
{
	return room->getDifficulty();
}

vector<Room*> CompasCommand::getNeighbors(Room * room)
{
	return room->GetAdjecentRooms();
}

void CompasCommand::getPath(Room * stairRoom)
{
	vector<Room*> path;
	vector<std::string> directions;
	Room* step = stairRoom;

	// check of stairRoom wel in predecessors zit
	if (predecessors.find(stairRoom) != predecessors.end()) {
		path.push_back(stairRoom);

		//werk hashmap terug vanuit stairRoom
		while (predecessors.find(step) != predecessors.end()) {
			step = predecessors[step];
			path.push_back(step);
		}

		for (int i = path.size(); i > 0; --i) {
			if (i > 0) {
				Room* to = path[i];
				Room* from = path[i - 1];

				if (from->GetXPosition() < to->GetXPosition()) {
					directions.push_back("East");
				}
				else if (from->GetXPosition() > to->GetXPosition()) {
					directions.push_back("West");
				}
				else if (from->GetYPosition() > to->GetYPosition()) {
					directions.push_back("South");
				}
				else if (from->GetYPosition() < to->GetYPosition()) {
					directions.push_back("North");
				}
			}
		}

		for (int i = directions.size(); i > 0; --i) {
			std::cout << directions[i] << " - " << endl;
		}
	}
	
}


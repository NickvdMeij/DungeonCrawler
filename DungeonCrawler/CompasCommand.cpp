#include "stdafx.h"
#include "CompasCommand.h"



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
		settledRooms.push_back(startRoom);

		for (int i = 0; i < unsettledRooms.size(); i++) { //remove room from unsettledRooms
			if (unsettledRooms[i] == room) {
				unsettledRooms.erase(unsettledRooms.begin() + i);
			}
		}

		findMinimalDistances(room);
	}
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


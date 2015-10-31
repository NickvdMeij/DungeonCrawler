#include "stdafx.h"
#include "CompasCommand.h"
#include <sstream>
#include <limits.h>

CompasCommand::CompasCommand()
{
}


CompasCommand::~CompasCommand()
{
}

void CompasCommand::Run(list<string>* parameters, Game * game)
{
	distance.clear();
	unsettledRooms.clear();
	settledRooms.clear();
	predecessors.clear();

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
	/*vector<Room*> adjecentRooms = getNeighbors(room);
	for (Room* adjecent : adjecentRooms) {
		if (getShortestDistance(adjecent) > getShortestDistance(room) + getWeight(adjecent)) {
			distance.insert(std::pair<Room*, int>(adjecent, getShortestDistance(room) + getWeight(adjecent)));
			predecessors.insert(std::pair<Room*, Room*>(adjecent, room));
			unsettledRooms.push_back(adjecent);
		}
	}*/

	if (room->DoesRoomHaveDoorway(Room::Direction::North)) {
		Room* adjecent = room->GetAdjecentRoom(Room::Direction::North);
		if (!isSettled(adjecent) && getShortestDistance(adjecent) > getShortestDistance(room) + room->getWeigthDoorway(Room::Direction::North)) {
			distance.insert(std::pair<Room*, int>(adjecent, getShortestDistance(room) + room->getWeigthDoorway(Room::Direction::North)));
			predecessors.insert(std::pair<Room*, Room*>(adjecent, room));
			unsettledRooms.push_back(adjecent);
		}
	}
	if (room->DoesRoomHaveDoorway(Room::Direction::East)) {
		Room* adjecent = room->GetAdjecentRoom(Room::Direction::East);
		if (!isSettled(adjecent) && getShortestDistance(adjecent) > getShortestDistance(room) + room->getWeigthDoorway(Room::Direction::East)) {
			distance.insert(std::pair<Room*, int>(adjecent, getShortestDistance(room) + room->getWeigthDoorway(Room::Direction::East)));
			predecessors.insert(std::pair<Room*, Room*>(adjecent, room));
			unsettledRooms.push_back(adjecent);
		}
	}
	if (room->DoesRoomHaveDoorway(Room::Direction::South)) {
		Room* adjecent = room->GetAdjecentRoom(Room::Direction::South);
		if (!isSettled(adjecent) && getShortestDistance(adjecent) > getShortestDistance(room) + room->getWeigthDoorway(Room::Direction::South)) {
			distance.insert(std::pair<Room*, int>(adjecent, getShortestDistance(room) + room->getWeigthDoorway(Room::Direction::South)));
			predecessors.insert(std::pair<Room*, Room*>(adjecent, room));
			unsettledRooms.push_back(adjecent);
		}
	}
	if (room->DoesRoomHaveDoorway(Room::Direction::West)) {
		Room* adjecent = room->GetAdjecentRoom(Room::Direction::West);
		if (!isSettled(adjecent) && getShortestDistance(adjecent) > getShortestDistance(room) + room->getWeigthDoorway(Room::Direction::West)) {
			distance.insert(std::pair<Room*, int>(adjecent, getShortestDistance(room) + room->getWeigthDoorway(Room::Direction::West)));
			predecessors.insert(std::pair<Room*, Room*>(adjecent, room));
			unsettledRooms.push_back(adjecent);
		}
	}
}

int CompasCommand::getShortestDistance(Room * room)
{
	int d = distance[room];
	if (d == NULL) {
		return INT_MAX; //max value
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
	//return room->getDifficulty();

	return rnd.generateInt(1, 20);
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

		for (int i = path.size() - 1; i >= 0; i--) {
			if (i > 0) {
				Room* to = path[i];
				Room* from = path[i - 1];

				if (from->GetXPosition() == to->GetXPosition()) {
					if (from->GetYPosition() > to->GetYPosition()) {
						directions.push_back("South");
					}
					else {
						directions.push_back("North");
					}
				}
				else if (from->GetYPosition() == to->GetYPosition()) {
					if (from->GetXPosition() > to->GetXPosition()) {
						directions.push_back("East");
					}
					else {
						directions.push_back("West");
					}
				}

				/*if (from->GetXPosition() < to->GetXPosition()) {
					directions.push_back("West");
				}
				else if (from->GetXPosition() > to->GetXPosition()) {
					directions.push_back("East");
				}
				else if (from->GetYPosition() > to->GetYPosition()) {
					directions.push_back("North");
				}
				else if (from->GetYPosition() < to->GetYPosition()) {
					directions.push_back("South");
				}*/
			}
		}

		for (int i = 0; i < directions.size(); i++) {
			std::cout << directions[i] << " - ";
		}
		std::cout << endl;
	}

}


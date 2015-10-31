#include "stdafx.h"
#include "HandgrenadeCommand.h"
#include <queue>
#include <vector>


HandgrenadeCommand::HandgrenadeCommand()
{
}


HandgrenadeCommand::~HandgrenadeCommand()
{
}

void HandgrenadeCommand::Run(list<string>* parameters, Game * game)
{
	Room* startRoom = game->getPlayer()->getCurrentRoom();
	int totalRooms = game->getLevel()->dungeon->size();
	visitedRooms.push_back(startRoom);

	while (visitedRooms.size() < totalRooms) {
		GetMinimunEdge();
	}

	CollapseDoorways(startRoom, 5);
}

void HandgrenadeCommand::GetMinimunEdge() {
	map<int, map<Room*, Room::Direction>> availableEdges;

	//ga alle visitRooms langs om verzamel alle Edges naar unvisitedRooms
	for (Room* visitedRoom : visitedRooms) {
		map<Room::Direction, Room*> adjecentRooms = visitedRoom->GetAdjecentRoomsMap();

		typedef std::map<Room::Direction, Room*>::iterator it_type;
		for (it_type iterator = adjecentRooms.begin(); iterator != adjecentRooms.end(); iterator++) {
			//als adjecentKamer nog niet bezocht is
			if (find(visitedRooms.begin(), visitedRooms.end(), iterator->second) == visitedRooms.end()) {
				//weight van doorway
				int weight = iterator->second->getWeigthDoorway(iterator->first);
				//availableEdges.insert(std::pair<int, map<Room*, Room::Direction>>(weight, std::pair<Room*, Room::Direction>(iterator->second, iterator->first)));
				availableEdges[weight][iterator->second] = iterator->first;
			}
		}
	}

	//haal edge op met laagste weight
	int minimum = NULL;
	typedef std::map<int, map<Room*, Room::Direction>>::iterator it_type;
	for (it_type iterator = availableEdges.begin(); iterator != availableEdges.end(); iterator++) {
		if (minimum == NULL) {
			minimum = iterator->first;
		}
		else if (iterator->first < minimum) {
			minimum = iterator->first;
		}
	}

	//doorways.insert(std::pair<Room*, Room::Direction>();
	std::map<Room*, Room::Direction>::iterator itr1;
	std::map<int, std::map<Room*, Room::Direction> >::iterator itr2;
	for (itr2 = availableEdges.begin(); itr2 != availableEdges.end(); itr2++)
	{
		for (itr1 = itr2->second.begin(); itr1 != itr2->second.end(); itr1++)
		{
			if (itr2->first == minimum) {
				doorways[itr1->first] = itr1->second;
				visitedRooms.push_back(itr1->first);
			}
		}
	}

}

void HandgrenadeCommand::CollapseDoorways(Room* startRoom, int amount) {
	int collapsed = 0;
	map<Room*, Room::Direction> toCollapseDoorways;

	deque<Room*> queue;
	vector<Room*> visitedRooms;

	//begin bij currentRoom
	queue.push_back(startRoom);

	while (!queue.empty()) {
		if (collapsed == amount) {
			break;
		}
		Room* room = queue.front();
		queue.pop_front(); // haal room uit queue

		visitedRooms.push_back(room);

		if (doorways.find(room) != doorways.end()) {
			Room::Direction d = doorways[room];
			map<Room::Direction, Room*> adjecentRooms = room->GetAdjecentRoomsMap();
			if (adjecentRooms.size() > 1) {
				if (room->DoesRoomHaveDoorway(Room::Direction::East) && Room::Direction::East != d && collapsed < amount) {
					room->CollapseDoorway(Room::Direction::East);
					collapsed++;
				}
				if (room->DoesRoomHaveDoorway(Room::Direction::West) && Room::Direction::West != d && collapsed < amount) {
					room->CollapseDoorway(Room::Direction::West);
					collapsed++;
				}
				if (room->DoesRoomHaveDoorway(Room::Direction::North) && Room::Direction::North != d && collapsed < amount) {
					room->CollapseDoorway(Room::Direction::North);
					collapsed++;
				}
				if (room->DoesRoomHaveDoorway(Room::Direction::South) && Room::Direction::South != d && collapsed < amount) {
					room->CollapseDoorway(Room::Direction::South);
					collapsed++;
				}
			}
		}

		for (Room* adjecent : room->GetAdjecentRooms()) {
			bool found1 = find(queue.begin(), queue.end(), adjecent) != queue.end();
			bool found2 = find(visitedRooms.begin(), visitedRooms.end(), adjecent) != visitedRooms.end();

			if (!found1 && !found2) {
				queue.push_back(adjecent);
			}

		}
	}
}

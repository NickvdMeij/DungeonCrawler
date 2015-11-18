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
	visitedRooms.clear();
	doorways.clear();

	Room* startRoom = game->getPlayer()->getCurrentRoom();
	int totalRooms = game->getLevel()->dungeon->size();
	visitedRooms.push_back(startRoom);

	while (visitedRooms.size() < totalRooms) {
		GetMinimunEdge();
	}

	if (CollapseDoorways(startRoom, 5)) {
		if (game->getPlayer()->getCurrentRoom()->hasEnemy()) {
			game->getPlayer()->getCurrentRoom()->getEnemy()->takeDamage(INT_MAX);
		}
	}
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
				int weight = visitedRoom->getWeigthDoorway(iterator->first);
				//availableEdges.insert(std::pair<int, map<Room*, Room::Direction>>(weight, std::pair<Room*, Room::Direction>(iterator->second, iterator->first)));
				availableEdges[weight][visitedRoom] = iterator->first;
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
				doorways[itr1->first].push_back(itr1->second);
				visitedRooms.push_back(itr1->first->GetAdjecentRoom(itr1->second));
			}
		}
	}

}

bool HandgrenadeCommand::CollapseDoorways(Room* startRoom, int amount) {
	int collapsed = 0;
	map<Room*, Room::Direction> toCollapseDoorways;

	deque<Room*> queue;
	vector<Room*> visitedRooms;

	//begin bij currentRoom
	queue.push_back(startRoom);

	while (!queue.empty() && collapsed < amount) {
		/*if (collapsed == amount) {
			break;
		}*/
		Room* room = queue.front();
		queue.pop_front(); // haal room uit queue

		visitedRooms.push_back(room);

		if (doorways.find(room) != doorways.end()) {
			vector<Room::Direction> doors = doorways[room];
			map<Room::Direction, Room*> adjecentRooms = room->GetAdjecentRoomsMap();
			if (adjecentRooms.size() > doors.size()) {
				if (room->DoesRoomHaveDoorway(Room::Direction::East) && find(doors.begin(), doors.end(), Room::Direction::East) == doors.end() && collapsed < amount
					&& find(visitedRooms.begin(), visitedRooms.end(), room->GetAdjecentRoom(Room::Direction::East)) == visitedRooms.end()
					&& adjecentRooms[Room::Direction::East] != nullptr) {
					room->GetAdjecentRoom(Room::Direction::East)->CollapseDoorway(Room::Direction::West);
					room->CollapseDoorway(Room::Direction::East);					
					collapsed++;
				}
				if (room->DoesRoomHaveDoorway(Room::Direction::West) && find(doors.begin(), doors.end(), Room::Direction::West) == doors.end() && collapsed < amount
					&& find(visitedRooms.begin(), visitedRooms.end(), room->GetAdjecentRoom(Room::Direction::West)) == visitedRooms.end()
					&& adjecentRooms[Room::Direction::West] != nullptr) {
					room->GetAdjecentRoom(Room::Direction::West)->CollapseDoorway(Room::Direction::East);
					room->CollapseDoorway(Room::Direction::West);
					collapsed++;
				}
				if (room->DoesRoomHaveDoorway(Room::Direction::North) && find(doors.begin(), doors.end(), Room::Direction::North) == doors.end() && collapsed < amount
					&& find(visitedRooms.begin(), visitedRooms.end(), room->GetAdjecentRoom(Room::Direction::North)) == visitedRooms.end()
					&& adjecentRooms[Room::Direction::North] != nullptr) {
					room->GetAdjecentRoom(Room::Direction::North)->CollapseDoorway(Room::Direction::South);
					room->CollapseDoorway(Room::Direction::North);
					collapsed++;
				}
				if (room->DoesRoomHaveDoorway(Room::Direction::South) && find(doors.begin(), doors.end(), Room::Direction::South) == doors.end() && collapsed < amount
					&& find(visitedRooms.begin(), visitedRooms.end(), room->GetAdjecentRoom(Room::Direction::South)) == visitedRooms.end()
					&& adjecentRooms[Room::Direction::South] != nullptr) {
					room->GetAdjecentRoom(Room::Direction::South)->CollapseDoorway(Room::Direction::North);
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

	if (collapsed > 0) {
		std::cout << "De kerker schudt op zijn grondvesten, alle tegenstanders in de kamer zijn verslagen! Een donderend geluid maakt duidelijk dat gedeeltes van de kerker zijn ingestort..." << endl;
		return true;
	}
	else {
		std::cout << "Je vreest dat een extra handgranaat een cruciale passage zal blokkeren. Het is beter om deze niet meer te gebruiken op deze verdieping." << endl;
		return false;
	}
}

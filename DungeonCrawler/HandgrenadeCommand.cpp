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
			if (find(visitedRooms.begin(), visitedRooms.end(), iterator->second) != visitedRooms.end()) {
				//weight van doorway
				int weight = iterator->second->getWeigthDoorway(iterator->first);
				//availableEdges.insert(std::pair<int, map<Room*, Room::Direction>>(weight, std::pair<Room*, Room::Direction>(iterator->second, iterator->first)));
				availableEdges[weight][iterator->second] = iterator->first;
			}
		}		
	}


}

void HandgrenadeCommand::CollapseDoorways(int amount) {

}

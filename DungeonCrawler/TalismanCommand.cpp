#include "stdafx.h"
#include "TalismanCommand.h"
#include <queue>
#include <vector>


TalismanCommand::TalismanCommand()
{
}


TalismanCommand::~TalismanCommand()
{
}

void TalismanCommand::Run(list<string>* parameters, Game * game)
{
	int amountOfRoomsAway = 0;
	bool foundStair = false;

	Room* stairRoom = game->getLevel()->getStairRoom();
	Room* startRoom = game->getPlayer()->getCurrentRoom();
	startRoom->setDistance(0);

	deque<Room*> queue;
	vector<Room*> visitedRooms;

	//begin bij currentRoom
	queue.push_back(startRoom);

	while (!queue.empty() && !foundStair) {
		Room* room = queue.front();
		queue.pop_front(); // haal room uit queue

		visitedRooms.push_back(room);

		for (Room* adjecent : room->GetAdjecentRooms()) {
			bool found1 = find(queue.begin(), queue.end(), adjecent) != queue.end();
			bool found2 = find(visitedRooms.begin(), visitedRooms.end(), adjecent) != visitedRooms.end();

			if (!found1 && !found2) {
				adjecent->setDistance(room->getDistance() + 1);// zet afstand 1 hoger dan huidige kamer
				if (adjecent == stairRoom) {
					// stairRoom gevonden: print en stop loop
					amountOfRoomsAway = adjecent->getDistance();
					foundStair = true;
					break;
				}
				queue.push_back(adjecent);
			}

		}
	}

	cout << "De talisman licht op en fluistert dat de trap omhoog " << amountOfRoomsAway << " kamers ver weg is." << endl;
}

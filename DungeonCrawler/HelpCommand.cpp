#include "stdafx.h"
#include "HelpCommand.h"
#include <iostream>

using namespace std;
HelpCommand::HelpCommand()
{
}


HelpCommand::~HelpCommand()
{
}

void HelpCommand::Run(list<string>* parameters, Game* game)
{
	cout << "Help" << endl;
	cout << "-- help			- Generates a list with commands you can execute with a small description what they do" << endl;
	cout << "-- go <direction>	- Move the player in a direction (north, east, south or west)" << endl;
	cout << "-- map			- Show the map" << endl;
	cout << "-- talisman		- Shows how close you are to the stair going down " << endl;
	cout << "-- compass		- Show the direction to the stair room" << endl;
	cout << "-- grenade		- Destroys all enemies in the room, collapses up to 5 doorways. No experience and items are given" << endl;
	cout << "-- look			- Look in the current room" << endl;
	cout << "-- attack		- Attack the enemy (if there is an enemy present in the room)" << endl;
	cout << "-- player		- Show player info" << endl;
	cout << "-- stair		- Take the stairs to the next level" << endl;
	cout << "-- rest			- Your hero rests a bit to restore health" << endl;
}

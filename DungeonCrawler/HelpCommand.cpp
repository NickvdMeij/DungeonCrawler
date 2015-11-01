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
	cout << "-- talisman		- " << endl;
	cout << "-- compass		- Show the direction to the stair room" << endl;
	cout << "-- grenade		- " << endl;
	cout << "-- look		1	- Look in the current room" << endl;
	cout << "-- attack		- Attack the enemy (if there is an enemy present in the room)" << endl;
	cout << "-- player		- Show player info" << endl;
	cout << "-- stair		- Take the stairs to the next level" << endl;
}

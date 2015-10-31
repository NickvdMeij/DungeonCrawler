#include "stdafx.h"
#include "MapCommand.h"
#include <sstream>


MapCommand::MapCommand()
{
}


MapCommand::~MapCommand()
{
}

void MapCommand::Run(list<string>* parameters, Game * game)
{

	Array2D* dungeon = game->getLevel()->dungeon;

	int width, height;

	width = dungeon->get_x_size();
	height = dungeon->get_y_size();

	vector<std::string> strings;

	for (int lines = 0; lines < height; lines++) {
		std::string s;
		std::string e = "                                                  ";
		strings.push_back(s);
		strings.push_back(e);
	}

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (dungeon->get(x, y)->isVisited()) {
				if (game->getPlayer()->getCurrentRoom() == dungeon->get(x, y)) {
					strings[y * 2] += "C";
				}
				else if (game->getLevel()->getStairRoom() == dungeon->get(x, y)) {
					strings[y * 2] += "S";
				}
				else {
					strings[y * 2] += "N";
				}

				if (y > 0) {
					if (dungeon->get(x, y)->DoesRoomHaveDoorway(Room::Direction::North)) {
						char replaceChar = '|';
						if (dungeon->get(x, y)->isDoorwayCollapsed(Room::Direction::North)) {
							replaceChar = '~';
						}
						int replaceIndex = strings[(y * 2)].length() - 1;
						strings[(y * 2) - 1][replaceIndex] = replaceChar;
					}
				}
				if (y < height - 1) {
					if (dungeon->get(x, y)->DoesRoomHaveDoorway(Room::Direction::South)) {
						char replaceChar = '|';
						if (dungeon->get(x, y)->isDoorwayCollapsed(Room::Direction::South)) {
							replaceChar = '~';
						}
						int replaceIndex = strings[(y * 2)].length() - 1;
						strings[(y * 2) + 1][replaceIndex] = replaceChar;
					}
				}
				if (x > 0) {
					if (dungeon->get(x, y)->DoesRoomHaveDoorway(Room::Direction::West)) {
						char replaceChar = '-';
						if (dungeon->get(x, y)->isDoorwayCollapsed(Room::Direction::West)) {
							replaceChar = '~';
						}
						int replaceIndex = strings[y * 2].length() - 3;
						strings[y * 2][replaceIndex] = replaceChar;
					}
				}
				if (x < width - 1) {
					if (dungeon->get(x, y)->DoesRoomHaveDoorway(Room::Direction::East)) {
						if (dungeon->get(x, y)->isDoorwayCollapsed(Room::Direction::East)) {
							strings[y * 2] += " ~ ";
						}
						else {
							strings[y * 2] += " - ";
						}
					}
					else {
						strings[y * 2] += "   ";
					}
				}
				
			}
			else {
				strings[y * 2] += ".";
				strings[y * 2] += "   ";
			}
		}
	}

	for (int x = 0; x < strings.size(); x++) {
		std::cout << strings[x] << endl;
	}
	std::cout << "Legenda:" << endl;
	std::cout << "-| : Doorway" << endl;
	std::cout << "~  : Collapsed Doorway" << endl;
	std::cout << "N  : Normal Room" << endl;
	std::cout << "S  : Stair Room" << endl;
	std::cout << "C  : Current Room" << endl;
}

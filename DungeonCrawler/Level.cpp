#include "stdafx.h"
#include "Level.h"

Level::Level(int _width, int _height, int _floor) {
	width = _width;
	height = _height;
	floor = _floor;

	DungeonGenerator* g = new DungeonGenerator();
	dungeon = g->GenerateRooms(width, height, floor);
	
	chooseStartRoom();
	if (floor < 4) {
		chooseStairRoom();
	}
	else {
		chooseBossRoom();
	}

	delete g;
	g = nullptr;
}

Level::~Level()
{
	delete dungeon;
	dungeon = nullptr;
	startRoom = nullptr;
	stairRoom = nullptr;
	bossRoom = nullptr;
}

void Level::chooseStartRoom()
{
	int randomX = rnd.generateInt(0, width - 1);
	int randomY = rnd.generateInt(0, height - 1);

	//begin bij willekeurige kamer
	setStartRoom(dungeon->get(randomX, randomY));
}

void Level::chooseBossRoom()
{
	int randomX = rnd.generateInt(0, width - 1);
	int randomY = rnd.generateInt(0, height - 1);

	//kamer mag niet rondom start kamer zijn.
	while ((randomX == startRoom->GetXPosition() || randomX == startRoom->GetXPosition() - 1 || randomX == startRoom->GetXPosition() + 1)
		&& (randomY == startRoom->GetYPosition() || randomY == startRoom->GetYPosition() - 1 || randomY == startRoom->GetYPosition() + 1)) {
		randomX = rnd.generateInt(0, width - 1);
		randomY = rnd.generateInt(0, height - 1);
	}

	setBossRoom(dungeon->get(randomX, randomY));
	//bossRoom = dungeon->get(randomX, randomY);
	
	//De boss - hoger base stats
	Enemy* enemy = new Enemy();
	int i = rnd.generateInt(0, 1);
	bossRoom->removeEnemy();
	if (i == 0) {
		enemy->setIsAlive(true);
		enemy->setName("Hill giant");
		enemy->setAttack(35 * floor);
		enemy->setDefence(20 * floor);
		enemy->setHealth(150 * floor);
	}
	else {
		enemy->setIsAlive(true);
		enemy->setName("Snake");
		enemy->setAttack(40 * floor);
		enemy->setDefence(15 * floor);
		enemy->setHealth(150 * floor);
	}

	bossRoom->setEnemy(enemy);
}

void Level::chooseStairRoom()
{
	int randomX = rnd.generateInt(0, width - 1);
	int randomY = rnd.generateInt(0, height - 1);

	//kamer mag niet rondom start kamer zijn.
	while ((randomX == startRoom->GetXPosition() || randomX == startRoom->GetXPosition() - 1 || randomX == startRoom->GetXPosition() + 1)
		&& (randomY == startRoom->GetYPosition() || randomY == startRoom->GetYPosition() - 1 || randomY == startRoom->GetYPosition() + 1)) {
		randomX = rnd.generateInt(0, width - 1);
		randomY = rnd.generateInt(0, height - 1);
	}

	//begin bij willekeurige kamer
	setStairRoom(dungeon->get(randomX, randomY));
}

#include "stdafx.h"
#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
}

void Player::MoveDirection(Room::Direction direction)
{
	if (currentRoom.DoesRoomHaveDoorway(direction)) {
		currentRoom = currentRoom.GetAdjecentRoom(direction);
	}
}



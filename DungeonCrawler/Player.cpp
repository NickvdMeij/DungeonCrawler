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
	if (currentRoom->DoesRoomHaveDoorway(direction)) {
		setCurrentRoom(currentRoom->GetAdjecentRoom(direction));
		currentRoom->visitRoom();
		cout << "You entered the next room." << endl;
	}
	else {
		cout << "No doorway in that direction!" << endl;
	}
}

void Player::Equip(Weapon weapon)
{
	if (inventory.hasItem(weapon)) {
		inventory.removeItem(weapon);
		setMainHand(weapon);
	}
}

void Player::Equip(Shield shield)
{
	if (inventory.hasItem(shield)) {
		inventory.removeItem(shield);
		setOffHand(shield);
	}
}



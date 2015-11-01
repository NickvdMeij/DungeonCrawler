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
		if (currentRoom->isDoorwayCollapsed(direction)) {
			cout << "This doorway seems collapsed." << endl;
		}
		else {
			setCurrentRoom(currentRoom->GetAdjecentRoom(direction));
			currentRoom->visitRoom();
			cout << "You entered the next room." << endl;
		}
	}
	else {
		cout << "No doorway in that direction!" << endl;
	}
}

void Player::setExperience(int e)
{
	experience += e;
	int xpLevel = 1000 * level;

	if (experience > xpLevel) {
		experience = 0;
		level++;
		totalHealth = totalHealth * 2;
		std::cout << "You have leveled up!";
	}
}

void Player::Equip(Weapon* weapon)
{
	if (inventory.hasItem(*weapon)) {
		inventory.removeItem(*weapon);
		setMainHand(weapon);
	}
}

void Player::Equip(Shield* shield)
{
	if (inventory.hasItem(*shield)) {
		inventory.removeItem(*shield);
		setOffHand(shield);
	}
}

void Player::TakeDamage(int amount) {
	if (!offHand->Block()) {
		if (amount > offHand->getDefence()) {
			std::cout << "You lost " << (amount - offHand->getDefence()) << "hp" << endl;
			currentHealth = currentHealth - (amount - offHand->getDefence());
		}
		else {
			std::cout << "HAHA, this enemy is so weak that you didnt recieve any damage!" << endl;
		}
	}
	else {
		std::cout << "Attack blocked by your shield!" << endl;
	}
}



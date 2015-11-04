#include "stdafx.h"
#include "Enemy.h"
#include "RandomInt.h"

Enemy::Enemy()
{
	alive = true;
}

Enemy::~Enemy()
{
	//std::cout << "enemy destructor" << std::endl;
}

void Enemy::takeDamage(int damage)
{
	if ((damage - defence) > health) {
		alive = false;
		health = 0;
	}
	else {
		health = health - (damage - defence);
	}
}

int Enemy::getDamage()
{
	bool isCritical = (bool) RandomInt::generateInt(0, 1);

	if (isCritical) {
		return attack * 1.5;
	}
	else {
		return attack;
	}
}

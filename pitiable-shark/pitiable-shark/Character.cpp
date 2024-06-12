#include "Character.h"

Character::Character()
{
	this->health = 0;
	this->level = 1;
}

void Character::setHealth(int health)
{
	this->health = health;
}

int Character::getHealth()
{
	return this->health;
}

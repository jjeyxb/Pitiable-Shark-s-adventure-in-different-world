#include "Character.h"


Character::Character()
{
	this->health = 500;
	this->level = 1;
	this->damage = 100;
}

Character::~Character()
{

}

void Character::setHealth(int health)
{
	this->health = health;
}

void Character::setName(string name)
{
	this->name = name;
}

void Character::setDamage(int damage)
{
	this->damage = damage;
}

int Character::getHealth() const
{
	return this->health;
}

string Character::getName() const
{
	return this->name;
}

int Character::getDamage() const
{
	return this->damage;
}

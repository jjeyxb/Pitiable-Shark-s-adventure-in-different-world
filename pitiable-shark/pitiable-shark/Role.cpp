#include "Role.h"

Role::Role()
{
	//weapon乃傷害之乘區，默認為1。
	this->weapon = 1;
}

Role::~Role()
{

}

void Role::setWeapon(int weapon)
{
	this->weapon = weapon;
}

Role::Role(string name)
{
	this->setName(name);
	this->weapon = 1;
}


int Role::getWeapon() const
{
	return this->weapon;
}

void Role::attack(Character* c1)
{
	Role* pr1 = dynamic_cast<Role*>(c1);
	int health = pr1->getHealth();
	health -= this->getDamage() * this->getWeapon();
	pr1->setHealth(health);

}

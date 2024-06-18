#pragma once
#include "Character.h"
class Role : public Character
{
private:
	int weapon;
public:
	Role();
	Role(string name);
	virtual ~Role();
	void setWeapon(int weapon);
	int getWeapon() const;
	virtual void attack(Character* c1);
};


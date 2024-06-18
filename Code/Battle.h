#pragma once
#include "Role.h"
#include "Output.h"
#include <iostream>
#include <iomanip>

using namespace std;
class Battle
{
private:
	Role* mainRole;
	Role* monster;
	bool endBattle;
public:
	Battle();
	Battle(Role* mainRole, Role* monster);
	~Battle();
	Role* getMonster();
	Role* getMainRole();
	void fight();
	void showInFo();
	void showOptions();

};


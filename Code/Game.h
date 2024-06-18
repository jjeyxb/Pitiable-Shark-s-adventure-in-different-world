#pragma once
#include "Story.h"
#include "Role.h"
#include "Battle.h"
#include <iostream>
using namespace std;

class Game
{
private:
	bool gameOver;
public:
	Game();
	void setGameOver(int gameOver);
	int getGameOver() const;
	void runTheGame();
	void forgive(Role* monster);
	bool checkHealth(Role* r1);
	static int forgiveValue;
};


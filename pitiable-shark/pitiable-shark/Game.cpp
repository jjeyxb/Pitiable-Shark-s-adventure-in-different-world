#include "Game.h"

int Game::forgiveValue = 0;
Game::Game()
{
	this->gameOver = 0;
}

void Game::setGameOver(int gameOver)
{
	this->gameOver = gameOver;
}

int Game::getGameOver() const
{
	return this->gameOver;
}

void Game::runTheGame()
{
	Story start;
	
	start.outPutFile("opening.txt");
	string name;
	cin >> name;
	//創建主角
	Role your(name);


	start.setCheck('#');
	start.outPutFile("opening.txt");
	cout << "去吧!" << name << "! 開始你的傳奇冒險!" << endl;
	start.setCheck('$');
	start.outPutFile("opening.txt");

	int event = 0;
	while (this->getGameOver() != 1) 
	{
		//第一天王
		Role* monster = new Role("大屌俠");
		Battle event1(&your, monster);
		event1.fight();
		if (this->checkHealth(&your)) {
			cout << "很抱歉，你死在了" << monster->getName() << "的淫威之下。" << endl;
			start.setCheck('$');
			start.outPutFile("gameover.txt");
			this->setGameOver(1);
			break;
		}
		else {
			cout << your.getName() << ": 抱歉，我討厭有人的屌比我還大。" << endl;
			cout << monster->getName() << ": 可是我才五公分阿！" << endl;
			this->forgive(monster);
		}
		delete monster;
		//第一天王結束
		your.setWeapon(your.getWeapon() + this->forgiveValue);
		your.setHealth(1600);
		//第二天王
		Role* monster2 = new Role("博愛座之王");
		monster2->setHealth(600);
		monster2->setDamage(500);
		Battle event2(&your, monster2);
		event2.fight();
		if (this->checkHealth(&your)) {
			cout << "很抱歉，你死在了"<<monster2->getName()<<"的淫威之下。" << endl;
			start.setCheck('$');
			start.outPutFile("gameover.txt");
			this->setGameOver(1);
			break;
		}
		else {
			cout << your.getName() << ": 以後博愛座沒人搶的過我了!" << endl;
			cout << monster2->getName() << ": 可是我是老人家阿！" << endl;
			this->forgive(monster2);
		}
		delete monster2;
		//第二天王結束
		your.setWeapon(your.getWeapon() + this->forgiveValue);
		//第三天王

		//第三天王結束
	}
	
}
void Game::forgive(Role* monster)
{
	Output talk;
	int options;

	cout << "你是否要放過" << monster->getName() << "?" << endl;
	talk.setColors(2);
	talk.talk("1是 ");
	talk.setColors(1);
	talk.talk("2否");
	cout << "輸入數字" << endl;
	cin >> options;
	if (options == 1) {
		cout << "你放過了" << monster->getName() << endl;
		forgiveValue++;
	}else{
		cout << "你殺死了" << monster->getName() << endl;
	}
}
//如果角色血量小於0，回傳true來結束遊戲
bool Game::checkHealth(Role* r1)
{
	if (r1->getHealth() <= 0)
		return true;
	else
		return false;
}

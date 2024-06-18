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
	//�ЫإD��
	Role your(name);


	start.setCheck('#');
	start.outPutFile("opening.txt");
	cout << "�h�a!" << name << "! �}�l�A���ǩ_�_�I!" << endl;
	start.setCheck('$');
	start.outPutFile("opening.txt");

	int event = 0;
	while (this->getGameOver() != 1) 
	{
		//�Ĥ@�Ѥ�
		Role* monster = new Role("�j�x�L");
		Battle event1(&your, monster);
		event1.fight();
		if (this->checkHealth(&your)) {
			cout << "�ܩ�p�A�A���b�F" << monster->getName() << "���]�¤��U�C" << endl;
			start.setCheck('$');
			start.outPutFile("gameover.txt");
			this->setGameOver(1);
			break;
		}
		else {
			cout << your.getName() << ": ��p�A�ڰQ�����H���x����٤j�C" << endl;
			cout << monster->getName() << ": �i�O�ڤ~���������I" << endl;
			this->forgive(monster);
		}
		delete monster;
		//�Ĥ@�Ѥ�����
		your.setWeapon(your.getWeapon() + this->forgiveValue);
		your.setHealth(1600);
		//�ĤG�Ѥ�
		Role* monster2 = new Role("�շR�y����");
		monster2->setHealth(600);
		monster2->setDamage(500);
		Battle event2(&your, monster2);
		event2.fight();
		if (this->checkHealth(&your)) {
			cout << "�ܩ�p�A�A���b�F"<<monster2->getName()<<"���]�¤��U�C" << endl;
			start.setCheck('$');
			start.outPutFile("gameover.txt");
			this->setGameOver(1);
			break;
		}
		else {
			cout << your.getName() << ": �H��շR�y�S�H�m���L�ڤF!" << endl;
			cout << monster2->getName() << ": �i�O�ڬO�ѤH�a���I" << endl;
			this->forgive(monster2);
		}
		delete monster2;
		//�ĤG�Ѥ�����
		your.setWeapon(your.getWeapon() + this->forgiveValue);
		//�ĤT�Ѥ�

		//�ĤT�Ѥ�����
	}
	
}
void Game::forgive(Role* monster)
{
	Output talk;
	int options;

	cout << "�A�O�_�n��L" << monster->getName() << "?" << endl;
	talk.setColors(2);
	talk.talk("1�O ");
	talk.setColors(1);
	talk.talk("2�_");
	cout << "��J�Ʀr" << endl;
	cin >> options;
	if (options == 1) {
		cout << "�A��L�F" << monster->getName() << endl;
		forgiveValue++;
	}else{
		cout << "�A�����F" << monster->getName() << endl;
	}
}
//�p�G�����q�p��0�A�^��true�ӵ����C��
bool Game::checkHealth(Role* r1)
{
	if (r1->getHealth() <= 0)
		return true;
	else
		return false;
}

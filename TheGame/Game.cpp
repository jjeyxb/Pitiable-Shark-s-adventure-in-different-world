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
	Output talk;
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
		start.setCheck('@');
		start.outPutFile("story1.txt");
		Role* monster = new Role("�j�x�L");
		Battle event1(&your, monster);
		event1.fight();
		if (this->checkHealth(&your)) {
			cout << "�ܩ�p�A�A���b�F" << monster->getName() << "���]�¤��U�C" << endl;
			talk.PauseSomeTimes();
			start.setCheck('$');
			start.outPutFile("gameover.txt");
			this->setGameOver(1);
			break;
		}
		else {
			talk.PauseSomeTimes();
			cout << your.getName() << ": ��p�A�ڰQ�����H���x����٤j�C" << endl;
			talk.PauseSomeTimes();
			cout << monster->getName() << ": �i�O�ڤ~���������I" << endl;
			talk.PauseSomeTimes();
			this->forgive(monster);
		}
		delete monster;
		//�Ĥ@�Ѥ�����
		your.setWeapon(your.getWeapon() + this->forgiveValue);
		your.setHealth(2600);
		//�ĤG�Ѥ�
		start.setCheck('#');
		start.outPutFile("story1.txt");
		Role* monster2 = new Role("�շR�y����");
		monster2->setHealth(1000);
		monster2->setDamage(500);
		Battle event2(&your, monster2);
		event2.fight();
		if (this->checkHealth(&your)) {
			talk.PauseSomeTimes();
			cout << "�ܩ�p�A�A���b�F"<<monster2->getName()<<"���]�¤��U�C" << endl;
			talk.PauseSomeTimes();
			start.setCheck('$');
			start.outPutFile("gameover.txt");
			this->setGameOver(1);
			break;
		}
		else {
			talk.PauseSomeTimes();
			cout << your.getName() << ": �H��շR�y�S�H�m���L�ڤF!" << endl;
			talk.PauseSomeTimes();
			cout << monster2->getName() << ": �i�O�ڬO�ѤH�a���I" << endl;
			talk.PauseSomeTimes();
			this->forgive(monster2);
		}
		delete monster2;
		//�ĤG�Ѥ�����
		your.setWeapon(your.getWeapon() + this->forgiveValue);
		your.setHealth(3000);
		//�ĤT�Ѥ�
		start.setCheck('%');
		start.outPutFile("story1.txt");
		Role* monster3 = new Role("���q��");
		monster3->setHealth(4000);
		monster3->setDamage(888);
		Battle event3(&your, monster3);
		event3.fight();
		if (this->checkHealth(&your)) {
			talk.PauseSomeTimes();
			cout << "�ܩ�p�A�A���b�F" << monster3->getName() << "���]�¤��U�C" << endl;
			talk.PauseSomeTimes();
			start.setCheck('$');
			start.outPutFile("gameover.txt");
			this->setGameOver(1);
			break;
		}
		else {
			talk.PauseSomeTimes();
			cout << your.getName() << ": ����N��a!" << endl;
			talk.PauseSomeTimes();
			cout << monster3->getName() << ": �ڥi�O���q���@���! ���D�ڿ��F��? " << endl;
			talk.PauseSomeTimes();
			this->forgive(monster3);
		}
		delete monster3;
		//�ĤT�Ѥ�����
		this->setGameOver(1);
	}
	if (forgiveValue == 3) {
		start.setCheck('@');
		start.outPutFile("end.txt");
	}
	else {
		start.setCheck('#');
		start.outPutFile("end.txt");
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
		cout << "�A��L�F" << monster->getName() <<"�ño��ˮ`�[��" << endl;
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

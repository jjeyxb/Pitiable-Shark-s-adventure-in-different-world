#include "Battle.h"

Battle::Battle()
{
	this->mainRole = new Role;
	this->monster = new Role;
	this->endBattle = 0;
}

Battle::Battle(Role* mainRole, Role* monster)
{
	this->mainRole = new Role;
	this->monster = new Role;
	this->mainRole = mainRole;
	this->monster = monster;
	this->endBattle = 0;
}

Battle::~Battle()
{

}

Role* Battle::getMonster()
{
	return this->monster;
}

Role* Battle::getMainRole()
{
	return this->mainRole;
}

void Battle::fight()
{
	Output talk;//�ΨӼȰ��@��
	int options;
	this->showInFo();
	int value = 2;
	while (this->endBattle != 1) {
		this->showOptions();
		cin >> options;
		if (options == 1) {
			cout << "�A���X�F" << this->mainRole->getDamage() * this->mainRole->getWeapon() << "�I�ˮ`" << endl;
			this->mainRole->attack(this->monster);
			talk.PauseSomeTimes();
		}
		else if (options == 2) {
			if (this->monster->getDamage() == 500) {
				srand(time(0));
				if (rand() % 10 + 1 <= value) {
					cout << "�A�ϥX�L�����N�A��" << this->getMonster()->getName() << "����q�M�s" << endl;
					talk.PauseSomeTimes();
					this->getMonster()->setHealth(0);
					if (this->mainRole->getHealth() <= 0 || this->monster->getHealth() <= 0) {
						this->endBattle = 1;
						cout << "�԰�����" << endl;
						cout << "--------------------" << endl;
						break;
					}
				}
				else {
					value++;
					cout << "�A���L�����N�t�I���\, �ثe���\���v:" << value << "0%" << endl;
					talk.PauseSomeTimes();
				}
				
			}else
			cout << this->getMonster()->getName() << ":�ڤ��Q��A�i�����o�ܡC" << endl;
			talk.PauseSomeTimes();
		}
		else if (options == 3) {
			cout << "�A��ܮ��O�^�X�Ӭd�ݼħڪ��A" << endl;
			talk.PauseSomeTimes();
			cout << this->monster->getName() << "��A�y���F"
				<< this->monster->getDamage() * this->monster->getWeapon() << "���ˮ`" << endl;
			this->monster->attack(this->mainRole);
			talk.PauseSomeTimes();
			this->showInFo();
		}
		else if (options >= 4) {
			cout << this->getMonster()->getName() << "������A���٭��F" << endl;
			this->getMainRole()->setHealth(0);	
			talk.PauseSomeTimes();
		}
		
		
		if (this->mainRole->getHealth() <= 0 || this->monster->getHealth() <= 0) {
			this->endBattle = 1;
			cout << "�԰�����" << endl;
			break;
		}
		if (options < 3) {
			cout << this->monster->getName() << "��A�y���F"
				<< this->monster->getDamage() * this->monster->getWeapon() << "���ˮ`" << endl;
			this->monster->attack(this->mainRole);
			talk.PauseSomeTimes();
		}
		if (this->mainRole->getHealth() <= 0 || this->monster->getHealth() <= 0) {
			this->endBattle = 1;
			cout << "�԰�����" << endl;
			cout << "--------------------" << endl;
			break;
		}
	}
}

void Battle::showInFo()
{
	Output output;
	output.setColors(1);
	output.talk("�Ǫ��W��:");
	output.talk(this->getMonster()->getName());
	cout << endl;
	cout << "��q: " << this->getMonster()->getHealth() << endl;
	output.PauseSomeTimes();

	output.setColors(4);
	output.talk("����W��:");
	output.talk(this->getMainRole()->getName());
	cout << endl;
	cout << "��q: " << this->getMainRole()->getHealth() << endl;
	output.PauseSomeTimes();
}

void Battle::showOptions()
{
	Output output;
	output.setColors(2);
	output.talk("��ܧA���欰:\n1����, 2�͸�, 3�d�ݪ��A, 4�D��(��J�Ʀr)\n");
}

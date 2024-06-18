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
	Output talk;//用來暫停一秒
	int options;
	this->showInFo();
	int value = 2;
	while (this->endBattle != 1) {
		this->showOptions();
		cin >> options;
		if (options == 1) {
			cout << "你打出了" << this->mainRole->getDamage() * this->mainRole->getWeapon() << "點傷害" << endl;
			this->mainRole->attack(this->monster);
			talk.PauseSomeTimes();
		}
		else if (options == 2) {
			if (this->monster->getDamage() == 500) {
				srand(time(0));
				if (rand() % 10 + 1 <= value) {
					cout << "你使出嘴砲之術，把" << this->getMonster()->getName() << "的血量清零" << endl;
					talk.PauseSomeTimes();
					this->getMonster()->setHealth(0);
					if (this->mainRole->getHealth() <= 0 || this->monster->getHealth() <= 0) {
						this->endBattle = 1;
						cout << "戰鬥結束" << endl;
						cout << "--------------------" << endl;
						break;
					}
				}
				else {
					value++;
					cout << "你的嘴砲之術差點成功, 目前成功機率:" << value << "0%" << endl;
					talk.PauseSomeTimes();
				}
				
			}else
			cout << this->getMonster()->getName() << ":我不想跟你進行任何廢話。" << endl;
			talk.PauseSomeTimes();
		}
		else if (options == 3) {
			cout << "你選擇浪費回合來查看敵我狀態" << endl;
			talk.PauseSomeTimes();
			cout << this->monster->getName() << "對你造成了"
				<< this->monster->getDamage() * this->monster->getWeapon() << "的傷害" << endl;
			this->monster->attack(this->mainRole);
			talk.PauseSomeTimes();
			this->showInFo();
		}
		else if (options >= 4) {
			cout << this->getMonster()->getName() << "直接把你給斬首了" << endl;
			this->getMainRole()->setHealth(0);	
			talk.PauseSomeTimes();
		}
		
		
		if (this->mainRole->getHealth() <= 0 || this->monster->getHealth() <= 0) {
			this->endBattle = 1;
			cout << "戰鬥結束" << endl;
			break;
		}
		if (options < 3) {
			cout << this->monster->getName() << "對你造成了"
				<< this->monster->getDamage() * this->monster->getWeapon() << "的傷害" << endl;
			this->monster->attack(this->mainRole);
			talk.PauseSomeTimes();
		}
		if (this->mainRole->getHealth() <= 0 || this->monster->getHealth() <= 0) {
			this->endBattle = 1;
			cout << "戰鬥結束" << endl;
			cout << "--------------------" << endl;
			break;
		}
	}
}

void Battle::showInFo()
{
	Output output;
	output.setColors(1);
	output.talk("怪物名稱:");
	output.talk(this->getMonster()->getName());
	cout << endl;
	cout << "血量: " << this->getMonster()->getHealth() << endl;
	output.PauseSomeTimes();

	output.setColors(4);
	output.talk("角色名稱:");
	output.talk(this->getMainRole()->getName());
	cout << endl;
	cout << "血量: " << this->getMainRole()->getHealth() << endl;
	output.PauseSomeTimes();
}

void Battle::showOptions()
{
	Output output;
	output.setColors(2);
	output.talk("選擇你的行為:\n1攻擊, 2談話, 3查看狀態, 4求饒(輸入數字)\n");
}

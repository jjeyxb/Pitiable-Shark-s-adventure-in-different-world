#pragma once
#include <string>

using namespace std;
class Character
{
//�w�]��private�C
int health;
int level;
int damage;
string name;
//���F���l���O�i�H�I�A�l���O�~���i�I�A�G�ϥ�protected�C
protected:
	//�l���O�i�H�z�L���禡�]�wprivate�����ȡC

	void setName(string name);

public:
	Character();
	virtual ~Character();
	void setHealth(int health);
	void setDamage(int damage);
	int getHealth() const;
	string getName() const;
	int getDamage() const;
	//�ϥΦh���Aabstract class�A�Τ����O���O��Ѽƫ��O�C
	virtual void attack(Character* c1) = 0;

};


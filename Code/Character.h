#pragma once
#include <string>

using namespace std;
class Character
{
//預設為private。
int health;
int level;
int damage;
string name;
//為了讓子類別可以碰，子類別外不可碰，故使用protected。
protected:
	//子類別可以透過此函式設定private中的值。

	void setName(string name);

public:
	Character();
	virtual ~Character();
	void setHealth(int health);
	void setDamage(int damage);
	int getHealth() const;
	string getName() const;
	int getDamage() const;
	//使用多型，abstract class，用父類別型別當參數型別。
	virtual void attack(Character* c1) = 0;

};


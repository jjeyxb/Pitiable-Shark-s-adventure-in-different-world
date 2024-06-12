#pragma once
class Character
{
//預設為private。
int health;
int level;
//為了讓子類別可以碰，子類別外不可碰，故使用protected。
protected:
	//子類別可以透過此函式設定private中的值。
	void setHealth(int health);
public:
	Character();
	int getHealth();

};


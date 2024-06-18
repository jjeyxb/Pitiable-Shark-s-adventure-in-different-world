#include "Output.h"

Output::Output()
{
	this->text = " ";
	this->colors = 0;
}

void Output::setColors(int colors)
{
	this->colors = colors;
}

int Output::getColors() const
{
	return this->colors;
}

void Output::talk(string text)
{
	//�o�O�@�ӯ��X�C�⪺�禡�An�ΨӨM�w��X���C��C
	//�Ƶ�:0�w�],1����,2���,3�`��,4����,5����C
	this->text = text;
	switch (this->getColors())
	{
	case 0:
		cout <<RESET<< text;
		break;
	case 1:
		cout << RED << text << RESET;
		break;
	case 2:
		cout << GREEN << text << RESET;
		break;
	case 3:
		cout << DEEPGREEN << text << RESET;
		break;
	case 4:
		cout << YELLOW << text << RESET;
		break;
	case 5:
		cout << PURPLE << text << RESET;
		break;
	}
}

void Output::PauseSomeTimes(int times)
{
	//�ΨӼȰ��t�ήɶ����禡
	std::this_thread::sleep_for(std::chrono::seconds(times));
}

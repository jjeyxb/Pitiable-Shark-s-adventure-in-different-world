#include "Output.h"

Output::Output()
{
	text = " ";
	colors = 0;
}

void Output::talk(string text, int n)
{
	//�o�O�@�ӯ��X�C�⪺�禡�An�ΨӨM�w��X���C��C
	//�Ƶ�:0�w�],1����,2���,3�`��,4����,5����C
	this->text = text;
	switch (n)
	{
	case 0:
		cout <<RESET<< text << endl;
		break;
	case 1:
		cout << RED << text << RESET << endl;
		break;
	case 2:
		cout << GREEN << text << RESET << endl;
		break;
	case 3:
		cout << DEEPGREEN << text << RESET << endl;
		break;
	case 4:
		cout << YELLOW << text << RESET << endl;
		break;
	case 5:
		cout << PURPLE << text << RESET << endl;
		break;
	}
}

void Output::PauseSomeTimes(int times)
{
	//�ΨӼȰ��t�ήɶ����禡
	std::this_thread::sleep_for(std::chrono::seconds(times));
}

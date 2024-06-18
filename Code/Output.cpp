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
	//這是一個能輸出顏色的函式，n用來決定輸出的顏色。
	//備註:0預設,1紅色,2綠色,3深綠,4黃色,5紫色。
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
	//用來暫停系統時間的函式
	std::this_thread::sleep_for(std::chrono::seconds(times));
}

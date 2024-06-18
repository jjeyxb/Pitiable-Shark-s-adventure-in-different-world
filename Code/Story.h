#pragma once
#include <fstream>
#include "Output.h"
class Story
{
private:
	char check;
	Output * talk;
public:
	Story();
	~Story();
	void setCheck(char sign);
	char getCheck();
	void outPutFile(string fileName);
};


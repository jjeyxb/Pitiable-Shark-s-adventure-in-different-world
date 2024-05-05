#include "Story.h"

Story::Story()
{
	check = '@';
	talk = new Output();
}

Story::~Story()
{
	delete talk;
}

void Story::setCheck(char sign)
{
	check = sign;
}

char Story::getCheck()
{
	return check;
}

void Story::outPutFile(string fileName)
{
	//用來打開某個檔案，並根據成員check的符號來決定是否輸出那一行。
	fstream* file;
	file = new fstream(fileName);
	string line;
	
	while (getline(*file, line)) {
		if (!line.empty() && line[0] == this->getCheck()) {
			talk->talk(line.substr(1),0);
			talk->PauseSomeTimes();
		}
	}

	file->close();
	delete file;
}

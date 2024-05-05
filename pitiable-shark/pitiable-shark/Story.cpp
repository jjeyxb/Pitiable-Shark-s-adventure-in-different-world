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
	//�Ψӥ��}�Y���ɮסA�îھڦ���check���Ÿ��ӨM�w�O�_��X���@��C
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

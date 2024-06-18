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
			this->talk->talk(line.substr(1));
			cout << endl;
			if(this->getCheck()!= '$') //�p�G�ˬd�Ÿ��O$�N���|�Ȱ��ɶ��A�ɶ��N�O�����A�_���C
			this->talk->PauseSomeTimes();
		}
	}

	file->close();
	delete file;
}

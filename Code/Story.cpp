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
			this->talk->talk(line.substr(1));
			cout << endl;
			if(this->getCheck()!= '$') //如果檢查符號是$將不會暫停時間，時間就是金錢，寶貝。
			this->talk->PauseSomeTimes();
		}
	}

	file->close();
	delete file;
}

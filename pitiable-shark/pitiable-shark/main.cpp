#include <iostream>
#include <string>


#include "Story.h"

int main() {
    //�ȮɥΨӴ��աC
    Output test;
    test.talk("���ѬO�Ӭ��n���@��", 1);
    test.PauseSomeTimes(1);
    test.talk("���ѬO�Ӭ��n���@��", 2);
    test.PauseSomeTimes(1);
    test.talk("���ѬO�Ӭ��n���@��", 3);
    Story game;
    game.outPutFile("test.txt");
    system("pause");
    return 0;
}

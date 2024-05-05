#include <iostream>
#include <string>


#include "Story.h"

int main() {
    //暫時用來測試。
    Output test;
    test.talk("今天是個美好的一天", 1);
    test.PauseSomeTimes(1);
    test.talk("今天是個美好的一天", 2);
    test.PauseSomeTimes(1);
    test.talk("今天是個美好的一天", 3);
    Story game;
    game.outPutFile("test.txt");
    system("pause");
    return 0;
}

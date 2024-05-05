#include <iostream>
#include <string>

#include "Output.h"


int main() {
    Output test;
    test.talk("今天是個美好的一天", 1);
    test.PauseSomeTimes(1);
    test.talk("今天是個美好的一天", 2);
    test.PauseSomeTimes(1);
    test.talk("今天是個美好的一天", 3);
    return 0;
}

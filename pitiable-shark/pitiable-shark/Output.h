#pragma once

#include <iostream>
#include <string>
#include <thread>
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define DEEPGREEN "\033[36m"
#define YELLOW  "\033[33m"
#define PURPLE "\033[1m"

using namespace std;
class Output
{
private:
	string text;
	int colors;
public:
	Output();
	void talk(string text, int n = 0);
	void PauseSomeTimes(int times = 1);
};


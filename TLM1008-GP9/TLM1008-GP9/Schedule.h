#include <string>
#include <iostream>
#include <istream>
#include <ostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <array>
#include <cstdio>
#include <filesystem>

using namespace std;

#pragma once
class Schedule
{
public:
//	string currentLine;
	string name;
//	enum stop = {1};

	Schedule();
	~Schedule();
//	void sortByDest();
	void sortByDate();
	void sortByName();
	void sortByTime();
	void displayContent(unsigned int);

	void insertEntry();
	void editEntry();
	void deleteEntry();
//	bool compareFunction(string, string);
};

//int n = 10;
//const int x = 3;
//string* a = new string[n][x];
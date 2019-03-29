#ifndef PARCEL_H
#define PARCEL_H

#pragma once

#include <iostream>
#include <istream>
#include <ostream>
#include <fstream>
#include <algorithm>
#include <array>
#include <cstdio>
#include <filesystem>
#include <functional>
#include <string>
#include <vector>
using namespace std;

class Parcel
{
public:
	string name;
	Parcel();
	~Parcel();
	void displayParcelContent(unsigned int);
	void insertParcelEntry();
	void editParcelEntry();
	void deleteParcelEntry();
};

#endif

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
#include <stdio.h>

using namespace std;

class Parcel
{
private:
	string nameParcel;
	string destinationParcel;
	int deadlineParcel;
	string parcelName[999];
	string parcelDest[999];
	string parcelDead[999];
	string parcelArr[999];

	vector<string> parVect{};
public:
	Parcel();
	Parcel(string, string, int);
	string getNameParcel();
	string getDestinationParcel();
	int getDeadlineParcel();
	
	void setParName(int, string);
	void setParDest(int, string);
	void setParDead(int, string);

	string getParName(int);
	string getParDest(int);
	string getParDead(int);

	string * getParcelArr(string arr[]);

	void setParcelArray(int, string, string, string, int);
};

#endif

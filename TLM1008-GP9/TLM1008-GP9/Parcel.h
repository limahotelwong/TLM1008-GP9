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
	string parcelName[999];
	string parcelDest[999];
	string parcelDead[999];
	vector<string> parVect{};
	int parcelDeadline;
public:
	Parcel();
	Parcel(string, string, int);
	string getParcelName();
	string getParcelDestination();
	string getParcelDeadline();
	void displayParcelContent(unsigned int);
	void insertParcelEntry();
	void editParcelEntry();
	void deleteParcelEntry();
	
	void setParName(int, string);
	void setParDest(int, string);
	void setParDead(int, string);

	string getParName(int);
	string getParDest(int);
	string getParDead(int);
};

#endif

/*
#ifndef PARCEL_H
#define PARCEL_H



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
*/

//#endif

//anything 
/*


#pragma once




class Parcel
{
private:
	string parcelName;
	string parcelDestination;
	int parcelDeadline;
public:
	Parcel(string, string, int);
	string getParcelName();
	string getParcelDestination();
	int getParcelDeadline();
	void displayParcelContent(unsigned int);
	void insertParcelEntry();
	void editParcelEntry();
	void deleteParcelEntry();
};

#endif
*/

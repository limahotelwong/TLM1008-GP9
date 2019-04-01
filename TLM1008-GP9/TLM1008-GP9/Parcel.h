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

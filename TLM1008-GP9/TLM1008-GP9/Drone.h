#ifndef DRONE_H
#define DRONE_H

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

class Drone
{
private:
	string droneName;
	int droneCapacity;
	string droneDestination;
	int droneDeadline;
	int parcelCount;
public:
	Drone(string, int, string, int);
	string getDroneName();
	int getDroneCapacity();
	string getDroneDestination();
	int getDroneDeadline();
	int getParcelCount();
	void parcelCounter(string);
	void readDroneFile();
	void editDroneEntry();

	void setdName(string);
	void setdDestination(string);
	void setdDeadline(int);
	void setdCapacity(int);
};

#endif

/*
#ifndef DRONE_H
#define DRONE_H

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

class Drone
{
private:
	string dArray[999], dName[999], dCapacity[999], dDestination[999], dDeadline[999], dDroneArray[999] = {};
protected:

public:
	string name;
	Drone();
	~Drone();
	void displayDroneContent(unsigned int);
	void insertDroneEntry();
	void editDroneEntry();
	void deleteDroneEntry();
	void setdArray(int, string);
	void setDroArr(int, string);
	void readDroneFile();
	string * getDroneArray(string arr[]);
	void setdName(int, string);
	void setdDestination(int, string);
	void setdDeadline(int, string);
	void setdCapacity(int, string);
	string getdArray(int);
	string getdName(int);
	string getdCapacity(int);
	string getdDestination(int);
	string getdDeadline(int);
	string getDroArr(int);
};

#endif



//--------------------------------------------------


/*#define MAX_BATT 100
#define MAX_RANGE 5000

#include <string>

using namespace std;

#pragma once
class Drone
{
	friend 
private:
	int droneId;
	string droneName, droneModel;

protected:
	int battLevel;

public:
	Drone();
	~Drone();
	void GetDroneName(int);
	int GetBatteryLevel(int);
};

*/

//anything


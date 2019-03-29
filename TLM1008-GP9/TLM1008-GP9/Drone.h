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
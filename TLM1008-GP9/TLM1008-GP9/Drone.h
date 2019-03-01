#define MAX_BATT 100
#define MAX_RANGE_MINI 4000
#define MAX_RANGE_HEAVY 4500
#define MAX_RANGE_MAXI 5000

#include <iostream>
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
	Drone(string);
	~Drone();
	void GetDroneName(int);
	int GetBatteryLevel(int);
};
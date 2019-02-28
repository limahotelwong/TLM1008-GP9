#define MAX_BATT 100
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


#define MAX_BATT 100
#define MAX_RANGE 5000

#include <iostream>
#include <string>

using namespace std;

#include "Drone.h"



Drone::Drone()
{
}

Drone::Drone(string dModel)
{
	Drone::droneModel = dModel;
}

Drone::~Drone()
{
}

int GetDroneName(int)
{
	return 0;
}
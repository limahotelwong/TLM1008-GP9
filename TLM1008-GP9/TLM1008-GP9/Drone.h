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


	void setdName(string);
	void setdDestination(string);
	void setdDeadline(int);
	void setdCapacity(int);
};

#endif

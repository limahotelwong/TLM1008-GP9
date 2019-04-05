#ifndef DRONE_CPP
#define DRONE_CPP

#include "Drone.h"

using namespace std;

Drone::Drone(string dName, int dCapacity, string dDestination, int dDeadline)
{
	droneName = dName;
	droneCapacity = dCapacity;
	droneDestination = dDestination;
	droneDeadline = dDeadline;
}

string Drone::getDroneName()
{
	return droneName;
}

int Drone::getDroneCapacity()
{
	return droneCapacity;
}

string Drone::getDroneDestination()
{
	return droneDestination;
}

int Drone::getDroneDeadline()
{
	return droneDeadline;
}

int Drone::getParcelCount()
{
	return parcelCount;
}

void Drone::parcelCounter(string pParcel)
{
	parcelCount = 0;

	parcelCount++;
}

void Drone::setdName(string str)
{
	droneName = str;
}

void Drone::setdDestination(string str)
{
	droneDestination = str;
}

void Drone::setdDeadline(int i)
{
	droneDeadline = i;
}

void Drone::setdCapacity(int i)
{
	droneCapacity = i;
}

#endif

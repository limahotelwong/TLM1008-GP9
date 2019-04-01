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

#endif


/*
//#include "pch.h"
#include "Drone.h"
using namespace std;

int droneValue = 0;
string dArra[999];

Drone::Drone()
{
	droneValue = 0;
}

Drone::~Drone()
{

}

void Drone::setdArray(int index, string str)
{
	dArray[index] = str;
}

void Drone::setDroArr(int index, string str)
{
	dDroneArray[index] = str;
}


void Drone::setdName(int index, string str)
{
	dName[index] = str;
}

void Drone::setdDestination(int index, string str)
{
	dDestination[index] = str;
}

void Drone::setdDeadline(int index, string str)
{
	dDeadline[index] = str;
}

void Drone::setdCapacity(int index, string str)
{
	dCapacity[index] = str;
}

string Drone::getdArray(int index)
{
	return dArray[index];
}

string Drone::getdName(int index)
{
	return dName[index];
}

string Drone::getdCapacity(int index)
{
	return dCapacity[index];
}

string Drone::getdDestination(int index)
{
	return dDestination[index];
}

string Drone::getdDeadline(int index)
{
	return dDeadline[index];
}

string Drone::getDroArr(int index)
{
	return dDroneArray[index];

}

string * Drone::getDroneArray(string arr[])
{

	return arr;
}

void Drone::displayDroneContent(unsigned int type)
{
	switch (type)
	{
	case 1:
		cout << endl << "Name\tCapacity\tDestination\tDeadline" << endl;		//header for the input
		cout << "-------------------------------------------------------" << endl;
		break;

	case 2:
		cout << endl << "Capacity\tName\t\Destination\tDeadline" << endl;		//header for the input
		cout << "-------------------------------------------------------" << endl;
		break;

	case 3:
		cout << endl << "Destination\tName\t\Capacity\tDeadline" << endl;		//header for the input
		cout << "-------------------------------------------------------" << endl;
		break;

	case 4:
		cout << endl << "Deadline\tName\tCapacity\tDestination" << endl;		//header for the input
		cout << "-------------------------------------------------------" << endl;
		break;

	default:
		cout << endl << "Error encountered. Please try again." << endl;		//in the case of a wrong input
	}

	readDroneFile();

	for (int i = 0; i < droneValue; i++)
	{
		switch (type)
		{
		case 1:
			setdArray(i, getdName(i) + "\t" + getdCapacity(i) + "\t\t" + getdDestination(i) + "\t\t" + getdDeadline(i) + "\n");		//printing details
			break;

		case 2:
			setdArray(i, getdCapacity(i) + "\t\t" + getdName(i) + "\t" + getdDestination(i) + "\t\t" + getdDeadline(i) + "\n");		//printing details
			break;

		case 3:
			setdArray(i, getdDestination(i) + "\t\t" + getdName(i) + "\t" + getdCapacity(i) + "\t\t" + getdDeadline(i) + "\n");		//printing details
			break;

		case 4:
			setdArray(i, getdDeadline(i) + "\t\t" + getdName(i) + "\t" + getdCapacity(i) + "\t\t" + getdDestination(i) + "\n");		//printing details
			break;

		default:
			cout << "";		//printing blank as it is an error
		}
	}

	string *dArr = getDroneArray(dArray);


	vector<string> myVector(dArr, dArr + 999);
	std::sort(myVector.begin(), myVector.end());
	copy(myVector.begin(), myVector.end(), ostream_iterator<string>(cout, ""));
}

void Drone::insertDroneEntry()
{
	string name;		//initialize variables
	int capacity;
	string location;
	int deadline;

	cout << endl << "Enter ADD Name, Capacity, Location and Deadline" << endl;		//instructions
	cout << "ADD Name: ";		//name input
	cin >> name;
	cout << "Capacity: ";		//capacity input
	cin >> capacity;
	cout << "Location: ";		//location input
	cin >> location;
	cout << "Deadline: ";		//deadline input
	cin >> deadline;

	ofstream drone_write;

	if (drone_write.is_open())
		cout << "Error encountered. Please try again." << endl;

	drone_write.open("ADDs.txt", ios::app);
	drone_write << "\n" << name << "," << capacity << "," << location << "," << to_string(deadline);		//writing in the input

	cout << endl << "Entry recorded successfully." << endl;

	drone_write.close();
}

void Drone::deleteDroneEntry()
{
	unsigned int dEntry;
	readDroneFile();

	ofstream new_file;
	new_file.open("ADDs.txt");

	if (new_file.is_open())
		cout << "   Name\tCapacity\tDestination\tDeadline:" << endl;		//header after the file is read

	for (int i = 0; i < droneValue; i++)
	{
		setDroArr(i, getdName(i) + "\t" + getdCapacity(i) + "\t\t" + getdDestination(i) + "\t\t" + getdDeadline(i) + "\n");		//printing details
		cout << i + 1 << ": " << getDroArr(i);		//number for the details to select and option
	}

	cout << endl << "Select entry to delete: ";
	cin >> dEntry;		//input option to delete

	for (int i = dEntry - 1; i < droneValue; i++)		//-1 to register the correct data in the array
	{
		setdName(i, getdName(i + 1));
		setdCapacity(i, getdCapacity(i + 1));
		setdDestination(i, getdDestination(i + 1));
		setdDeadline(i, getdDeadline(i + 1));
	}

	for (int i = 0; i < droneValue - 1; i++)
	{
		if (i > 0)		//print next line after line 0
			new_file << "\n";

		new_file << getdName(i) << "," << getdCapacity(i) << "," << getdDestination(i) << "," << getdDeadline(i);
	}

	cout << endl << "Entry deleted successfully." << endl;
	//rename("ADDs.txt", "ADDs.txt");

	new_file.close();
}

void Drone::editDroneEntry()
{
	unsigned int sEntry, eEntry;
	readDroneFile();

	ofstream new_file;
	new_file.open("ADDs.txt");

	if (new_file.is_open())
		cout << endl << "   Name\t\tDestination\tDeadline" << endl;		//header after the file is read

	for (int i = 0; i < droneValue; i++)
	{
		setDroArr(i, getdName(i) + "\t" + getdDestination(i) + "\t\t" + getdDeadline(i) + "\n");		//printing details
		cout << i + 1 << ": " << getDroArr(i);		//number for the details to select and option
	}

	cout << endl << "Select entry to modify: ";
	cin >> sEntry;		//input option to edit

	cout << endl << "1 - Name | 2 - Destination | 3 - Deadline" << endl;
	cout << "Select field to change: ";
	cin >> eEntry;		//input detail to edit

	string temp;

	switch (eEntry)
	{
	case 1:
		cout << "Enter new Name: ";
		cin >> temp;
		setdName(sEntry, temp);		//editing the name
		break;
	case 2:
		cout << "Enter new Destination: ";
		cin >> temp;
		setdDestination(sEntry, temp);		//editing the destination
		break;
	case 3:
		cout << "Enter new Deadline: ";
		cin >> temp;
		setdDeadline(sEntry, temp);			//editing the deadline
		break;
	default:
		cout << "Error encountered. Please enter another option.";
	}

	for (int i = 0; i < droneValue; i++)
	{
		if (i > 0)		//print next line after line 0
			new_file << "\n";

		new_file << getdName(i) << "," << getdDestination(i) << "," << getdDeadline(i);
	}

	cout << endl << "Entry modified successfully" << endl;
	//rename("ADDs.txt", "ADDs.txt");

	new_file.close();
}

void Drone::readDroneFile()
{

	ifstream schedule_file;

	if (schedule_file.is_open())
		cout << "Error reading file" << endl;

	schedule_file.open("ADDs.txt");
	//rename("ADDs.txt", "ADDs.txt");

	string tempName, tempCap, tempDest, tempDead;

	while (!schedule_file.eof())
	{
		getline(schedule_file, tempName, ',');		//read the name and breaks at the comma
		getline(schedule_file, tempCap, ',');		//read the capacity and breaks at the comma
		getline(schedule_file, tempDest, ',');		//read the destination and breaks at the comma
		getline(schedule_file, tempDead);			//read the deadline
		setdName(droneValue, tempName);
		setdCapacity(droneValue, tempCap);
		setdDestination(droneValue, tempDest);
		setdDeadline(droneValue, tempDead);

		droneValue++;
	}

	schedule_file.close();
}


//--------------------------------------------------
*/
/*
#define MAX_BATT 100
#define MAX_RANGE 5000

#include <iostream>
#include <string>

using namespace std;

#include "Drone.h"



Drone::Drone()
{
}


Drone::~Drone()
{
}
*/
/*
//////
//#ifndef DRONE_CPP anything 
#define DRONE_CPP

//#include "pch.h"
#include "Drone.h"

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

#endif 
*/
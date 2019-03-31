//#ifndef PARCEL_CPP
#define PARCEL_CPP

//#include "pch.h"
#include "Parcel.h"
#include <iostream>
#include <stdio.h>
using namespace std;

void readParcelFile();

int parcelValue = 0;
string pArray[999], pName[999], pDestination[999], pDeadline[999] = {};
string pParcelArray[999];

Parcel::Parcel()
{

}

Parcel::~Parcel()
{

}
int  z = 0;
void Parcel::displayParcelContent(unsigned int type)
{
	vector<string> myVector(pArray, pArray + 999);
	//myVector.clear();
	switch (type)
	{
	case 1:
		cout << endl << "Name\t\tDestination\tDeadline" << endl;		//header for the input
		cout << "---------------------------------------------" << endl;
		break;

	case 2:
		cout << endl << "Destination\tName\t\tDeadline" << endl;		//header for the input
		cout << "---------------------------------------------" << endl;
		break;

	case 3:
		cout << endl << "Deadline\tName\t\tDestination" << endl;		//header for the input
		cout << "---------------------------------------------" << endl;
		break;

	default:
		cout << endl << "Error encountered. Please try again." << endl;		//in the case of a wrong input
	}
	//myVector.clear();

	while (z == 0)
	{
		z++;
		readParcelFile();

	}

	for (int i = 0; i < parcelValue; i++)
	{
		switch (type)
		{
		case 1:
			pArray[i] = pName[i] + "\t" + pDestination[i] + "\t\t" + pDeadline[i] + "\n";		//printing details
			break;

		case 2:
			pArray[i] = pDestination[i] + "\t\t" + pName[i] + "\t" + pDeadline[i] + "\n";		//printing details
			break;

		case 3:
			pArray[i] = pDeadline[i] + "\t\t" + pName[i] + "\t" + pDestination[i] + "\n";		//printing details
			break;

		default:
			cout << "";		//printing blank as it is an error

		}
	}

	//	myVector.clear();
	sort(myVector.begin(), myVector.end());
	copy(myVector.begin(), myVector.end(), ostream_iterator<string>(cout, ""));
	//.clear();
}

void Parcel::insertParcelEntry()
{
	string name;		//initialize variables
	string location;
	int deadline;

	cout << endl << "Enter Package Name, Location and Deadline" << endl;		//instructions
	cout << "Package Name: ";		//name input
	cin >> name;
	cout << "Location: ";		//location input
	cin >> location;
	cout << "Deadline: ";		//deadline input
	cin >> deadline;

	ofstream parcel_write;

	if (parcel_write.is_open())
		cout << "Error encountered. Please try again." << endl;

	parcel_write.open("parcels.txt", ios::app);
	parcel_write << "\n" << name << "," << location << "," << to_string(deadline);		//writing in the input

	cout << endl << "Entry recorded successfully." << endl;

	parcel_write.close();
}

void Parcel::deleteParcelEntry()
{
	unsigned int dEntry;
	readParcelFile();

	ofstream new_file;
	new_file.open("parcels.txt");

	if (new_file.is_open())
		cout << "   Name\t\tDestination\tDeadline:" << endl;		//header after the file is read

	for (int i = 0; i < parcelValue; i++)
	{
		pParcelArray[i] = pName[i] + "\t" + pDestination[i] + "\t\t" + pDeadline[i] + "\n";		//printing details
		cout << i + 1 << ": " << pParcelArray[i];		//number for the details to select and option
	}

	cout << endl << "Select entry to delete: ";
	cin >> dEntry;		//input option to delete

	for (int i = dEntry - 1; i < parcelValue; i++)		//-1 to register the correct data in the array
	{
		pName[i] = pName[i + 1];
		pDestination[i] = pDestination[i + 1];
		pDeadline[i] = pDeadline[i + 1];
	}

	for (int i = 0; i < parcelValue - 1; i++)
	{
		if (i > 0)		//print next line after line 0
			new_file << "\n";

		new_file << pName[i] << "," << pDestination[i] << "," << pDeadline[i];
	}

	cout << endl << "Entry deleted successfully." << endl;
	rename("parcels.txt", "parcels.txt");

	new_file.close();
}

void Parcel::editParcelEntry()
{
	unsigned int sEntry, eEntry;
	readParcelFile();

	ofstream new_file;
	new_file.open("parcels.txt");

	if (new_file.is_open())
		cout << endl << "   Name\t\tDestination\tDeadline" << endl;		//header after the file is read

	for (int i = 0; i < parcelValue; i++)
	{
		pParcelArray[i] = pName[i] + "\t" + pDestination[i] + "\t\t" + pDeadline[i] + "\n";		//printing details
		cout << i + 1 << ": " << pParcelArray[i];		//number for the details to select and option
	}

	cout << endl << "Select entry to modify: ";
	cin >> sEntry;		//input option to edit

	cout << endl << "1 - Name | 2 - Destination | 3 - Deadline" << endl;
	cout << "Select field to change: ";
	cin >> eEntry;		//input detail to edit

	switch (eEntry)
	{
	case 1:
		cout << "Enter new Name: ";
		cin >> pName[sEntry];		//editing the name
		break;

	case 2:
		cout << "Enter new Destination: ";
		cin >> pDestination[sEntry];		//editing the destination
		break;

	case 3:
		cout << "Enter new Deadline: ";
		cin >> pDeadline[sEntry];		//editing the deadline
		break;

	default:
		cout << "Error encountered. Please enter another option.";
	}

	for (int i = 0; i < parcelValue; i++)
	{
		if (i > 0)		//print next line after line 0
			new_file << "\n";

		new_file << pName[i] << "," << pDestination[i] << "," << pDeadline[i];
	}

	cout << endl << "Entry modified successfully" << endl;
	rename("parcels.txt", "parcels.txt");

	new_file.close();
}

void readParcelFile()
{

	ifstream schedule_file;

	if (schedule_file.is_open())
		cout << "Error reading file" << endl;

	schedule_file.open("parcels.txt");
	rename("parcels.txt", "parcels.txt");

	while (!schedule_file.eof())
	{
		getline(schedule_file, pName[parcelValue], ',');		//read the name and breaks at the comma
		getline(schedule_file, pDestination[parcelValue], ',');		//read the destination and breaks at the comma
		getline(schedule_file, pDeadline[parcelValue]);		//read the deadline
		parcelValue++;
	}

	schedule_file.close();

}

/*//#ifndef PARCEL_CPP anything 
#define PARCEL_CPP

#include "pch.h"
#include <string>
#include <vector>
#include "Parcel.h"

Parcel::Parcel(string pName, string pDestination, int pDeadline)
{
	parcelName = pName;
	parcelDestination = pDestination;
	parcelDeadline = pDeadline;
}

string Parcel::getParcelName()
{
	return parcelName;
}

string Parcel::getParcelDestination()
{
	return parcelDestination;
}

int Parcel::getParcelDeadline()
{
	return parcelDeadline;
}

//#endif*/

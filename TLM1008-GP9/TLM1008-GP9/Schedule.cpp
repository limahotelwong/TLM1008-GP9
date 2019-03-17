#include "Schedule.h"

using namespace std;

void readFile();

int n = 0;
string sArr[999], rName[999], rDest[999], rTime[999] = {};
string dArr[999];

Schedule::Schedule()
{
}

Schedule::~Schedule()
{
}

void Schedule::displayContent(unsigned int type)
{
	switch (type)
	{
	case 1:
		cout << "Name:\t\tDest:\tTime:" << endl;
		break;
	case 2:
		cout << "Dest:\tName:\t\tTime:" << endl;
		break;
	case 3:
		cout << "Time:\tName:\t\tStop:" << endl;
		break;
	default:
		cout << "Name:\t\tDest:\tTime:" << endl;
	}

	readFile();

	for (int i = 0; i < n; i++)
	{
		switch (type)
		{
		case 1:
			sArr[i] = rName[i] + "\t" + rDest[i] + "\t" + rTime[i] + "\n";
			break;
		case 2:
			sArr[i] = rDest[i] + "\t" + rName[i] + "\t" + rTime[i] + "\n";
			break;
		case 3:
			sArr[i] = rTime[i] + "\t" + rName[i] + "\t" + rDest[i] + "\n";
			break;
		default:
			sArr[i] = rName[i] + "\t" + rDest[i] + "\t" + rTime[i] + "\n";
		}
	}
		
	vector<string> myVector(sArr, sArr + 999);

	std::sort(myVector.begin(), myVector.end());
	std::copy(myVector.begin(), myVector.end(), ostream_iterator<string>(cout, ""));	
}

void Schedule::insertEntry()
{
	string name;
	string loc;
//	int date;
	int time;
	cout << "Enter Package Name, Location and Deadline in (YYYYMMDD)\n\n";
	cout << "Package Name: ";
	cin >> name;
	cout << "Location: ";
	cin >> loc;
	cout << "Time: ";
	cin >> time;

	ofstream schedule_write;

	if (schedule_write.is_open())
		cout << "Error encountered, please try again." << endl;

	schedule_write.open("schedule.txt", ios::app);
	schedule_write << "\n" << name << "," << loc << "," << to_string(time);

	cout << "Entry recorded successfully" << endl;

	schedule_write.close();
}

void Schedule::deleteEntry()
{
	unsigned int del;
	readFile();

	ofstream new_file;
	new_file.open("schedule.txt");

	if (new_file.is_open())
		cout << "Error encountered, please try again." << endl;

	cout << "Name:\t\tDest:\tTime:" << endl;	//print table
	for (int i = 0; i < n; i++)
	{
		dArr[i] = rName[i] + "\t" + rDest[i] + "\t" + rTime[i] + "\n";		
		cout << i+1 << ": " << dArr[i];
	}

	cout << "\n\nSelect entry to delete: ";
	cin >> del;

	for (int i = del - 1; i < n; i++)	//shift array elements forward
	{
		rName[i] = rName[i + 1];
		rDest[i] = rDest[i + 1];
		rTime[i] = rTime[i + 1];	
	}
	
	for (int i = 0; i < n-1; i++)
	{
		if (i > 0)	//print next line after line0
			new_file << "\n";

		new_file << rName[i] << "," << rDest[i] << "," << rTime[i];		
	}

	cout << "Entry deleted successfully" << endl;

	new_file.close();
}

void readFile()
{
	n = 0;
	ifstream schedule_file;
	if (schedule_file.is_open())
		cout << "Error reading file" << endl;

	schedule_file.open("schedule.txt");

	while (!schedule_file.eof())
	{		
		getline(schedule_file, rName[n], ',');
		getline(schedule_file, rDest[n], ',');
		getline(schedule_file, rTime[n]);
		n++;		
	}
	cout << n << endl;

	schedule_file.close();
}
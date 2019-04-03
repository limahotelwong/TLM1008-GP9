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

#include "Drone.h"
#include "Parcel.h"
#include "Schedule.h"

void welcome(void);
void readTextFile();
void printTextFile(unsigned int);

vector<string> notFull{ };
vector<string> Full{ };
vector<string> totalADD{ };

Parcel parcel("", "", 1);
int printIndex = 0;

template <typename T> // To match element within vector. Return boolean.
const bool Contains(vector<T>& Vec, const T& Element)
{
	return (find(Vec.begin(), Vec.end(), Element) != Vec.end()) ? true : false;
}

int option;

vector<Parcel> package;		//initialize vector

void welcome()
{

	cout << endl;
	cout << "      W             W    A       K    K   EEEEEE   N      N   DDDDDD       A       N      N     GGGGGG        " << endl;
	cout << "       W           W    A A      K  K     E        N N    N   D     D     A A      N N    N    G              " << endl;
	cout << "        W    W    W    A   A     KKK      EEEEE    N   N  N   D      D   A   A     N   N  N   G    GGGG       " << endl;
	cout << "         W  W W  W    A AAA A    K  K     E        N    N N   D     D   A AAA A    N    N N    G      G       " << endl;
	cout << "          W     W    A       A   K    K   EEEEEE   N      N   DDDDDD   A       A   N      N     GGGGGG        " << endl << endl;

}
void menu()
{
	cout << "1. Display all ADD information" << endl;
	cout << "2. Display all parcels information" << endl;
	cout << "3. Schedule all parcels (by Deadline)" << endl;
	cout << "4. Schedule all parcels (minimum # of ADDs)" << endl;
	cout << "5. Display ADDs that are not full" << endl;
	cout << "6. Display final scheduling plan sorted by ADDs" << endl;
	cout << "7. Display final scheduling plan sorted by parcels" << endl;
	cout << "8. Save scheduling plan" << endl;
	cout << "9. Add/Delete/Edit ADD" << endl;
	cout << "10. Add/Delete/Edit parcel" << endl;
	cout << "Key -1 To End Program" << endl << endl;

	cout << "Please enter your option: " << endl << ">";
	cin >> option;
}


int main(void)
{
	string droneName, droneDestination;		//initialize variables to read files and register into class variables
	int droneCapacity, droneDeadline;

	ifstream droneFile("ADDs.txt");		//read .txt file

	vector<Drone> add;		//initialize vector
	{
		if (droneFile)
		{
			while (droneFile >> droneName >> droneCapacity >> droneDestination >> droneDeadline)
			{
				Drone drone(droneName, droneCapacity, droneDestination, droneDeadline);		//register data to variables
				add.push_back(drone);
			}
		}
	}

	string parcelName, parcelDestination;		//initialize variables to read file
	int parcelDeadline;

	ifstream parcelFile("parcels.txt");		//read .txt file

	
	{
		if (parcelFile)
		{
			while (parcelFile >> parcelName >> parcelDestination >> parcelDeadline)
			{
				Parcel parcel(parcelName, parcelDestination, parcelDeadline);		//register data to variables
				package.push_back(parcel);
			}
		}
	}

	vector<string> scheduleDeadline{ };
	vector<string> leftoverDeadline{ };
	vector<string> scheduleCapacity{ };
	vector<string> leftoverCapacity{ };

	welcome();
	menu();
	while (option != -1)
	{
		switch (option)
		{
		case 1:
			unsigned int sortD;

			cout << endl << "Display all ADD information" << endl;
			cout << "1 - Sort by Name | 2- Sort by Capacity | 3 - Sort by Destination | 4 - Sort by Deadline" << endl;
			cout << "Enter Option: ";
			cin >> sortD;

			if (sortD == 1)
			{
				cout << endl << "Name\tCapacity\tDestination\tDeadline" << endl;		//header for the input
				cout << "-------------------------------------------------------" << endl;
				for (int i = 0; i < add.size(); ++i)
				{
				//	cout << add[i].getDroneName() << "\t" << add[i].getDroneCapacity() << "\t\t" << add[i].getDroneDestination() << "\t\t" << add[i].getDroneDeadline() << endl;
					
				}

				cout << endl;

			}

			else if (sortD == 2)
			{
				cout << endl << "Capacity\tName\tDestination\tDeadline" << endl;		//header for the input
				cout << "-------------------------------------------------------" << endl;
				for (int i = 0; i < add.size(); ++i)
				{
				//	cout << add[i].getDroneCapacity() << "\t\t" << add[i].getDroneName() << "\t" << add[i].getDroneDestination() << "\t\t" << add[i].getDroneDeadline() << endl;
				}

				cout << endl;

			}

			else if (sortD == 3)
			{
				cout << endl << "Destination\tName\tCapacity\tDeadline" << endl;		//header for the input
				cout << "-------------------------------------------------------" << endl;
				for (int i = 0; i < add.size(); ++i)
				{
				//	cout << add[i].getDroneDestination() << "\t\t" << add[i].getDroneName() << "\t" << add[i].getDroneCapacity() << "\t\t" << add[i].getDroneDeadline() << endl;
				}

				cout << endl;

			}

			else if (sortD == 4)
			{
				cout << endl << "Deadline\tName\tCapacity\tDestination" << endl;		//header for the input
				cout << "-------------------------------------------------------" << endl;
				for (int i = 0; i < add.size(); ++i)
				{
				//	cout << add[i].getDroneDeadline() << "\t\t" << add[i].getDroneName() << "\t" << add[i].getDroneCapacity() << "\t\t" << add[i].getDroneDestination() << endl;
				}

				cout << endl;

			}

			else
			{
				cout << endl << "Invalid option. Please try again." << endl << endl;

			}

			break;

		case 2:
		{
			readTextFile();
			unsigned int sortP;
			cout << endl << "Display all Parcel information" << endl;
			cout << "1 - Sort by Name | 2 - Sort by Destination | 3 - Sort by Deadline" << endl;
			cout << "Enter Option: ";
			cin >> sortP;

		//	printTextFile(sortP);
			string parcelArray[999];

			for (int i = 0; i < printIndex; i++)
			{
				if (sortP == 1)
					parcelArray[i] = parcel.getParName(i) + '\t' + parcel.getParDest(i) + '\t' + parcel.getParDead(i) + "\n";
				else if (sortP == 2)
					parcelArray[i] = parcel.getParDest(i) + '\t' + parcel.getParName(i) + '\t' + parcel.getParDead(i) + "\n";
				else if (sortP == 3)
					parcelArray[i] = parcel.getParDead(i) + '\t' + parcel.getParName(i) + '\t' + parcel.getParDest(i) + "\n";
				else
					parcelArray[i] = parcel.getParName(i) + '\t' + parcel.getParDest(i) + '\t' + parcel.getParDead(i) + "\n";
			}



			vector<string> myVector(parcelArray, parcelArray + 999);

			std::sort(myVector.begin(), myVector.end());
			std::copy(myVector.begin(), myVector.end(), ostream_iterator<string>(cout, ""));
		}

			break;
		case 3:

			scheduleDeadline.clear();
			leftoverDeadline.clear();

			for (int i = 0; i < package.size(); i++)
			{
				bool k = false;

				for (int j = 0; j < add.size(); j++)
				{
					if (add[j].getDroneDestination() != package[i].getParcelDestination())		//stop name much match to continue
						continue;

					if ((add[j].getDroneDeadline() / 100 * 60 + add[j].getDroneDeadline() % 100) < (stoi(package[i].getParcelDeadline()) / 100 * 60 + stoi(package[j].getParcelDeadline()) % 100 - 30) ||
						(add[j].getDroneDeadline() / 100 * 60 + add[j].getDroneDeadline() % 100) > (stoi(package[i].getParcelDeadline()) / 100 * 60 + stoi(package[j].getParcelDeadline()) % 100))		//calculate the timing in minutes and must fit in the 30 seconds range to continue
						continue;

					if (add[j].getParcelCount() > add[j].getDroneCapacity())		//make sure the capacity doesn't exceed
						continue;

					add[j].parcelCounter(package[i].getParcelName());		//adding 1 to the capacity of the drone
					scheduleDeadline.push_back(package[i].getParcelName());		//register the parcel name
					scheduleDeadline.push_back(add[j].getDroneName());		//register the add name

					k = true;
					break;
				}

				if (k == false)
				{
					leftoverDeadline.push_back(package[i].getParcelName());
				}
			}

			cout << endl << "Scheduled success. Please select '6' to see the result." << endl << endl;

					

			break;

		case 4:
			scheduleCapacity.clear();
			leftoverCapacity.clear();

			for (int i = 0; i < package.size(); i++)
			{
				bool k = false;

				for (int j = add.size(); j >= 0; j--)
				{
					if (add[j - 1].getDroneDestination() != package[i].getParcelDestination())		//stop name much match to continue
					{
						continue;
					}

					if (add[j - 1].getParcelCount() > add[j - 1].getDroneCapacity())		//make sure the capacity doesn't exceed
					{
						continue;
					}

					add[j - 1].parcelCounter(package[i].getParcelName());		//adding 1 to the capacity of the drone
					scheduleCapacity.push_back(package[i].getParcelName());		//register the parcel name
					scheduleCapacity.push_back(add[j - 1].getDroneName());		//register the add name

					k = true;
					break;
				}

				if (k == false)
				{
					leftoverCapacity.push_back(package[i].getParcelName());
				}
			}

			cout << endl << "Scheduled success. Please select '7' to see the result." << endl << endl;

			

			break;

		case 5:
		//	vector<string> notFull{ };
		//	vector<string> Full{ };
		//	vector<string> totalADD{ };

			unsigned int option1;
			cout << endl;
			cout << "1. Sorted by Deadline" << endl;
			cout << "2. Sorted by ADD" << endl;
			cout << endl;
			cout << "Please enter your option: " << endl << ">";
			cin >> option1;


			switch (option1)
			{
			case 1:
			{
				// Comparing to check ADD scheduled by capacity is not full starts here. 

				for (int j = 0; j < add.size(); j++) //Total Parcels
				{
					for (int k = 0; k < add[j].getDroneCapacity(); k++)
					{
						notFull.push_back(add[j].getDroneName()); // (Eg. If ADD01 has max cap of 2, it will push ADD01 twice into vector)
					}
				}

				for (int k = 0; k < add.size(); k++) //Total ADD (Eg. ADD00 to ADD40)
				{
					totalADD.push_back(add[k].getDroneName()); // Pushing total ADD(s) into 'testing' vector. 
				}

				for (int i = 0; i < scheduleCapacity.size(); i++)
				{
					if (Contains(totalADD, scheduleCapacity.at(i))) // To match and obtain assigned scheduled ADD(s) name(s). 
					{
						Full.push_back(scheduleCapacity.at(i)); // To push assigned scheduled ADD(s) name into 'Full' vector. 
					}
					else {}
				}

				vector<string>::iterator lit; //Creating a temporary iterator vector.
				for (int j = 0; j < (Full.size()); j++)
				{
					lit = find(notFull.begin(), notFull.end(), Full.at(j)); // To identify each scheduled element position in Total ADD+CAP list
					if (lit != notFull.end()) //If element is identified in Total ADD list,
					{
						Full.erase(Full.begin() + (j));  //Remove matched element from scheduled vector. 
						notFull.erase(notFull.begin() + (lit - notFull.begin())); //Remove scheduled vector from total ADD list.
						--j; //Since an element has been removed, we will return back to previous counter. Else, it will be skipping one element. 
					}
					else {}
				}

				for (auto i = 0; i < notFull.size(); i++)
				{
					auto count = 1;
					auto limit = notFull.size() - 1;
					while (i < limit  && notFull[i] == notFull[i + 1])
					{
						count++;
						i++;
					}

					cout << notFull[i] << " is not full with " << count << " capacity left. " << endl;
				}

				cout << endl;
				
				break;
			}
			case 2:
			{
				// Comparing to check ADD scheduled by deadline is not full starts here. 

				for (int j = 0; j < add.size(); j++) //Totalling ADD+CAP
				{
					for (int k = 0; k < add[j].getDroneCapacity(); k++)
					{
						notFull.push_back(add[j].getDroneName()); // (Eg. If ADD01 has max cap of 2, it will push ADD01 twice into vector)
					}
				}

				for (int k = 0; k < add.size(); k++) // Eg. ADD00 to ADD30
				{
					totalADD.push_back(add[k].getDroneName()); // Pushing total ADD(s) name(s) into 'testing' vector. 
				}

				for (int i = 0; i < scheduleDeadline.size(); i++)
				{
					if (Contains(totalADD, scheduleDeadline.at(i))) //Comparing match for ADD 
					{
						Full.push_back(scheduleDeadline.at(i)); //Totalling Scheduled ADD+CAP
					}
					else {}
				}

				vector<string>::iterator lit; //Creating a temporary iterator vector.
				for (int j = 0; j < (Full.size()); j++)
				{
					lit = find(notFull.begin(), notFull.end(), Full.at(j)); // To identify each scheduled element position in Total ADD+CAP list
					if (lit != notFull.end()) //If element is identified in Total ADD list,
					{
						Full.erase(Full.begin() + j); //Remove matched element from scheduled vector. 
						notFull.erase(notFull.begin() + (lit - notFull.begin()));  //Remove scheduled vector from total ADD list.
						--j; //Since an element has been removed, we will return back to previous counter. Else, it will be skipping one element. 
					}
					else {
					}
				}

				sort(notFull.begin(), notFull.end());
				for (auto i = 0; i < notFull.size(); i++)
				{
					auto count = 1;

					auto limit = notFull.size() - 1;
					while (i < limit  && notFull[i] == notFull[i + 1])
					{
						count++;
						i++;
					}

					cout << notFull[i] << " is not full with " << count << " capacity left. " << endl;
				}

				cout << endl;
				
				break;
			}
			}
			//Case 5 end.
			break;
	
		case 6:
			cout << endl;

			for (vector<string>::iterator i = scheduleDeadline.begin(); i != scheduleDeadline.end(); i += 2)
			{
				cout << *i << " is assigned to " << *(i + 1) << endl;
			}

			cout << endl;

			for (vector<string>::iterator i = leftoverDeadline.begin(); i != leftoverDeadline.end(); ++i)
			{
				cout << *i << " is unassigned" << endl;
			}

			cout << endl;

			break;
		
		case 7:
			cout << endl;

			for (vector<string>::iterator i = scheduleCapacity.begin(); i != scheduleCapacity.end(); i += 2)
			{
				cout << *i << " is assigned to " << *(i + 1) << endl;
			}

			cout << endl;

			for (vector<string>::iterator i = leftoverCapacity.begin(); i != leftoverCapacity.end(); ++i)
			{
				cout << *i << " is unassigned" << endl;
			}

			cout << endl;
			

			break;
		
		case 8:
			unsigned int save, saveC, saveD;

			cout << endl << "Save scheduling plan" << endl;
			cout << "1 - Sorted by Deadline | 2 - Sorted by minimum # of ADDs" << endl;
			cout << "Enter Option: ";
			cin >> save;

			if (save == 1)
			{
				{
					cout << "1 - Save assigned parcels | 2 - Save unassigned parcels" << endl;
					cout << "Enter Option: ";
					cin >> saveD;

					if (saveD == 1)
					{
						ofstream output_file;
						output_file.open("assigned_parcels_deadline.txt");

						if (output_file.is_open())
						{
							std::cout << endl << "File successfully created." << endl << endl;
							for (vector<string>::iterator i = scheduleDeadline.begin(); i != scheduleDeadline.end(); i += 2)
							{
								output_file << *i << " is assigned to " << *(i + 1) << endl;
							}
							output_file.close();
						}
						else
						{
							std::cout << "Error opening file.\n";
						}
					}

					else if (saveD == 2)
					{
						ofstream output_file;
						output_file.open("unassigned_parcels_deadline.txt");

						if (output_file.is_open())
						{
							std::cout << endl << "File successfully created." << endl << endl;
							for (vector<string>::iterator i = leftoverDeadline.begin(); i != leftoverDeadline.end(); i += 2)
							{
								output_file << *i << " is unassigned" << endl;
							}
							output_file.close();
						}
						else
						{
							std::cout << "Error opening file.\n";
						}
					}

					else
					{
						cout << endl << "Invalid option. Please try again." << endl << endl;
					}
				}
			}

			else if (save == 2)
			{
				{
					cout << "1 - Save assigned parcels | 2 - Save unassigned parcels" << endl;
					cout << "Enter Option: ";
					cin >> saveC;

					if (saveC == 1)
					{
						ofstream output_file;
						output_file.open("assigned_parcels_capacity.txt");

						if (output_file.is_open())
						{
							std::cout << endl << "File successfully created." << endl << endl;
							for (vector<string>::iterator i = scheduleCapacity.begin(); i != scheduleCapacity.end(); i += 2)
							{
								output_file << *i << " is assigned to " << *(i + 1) << endl;
							}
							output_file.close();
						}
						else
						{
							std::cout << "Error opening file.\n";
						}
					}

					else if (saveC == 2)
					{
						ofstream output_file;
						output_file.open("unassigned_parcels_capacity.txt");

						if (output_file.is_open())
						{
							std::cout << endl << "File successfully created." << endl << endl;
							for (vector<string>::iterator i = leftoverCapacity.begin(); i != leftoverCapacity.end(); i += 2)
							{
								output_file << *i << " is unassigned" << endl;
							}
							output_file.close();
						}
						else
						{
							std::cout << "Error opening file.\n";
						}
					}

					else
					{
						cout << endl << "Invalid option. Please try again." << endl << endl;
					}
				}
			}

			else
			{
				cout << endl << "Invalid option. Please try again." << endl << endl;
			}

			break;
		
		case 9:
			unsigned int optionD;

			cout << endl << "Add/Delete/Edit ADD" << endl;
			cout << "1 - Add ADD | 2 - Delete ADD | 3 - Edit ADD" << endl;
			cout << "Enter Option: ";
			cin >> optionD;

			if (optionD == 1)
			{
				string name, destination;		//initialize variables
				int capacity, deadline;

				cout << endl << "Enter ADD Name, Capacity, Location and Deadline" << endl;		//instructions
				cout << "Name: ";		//name input
				cin >> name;
				cout << "Capacity: ";		//capacity input
				cin >> capacity;
				cout << "Destination: ";		//destination input
				cin >> destination;
				cout << "Deadline: ";		//deadline input
				cin >> deadline;

				ofstream drone_add;

				if (drone_add.is_open())
					cout << "Error encountered. Please try again." << endl;

				drone_add.open("ADDs.txt", ios::app);
				drone_add << "\n" << name << " " << capacity << " " << destination << " " << to_string(deadline);		//writing in the input

				cout << endl << "Entry recorded successfully." << endl;

				drone_add.close();

				cout << endl;
			}

			else if (optionD == 2)
			{
				ofstream drone_delete;
				drone_delete.open("ADDs.txt");

				if (drone_delete.is_open())
				{
					cout << endl << "Name\tCapacity\tDestination\tDeadline" << endl;		//header after the file is read
					cout << "-------------------------------------------------------" << endl;
				}

				for (int i = 0; i < add.size(); ++i)
				{
					cout << add[i].getDroneName() << "\t" << add[i].getDroneCapacity() << "\t\t" << add[i].getDroneDestination() << "\t\t" << add[i].getDroneDeadline() << endl;
				}

				string dEntry;

				cout << endl << "Enter ADD Name to delete: ";
				cin >> dEntry;		//input option to delete

				for (int i = 0; i < add.size(); i++)
				{
					if (add[i].getDroneName() == dEntry)		//finding the matching name to delete
					{
						add.erase(add.begin() + i);
					}
				}

				for (int i = 0; i < add.size(); i++)
				{
					drone_delete << add[i].getDroneName() << ' ' << add[i].getDroneCapacity() << ' ' << add[i].getDroneDestination() << ' ' << add[i].getDroneDeadline() << endl;
				}

				cout << endl << "Entry deleted successfully." << endl;
				//rename("ADDs.txt", "ADDs.txt");
				drone_delete.close();

				cout << endl;	
			}

			else if (optionD == 3)
			{
				int sEntry, eEntry;
				string  dTemp;
				int intTemp;

				ofstream drone_edit;
				drone_edit.open("ADDs.txt");

				for (int i = 0; i < add.size(); ++i)
				{
					cout << i + 1 << ": " << add[i].getDroneName() << "\t" << add[i].getDroneCapacity() << "\t\t" << add[i].getDroneDestination() << "\t\t" << add[i].getDroneDeadline() << endl;
				}
				cout << endl;	

				cout << endl << "Enter drone index to edit: ";
				cin >> eEntry;		//input option to edit

				cout << endl << "1 - Name | 2 - Capacity | 3 - Destination | 4 - Deadline" << endl;
				cout << "Select field to change: ";
				cin >> sEntry;		//input detail to edit

				switch (sEntry)
				{
				case 1:
					cout << "Enter new Name: ";
					cin >> dTemp;
					add[eEntry - 1].setdName(dTemp);	//editing the name
					break;

				case 2:
					cout << "Enter new Capacity: ";
					cin >> intTemp;
					add[eEntry - 1].setdCapacity(intTemp);//editing the destination		
					break;

				case 3:
					cout << "Enter new Destination: ";
					cin >> dTemp;
					add[eEntry - 1].setdDestination(dTemp);	//editing the deadline		
					break;

				case 4:
					cout << "Enter new Deadline: ";
					cin >> intTemp;
					add[eEntry - 1].setdDeadline(intTemp);	//editing the deadline

				default:
					cout << "Error encountered. Please enter another option.";
				}

				for (int i = 0; i < add.size(); i++)
				{
					if (i > 0)	//print next line after line0
						drone_edit << "\n";

					drone_edit << add[i].getDroneName() << " " << add[i].getDroneCapacity() << " " << add[i].getDroneDestination() << " " << add[i].getDroneDeadline();
				}

				cout << "Entry modified successfully" << endl;
				//	std::rename("schedule_new.txt", "schedule.txt");

				drone_edit.close();

				printTextFile(1);

				cout << endl << "Entry edited successfully." << endl;
				//rename("parcels.txt", "parcels.txt");
				drone_edit.close();

			}

			else
			{
				cout << endl << "Invalid option. Please try again." << endl << endl;		
			}

			break;
		
		case 10:
			readTextFile();
			
			unsigned int optionP;

			cout << endl << "Add/Delete/Edit parcel" << endl;
			cout << "1 - Add parcel | 2 - Delete parcel | 3 - Edit parcel" << endl;
			cout << "Enter Option: ";
			cin >> optionP;

			if (optionP == 1)
			{
				string name, destination;		//initialize variables
				int deadline;

				cout << endl << "Enter parcel Name, Destination and Deadline" << endl;		//instructions
				cout << "Name: ";		//name input
				cin >> name;
				cout << "Destination: ";		//destination input
				cin >> destination;
				cout << "Deadline: ";		//deadline input
				cin >> deadline;

				ofstream parcel_add;

				if (parcel_add.is_open())
					cout << "Error encountered. Please try again." << endl;

				parcel_add.open("parcel.txt", ios::app);
				parcel_add << "\n" << name << "," << destination << "," << to_string(deadline);		//writing in the input

				cout << endl << "Entry recorded successfully." << endl;

				parcel_add.close();

				cout << endl;
				//main();		
			}

			else if (optionP == 2)
			{
				printTextFile(1);
				ofstream parcel_delete;
				parcel_delete.open("parcel.txt");

				unsigned int del;

				if (parcel_delete.is_open())
				{
					cout << endl << "Name\tDestination\tDeadline" << endl;		//header after the file is read
					cout << "---------------------------------------------" << endl;
				}
				cout << "\n\nSelect entry to delete: ";
				cin >> del;

				for (int i = del - 1; i < printIndex; i++)	//shift array elements forward
				{
					parcel.setParName(i, parcel.getParName(i + 1));
					parcel.setParDest(i, parcel.getParDest(i + 1));
					parcel.setParDead(i, parcel.getParDead(i + 1));
				}

				for (int i = 0; i < printIndex - 1; i++)
				{
					if (i > 0)	//print next line after line0
						parcel_delete << "\n";

					parcel_delete << parcel.getParName(i) << " " << parcel.getParDest(i) << " " << parcel.getParDead(i);
				}

				cout << "Entry deleted successfully" << endl;
				parcel_delete.close();
	
			}

			else if (optionP == 3)
			{
				printTextFile(1);
				ofstream parcel_edit;
				parcel_edit.open("parcel.txt");

				if (parcel_edit.is_open())
				{
					cout << endl << "Name\tDestination\tDeadline" << endl;		//header after the file is read
					cout << "---------------------------------------------" << endl;
				}

				int sEntry, eEntry;
				string  temp;
				int editPDeadline;

				cout << endl << "Enter parcel index to edit: ";
				cin >> eEntry;		//input option to edit

						cout << endl << "1 - Name | 2 - Destination | 3 - Deadline" << endl;
						cout << "Select field to change: ";
						cin >> sEntry;		//input detail to edit

						switch (sEntry)
						{
						case 1:
							cout << "Enter new Name: ";
							cin >> temp;
							parcel.setParName(eEntry - 1, temp);	//editing the name
						//	package[i].getParcelName() = editPName;		
							break;

						case 2:
							cout << "Enter new Destination: ";
							cin >> temp;
							parcel.setParDest(eEntry - 1, temp);	//editing the destination
						//	package[i].getParcelDestination() = editPDestination;		
							break;

						case 3:
							cout << "Enter new Deadline: ";
							cin >> temp;
							parcel.setParDead(eEntry - 1, temp);	//editing the deadline
						//	package[i].getParcelDeadline() = editPDeadline;			
							break;

						default:
							cout << "Error encountered. Please enter another option.";
						}

						for (int i = 0; i < printIndex; i++)
						{
							if (i > 0)	//print next line after line0
								parcel_edit << "\n";

							parcel_edit << parcel.getParName(i) << " " << parcel.getParDest(i) << " " << parcel.getParDead(i);
						}

						cout << "Entry modified successfully" << endl;
						//	std::rename("schedule_new.txt", "schedule.txt");

						parcel_edit.close();

				printTextFile(1);

				cout << endl << "Entry edited successfully." << endl;
				//rename("parcels.txt", "parcels.txt");
				parcel_edit.close();

				cout << endl;		
			}

			else
			{
				cout << endl << "Invalid option. Please try again." << endl << endl;	
			}

			break;
		
		default: 
			cout << endl << "Error encountered. Please enter another option." << endl << endl;
		}
		menu();
	}
	cout << endl;
	cout << "        BBBBBB   Y       Y  EEEEEE          BBBBBB   Y       Y  EEEEEE           " << endl;
	cout << "        B     B   Y     Y   E               B     B   Y     Y   E                " << endl;
	cout << "        BBBBBB      Y Y     EEEEE           BBBBBB      Y Y     EEEEE            " << endl;
	cout << "        B     B      Y      E               B     B      Y      E                " << endl;
	cout << "        BBBBBB       Y      EEEEEE          BBBBBB       Y      EEEEEE           " << endl;
}

void readTextFile()
{
	printIndex = 0;
	string temp;
	ifstream text_file;

	text_file.open("parcel.txt");

	if (text_file.is_open())
		cout << "" << endl;

		while (!text_file.eof())
		{
			getline(text_file, temp, ' ');	//read the name and breaks at the comma
			parcel.setParName(printIndex, temp);
			getline(text_file, temp, ' ');	//read the destination and breaks at the comma
			parcel.setParDest(printIndex, temp);
			getline(text_file, temp);		//read the deadline
			parcel.setParDead(printIndex, temp);
			printIndex++;		
		}

	text_file.close();
}

void printTextFile(unsigned int sortP)
{
	if (sortP == 1)
	{
		cout << endl << "Name\t\tDestination\tDeadline" << endl;		//header for the input
		cout << "---------------------------------------------" << endl;
		//	for (int i = 0; i < package.size(); ++i)
		for (int i = 0; i < printIndex; i++)
		{
			//	cout << package[i].getParcelName() << "\t" << package[i].getParcelDestination() << "\t\t" << package[i].getParcelDeadline() << endl;
			cout << i + 1 << ": " << parcel.getParName(i) << "\t" << parcel.getParDest(i) << "\t\t" << parcel.getParDead(i) << endl;
		}

		cout << endl;

	}

	else if (sortP == 2)
	{
		cout << endl << "Destination\tName\t\tDeadline" << endl;		//header for the input
		cout << "---------------------------------------------" << endl;
		//	for (int i = 0; i < package.size(); ++i)
		for (int i = 0; i < printIndex; i++)
		{
			//	cout << package[i].getParcelDestination() << "\t\t" << package[i].getParcelName() << "\t" << package[i].getParcelDeadline() << endl;
			cout << i << ": " << parcel.getParDest(i) << "\t\t" << parcel.getParName(i) << "\t" << parcel.getParDead(i) << endl;
		}

		cout << endl;

	}

	else if (sortP == 3)
	{
		cout << endl << "Deadline\tName\t\tDestination" << endl;		//header for the input
		cout << "---------------------------------------------" << endl;
		//	for (int i = 0; i < package.size(); ++i)
		for (int i = 0; i < printIndex; i++)
		{
			//	cout << package[i].getParcelDeadline() << "\t\t" << package[i].getParcelName() << "\t" << package[i].getParcelDestination() << endl;
			cout << i << ": " << parcel.getParDead(i) << "\t\t" << parcel.getParName(i) << "\t" << parcel.getParDest(i) << endl;
		}

		cout << endl;

	}

	else
	{
		cout << endl << "Invalid option. Please try again." << endl << endl;
	}
}

//put readfile in main
//pass the variables to the class for storage
//use class to retrieve data
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
#include <numeric>
#include <sstream>
#include <iomanip>

using namespace std;

#include "Drone.h"
#include "Parcel.h"

void welcome(void);
void readTextFile();
void printTextFile(unsigned int);

Parcel parcel("", "", 1);
int printIndex = 0;

template <typename T>		//to match element within vector. Return boolean.
const bool Contains(vector<T>& Vec, const T& Element)
{
	return (find(Vec.begin(), Vec.end(), Element) != Vec.end()) ? true : false;
}

int option;

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
	cout << "10. Add/Delete/Edit parcel" << endl << endl;
	cout << "Key -1 To End Program" << endl << endl;
	cout << "Please enter your option: " << endl << ">";
	cin >> option;
	system("CLS");
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

	string nameParcel, destinationParcel;		//initialize variables to read file
	int deadlineParcel;
	  
	ifstream parcelFile("parcels.txt");		//read .txt file
	vector<Parcel> package;		//initialize vector
	{
		if (parcelFile)
		{
			while (parcelFile >> nameParcel >> destinationParcel >> deadlineParcel)
			{
				Parcel parcel(nameParcel, destinationParcel, deadlineParcel);		//register data to variables
				package.push_back(parcel);
			}
		}
	}

	vector<string> scheduleDeadline{ };		//initialize vectors for the scheduling
	vector<string> leftoverDeadline{ };
	vector<string> scheduleCapacity{ };
	vector<string> leftoverCapacity{ };

	welcome();		//show the welcome contents
	menu();		//show the menu contents

	while (option != -1)		//function repeats itself until user key in -1 to exit the program
	{
		switch (option)
		{
			case 1:
			{
				unsigned int sortD;

				cout << endl << "Display all ADD information" << endl;		//menu for the display function
				cout << "1 - Sort by Name | 2- Sort by Capacity | 3 - Sort by Destination | 4 - Sort by Deadline" << endl;
				cout << "Enter Option: ";
				cin >> sortD;

				if (sortD == 1)
				{
					vector<string> it;
					for (int i = 0; i < add.size(); i++)
					{
						string h;
						stringstream time;
						time << setfill('0') << setw(4) << add[i].getDroneDeadline();		//converting time into string with max 4 characters (filled with 0)
						h = (add[i].getDroneName() + "\t" + to_string(add[i].getDroneCapacity()) + "\t\t" + add[i].getDroneDestination() + "\t\t" + time.str());
						it.push_back(h);
					}

					sort(it.begin(), it.end());

					cout << endl << "Name\tCapacity\tDestination\tDeadline" << endl;		//header for the input
					cout << "-------------------------------------------------------" << endl;
					for (vector<string>::iterator i = it.begin(); i != it.end(); ++i)
					{
						cout << *i << endl;
					}

					cout << endl;
				}

				else if (sortD == 2)
				{
					vector<string> it;
					for (int i = 0; i < add.size(); i++)
					{
						string h;
						stringstream cap;
						cap << setfill(' ') << setw(3) << add[i].getDroneCapacity();		//converting time into string with max 4 characters (filled with 0)
						h = (" "+ cap.str() + "\t\t" + add[i].getDroneName() + "\t     " + to_string(add[i].getDroneCapacity()) + "\t\t" + add[i].getDroneDestination());
						it.push_back(h);
					}

					cout << endl << "Capacity\tName\tDestination\tDeadline" << endl;		//header for the input
					cout << "-------------------------------------------------------" << endl;
					sort(it.begin(), it.end());

					for (vector<string>::iterator i = it.begin(); i != it.end(); ++i)
					{
						cout << ' ' << *i << endl;
					}

					cout << endl;
				}

				else if (sortD == 3)
				{
					vector<string> it;
					for (int i = 0; i < add.size(); i++)
					{
						string h;
						h = (add[i].getDroneDestination() + "\t\t" + add[i].getDroneName() + "\t" + to_string(add[i].getDroneCapacity()) + "\t\t" + to_string(add[i].getDroneDeadline()));
						it.push_back(h);
					}

					cout << endl << "Destination\tName\tCapacity\tDeadline" << endl;		//header for the input
					cout << "-------------------------------------------------------" << endl;
					sort(it.begin(), it.end());

					for (vector<string>::iterator i = it.begin(); i != it.end(); ++i)
					{
						cout << *i << endl;
					}

					cout << endl;
				}

				else if (sortD == 4)
				{
					vector<string> it;
					for (int i = 0; i < add.size(); i++)
					{
						string h;
						stringstream time;
						time << setfill('0') << setw(4) << add[i].getDroneDeadline();		//converting time into string with max 4 characters (filled with 0)
						h = (time.str() + "\t\t" + add[i].getDroneName() + "\t" + to_string(add[i].getDroneCapacity()) + "\t\t" + add[i].getDroneDestination());
						it.push_back(h);
					}

					cout << endl << "Deadline\tName\tCapacity\tDestination" << endl;		//header for the input
					cout << "-------------------------------------------------------" << endl;
					sort(it.begin(), it.end());

					for (vector<string>::iterator i = it.begin(); i != it.end(); ++i)
					{
						cout << *i << endl;
					}

					cout << endl;
				}

				else
				{
					cout << endl << "Invalid option. Please try again." << endl << endl;		//outcome when user enters any other value
				}

				break;
			}

			case 2:
			{
				readTextFile();
				unsigned int sortP;
				cout << endl << "Display all Parcel information" << endl;		//menu for the display function
				cout << "1 - Sort by Name | 2 - Sort by Destination | 3 - Sort by Deadline" << endl;
				cout << "Enter Option: ";
				cin >> sortP;

				string parcelArray[999];			

				if (sortP == 1)
				{
					cout << endl << "Name\t\tDestination\tDeadline" << endl;		//header for the input
					cout << "-------------------------------------------------------" << endl;
				}

				else if (sortP == 2)
				{
					cout << endl << "Destination\tName\t\tDeadline" << endl;		//header for the input
					cout << "-------------------------------------------------------" << endl;
				}

				else if (sortP == 3)
				{
					cout << endl << "Deadline\tName\t\tDestination\t" << endl;		//header for the input
					cout << "-------------------------------------------------------" << endl;
				}

				else
				{
					cout << "Invalid option. Please try agian. \n";
				}

				for (int i = 0; i < printIndex; i++)
				{
					if (sortP == 1)
					{
						parcelArray[i] = parcel.getParName(i) + '\t' + parcel.getParDest(i) + '\t' + '\t' + parcel.getParDead(i) + "\n";
					}

					else if (sortP == 2)
					{
						parcelArray[i] = parcel.getParDest(i) + '\t' + '\t' + parcel.getParName(i) + '\t' + parcel.getParDead(i) + "\n";
					}

					else if (sortP == 3)
					{
						parcelArray[i] = parcel.getParDead(i) + '\t' + '\t' + parcel.getParName(i) + '\t' + parcel.getParDest(i) + "\n";
					}
				}
			
				vector<string> myVector(parcelArray, parcelArray + 999);
				std::sort(myVector.begin(), myVector.end());
				std::copy(myVector.begin(), myVector.end(), ostream_iterator<string>(cout, ""));

				cout << endl;

				break;
			}

			case 3:
			{
				scheduleDeadline.clear();		//clears the previous data in the vector to register a brand new schedule data
				leftoverDeadline.clear();

				for (int i = 0; i < package.size(); i++)
				{
					bool k = false;

					for (int j = 0; j < add.size(); j++)
					{
						if (add[j].getDroneDestination() != package[i].getDestinationParcel())		//stop name much match to continue
							continue;

						if ((add[j].getDroneDeadline() / 100 * 60 + (add[j].getDroneDeadline() % 100 + 15)) < ((package[i].getDeadlineParcel()) / 100 * 60 + (package[j].getDeadlineParcel()) % 100 - 30) ||
							(add[j].getDroneDeadline() / 100 * 60 + (add[j].getDroneDeadline() % 100 + 15)) > ((package[i].getDeadlineParcel()) / 100 * 60 + (package[j].getDeadlineParcel()) % 100))		//calculate the timing in minutes and must fit in the 30 seconds range to continue
							continue;

						if (add[j].getParcelCount() > add[j].getDroneCapacity())		//make sure the capacity doesn't exceed
							continue;

						add[j].parcelCounter(package[i].getNameParcel());		//adding 1 to the capacity of the drone
						scheduleDeadline.push_back(package[i].getNameParcel());		//register the parcel name
						scheduleDeadline.push_back(add[j].getDroneName());		//register the add name

						k = true;
						break;
					}

					if (k == false)
					{
						leftoverDeadline.push_back(package[i].getNameParcel());		//registering the parcels that are not scheduled
					}
				}

				cout << endl << "Scheduled success. Please select '6' to see the result." << endl << endl;		//inform user that the sorting is done

				break;
			}

			case 4:
			{
				scheduleCapacity.clear();		//clears the previous data in the vector to register a brand new schedule data
				leftoverCapacity.clear();

				for (int i = 0; i < package.size(); i++)
				{
					bool k = false;

					for (int j = add.size(); j >= 0; j--)
					{
						if (add[j - 1].getDroneDestination() != package[i].getDestinationParcel())		//stop name much match to continue
						{
							continue;
						}

						if (add[j - 1].getParcelCount() > add[j - 1].getDroneCapacity())		//make sure the capacity doesn't exceed
						{
							continue;
						}

						add[j - 1].parcelCounter(package[i].getNameParcel());		//adding 1 to the capacity of the drone
						scheduleCapacity.push_back(package[i].getNameParcel());		//register the parcel name
						scheduleCapacity.push_back(add[j - 1].getDroneName());		//register the add name

						k = true;
						break;
					}

					if (k == false)
					{
						leftoverCapacity.push_back(package[i].getNameParcel());		//registering the parcels that are not scheduled
					}
				}

				cout << endl << "Scheduled success. Please select '7' to see the result." << endl << endl;		//inform user that the sorting is done

				break;
			}

			case 5:
			{
				vector<string> notFull{ };
				vector<string> Full{ };
				vector<string> totalADD{ };

				unsigned int option1;
		
				cout << endl << "1 - Sorted by Deadline | 2 - Sorted by ADD" << endl;		//menu for the display function
				cout << "Enter Option: ";
				cin >> option1;

				switch (option1)	//comparing to check ADD scheduled by capacity is not full starts here
				{
					case 1:
					{
						cout << endl;

						for (int j = 0; j < add.size(); j++)		//total parcels
						{
							for (int k = 0; k < add[j].getDroneCapacity(); k++)
							{
								notFull.push_back(add[j].getDroneName());		//eg. if ADD01 has max cap of 2, it will push ADD01 twice into vector
							}
						}

						for (int k = 0; k < add.size(); k++)		//total ADDs
						{
							totalADD.push_back(add[k].getDroneName());		//pushing total ADDs into 'testing' vector 
						}

						for (int i = 0; i < scheduleCapacity.size(); i++)
						{
							if (Contains(totalADD, scheduleCapacity.at(i)))		//to match and obtain assigned scheduled ADD names 
							{
								Full.push_back(scheduleCapacity.at(i));		//to push assigned scheduled ADD names into 'Full' vector. 
							}
						}

						vector<string>::iterator lit;		//creating a temporary iterator vector

						for (int j = 0; j < (Full.size()); j++)
						{
							lit = find(notFull.begin(), notFull.end(), Full.at(j));		//to identify each scheduled element position in Total ADD+CAP list
							if (lit != notFull.end())		//if element is identified in Total ADD list
							{
								Full.erase(Full.begin() + (j));		//remove matched element from scheduled vector
								notFull.erase(notFull.begin() + (lit - notFull.begin()));		//remove scheduled vector from total ADD list
								--j;		//since an element has been removed, we will return back to previous counter, or else it will be skipping one element 
							}
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

							cout << notFull[i] << " is not full with " << count << " capacity left." << endl;
						}

						cout << endl;
						break;
					}

					case 2:		//comparing to check ADD scheduled by deadline is not full starts here. 
					{
						cout << endl;

						for (int j = 0; j < add.size(); j++)		//totalling ADD+CAP
						{
							for (int k = 0; k < add[j].getDroneCapacity(); k++)
							{
								notFull.push_back(add[j].getDroneName());		//eg. if ADD01 has max cap of 2, it will push ADD01 twice into vector
							}
						}

						for (int k = 0; k < add.size(); k++)		//total ADDs
						{
							totalADD.push_back(add[k].getDroneName());		//pushing total ADD names into 'Testing' vector
						}

						for (int i = 0; i < scheduleDeadline.size(); i++)
						{
							if (Contains(totalADD, scheduleDeadline.at(i)))		//comparing match for ADD 
							{
								Full.push_back(scheduleDeadline.at(i));		//totalling scheduled ADD+CAP
							}
						}

						vector<string>::iterator lit;		//creating a temporary iterator vector

						for (int j = 0; j < (Full.size()); j++)
						{
							lit = find(notFull.begin(), notFull.end(), Full.at(j));		//to identify each scheduled element position in Total ADD+CAP list
							if (lit != notFull.end())		//if element is identified in Total ADD list
							{
								Full.erase(Full.begin() + j);		//remove matched element from scheduled vector 
								notFull.erase(notFull.begin() + (lit - notFull.begin()));		//remove scheduled vector from total ADD list
								--j;		//since an element has been removed, we will return back to previous counter, or else it will be skipping one element 
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

					default:
					{
						cout << endl << "Invalid option. Please try again." << endl << endl;		//outcome when user enters any other value
					}
				}

				break;
			}

			case 6:
			{
				cout << endl;

				for (vector<string>::iterator i = scheduleDeadline.begin(); i != scheduleDeadline.end(); i += 2)		//reading data from scheduled vector
				{
					cout << *i << " is assigned to " << *(i + 1) << endl;
				}

				cout << endl;

				for (vector<string>::iterator i = leftoverDeadline.begin(); i != leftoverDeadline.end(); ++i)		//reading data from leftover vector
				{
					cout << *i << " is unassigned" << endl;
				}

				cout << endl;

				break;
			}

			case 7:
			{
				cout << endl;

				for (vector<string>::iterator i = scheduleCapacity.begin(); i != scheduleCapacity.end(); i += 2)		//reading data from scheduled vector
				{
					cout << *i << " is assigned to " << *(i + 1) << endl;
				}

				cout << endl;

				for (vector<string>::iterator i = leftoverCapacity.begin(); i != leftoverCapacity.end(); ++i)		//reading data from leftover vector
				{
					cout << *i << " is unassigned" << endl;
				}

				cout << endl;

				break;
			}

			case 8:
			{
				unsigned int save, saveC, saveD;

				cout << endl << "Save scheduling plan" << endl;		//menu for the save function
				cout << "1 - Sorted by Deadline | 2 - Sorted by minimum # of ADDs" << endl;
				cout << "Enter Option: ";
				cin >> save;

				if (save == 1)
				{
					{
						cout << "1 - Save assigned parcels | 2 - Save unassigned parcels" << endl;		//menu for the save deadline function
						cout << "Enter Option: ";
						cin >> saveD;

						if (saveD == 1)
						{
							ofstream output_file;
							output_file.open("assigned_parcels_deadline.txt");		//creating a new file to write

							if (output_file.is_open())
							{
								std::cout << endl << "File successfully created." << endl << endl;
								for (vector<string>::iterator i = scheduleDeadline.begin(); i != scheduleDeadline.end(); i += 2)		//writing the output into .txt file
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
							output_file.open("unassigned_parcels_deadline.txt");		//creating a new file to write

							if (output_file.is_open())
							{
								std::cout << endl << "File successfully created." << endl << endl;
								for (vector<string>::iterator i = leftoverDeadline.begin(); i != leftoverDeadline.end(); i += 2)		//writing the output into .txt file
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
							cout << endl << "Invalid option. Please try again." << endl << endl;		//outcome when user enters any other value
						}
					}
				}

				else if (save == 2)
				{
					{
						cout << "1 - Save assigned parcels | 2 - Save unassigned parcels" << endl;		//menu for the save capacity function
						cout << "Enter Option: ";
						cin >> saveC;

						if (saveC == 1)
						{
							ofstream output_file;
							output_file.open("assigned_parcels_capacity.txt");		//creating a new file to write

							if (output_file.is_open())
							{
								std::cout << endl << "File successfully created." << endl << endl;
								for (vector<string>::iterator i = scheduleCapacity.begin(); i != scheduleCapacity.end(); i += 2)		//writing the output into .txt file
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
							output_file.open("unassigned_parcels_capacity.txt");		//creating a new file to write

							if (output_file.is_open())
							{
								std::cout << endl << "File successfully created." << endl << endl;
								for (vector<string>::iterator i = leftoverCapacity.begin(); i != leftoverCapacity.end(); i += 2)		//writing the output into .txt file
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
							cout << endl << "Invalid option. Please try again." << endl << endl;		//outcome when user enters any other value
						}
					}
				}

				else
				{
					cout << endl << "Invalid option. Please try again." << endl << endl;		//outcome when user enters any other value
				}

				break;
			}

			case 9:
			{
				unsigned int optionD;

				cout << endl << "Add/Delete/Edit ADD" << endl;		//menu for the add/delete/edit function
				cout << "1 - Add ADD | 2 - Delete ADD | 3 - Edit ADD" << endl;
				cout << "Enter Option: ";
				cin >> optionD;

				if (optionD == 1)		//add function
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

					Drone drone(name, capacity, destination, deadline);
					add.push_back(drone);

					ofstream drone_add;
					drone_add.open("ADDs.txt", ios::app);

					if (drone_add.is_open())
					{
						drone_add << "\n" << name << " " << to_string(capacity) << " " << destination << " " << to_string(deadline);		//writing in the input
						cout << endl << "Entry recorded successfully." << endl << endl;
					}

					else
					{
						cout << "Error encountered. Please try again." << endl << endl;		//outcome when user enters any other value
					}

					drone_add.close();
				}

				else if (optionD == 2)		//delete function
				{
					ofstream drone_delete;
					drone_delete.open("ADDs.txt");

					if (drone_delete.is_open())
					{
						cout << endl << "Name\tCapacity\tDestination\tDeadline" << endl;		//header after the file is read
						cout << "------------------------------------------------------------" << endl;
					}

					for (int i = 0; i < add.size(); ++i)
					{
						cout << add[i].getDroneName() << "\t" << add[i].getDroneCapacity() << "\t\t" << add[i].getDroneDestination() << "\t\t" << add[i].getDroneDeadline() << endl;
					}

					string dEntry;

					cout << endl << "Enter ADD index to delete: ";
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

					cout << endl << "Entry deleted successfully." << endl << endl;
					drone_delete.close();
				}

				else if (optionD == 3)		//edit function
				{
					int sEntry, eEntry;
					string  dTemp;
					int intTemp;

					ofstream drone_edit;
					drone_edit.open("ADDs.txt");

					if (drone_edit.is_open())
					{
						cout << endl << "\tName\tCapacity\tDestination\tDeadline" << endl;		//header after the file is read
						cout << "------------------------------------------------------------" << endl;
					}

					for (int i = 0; i < add.size(); ++i)
					{
						cout << i + 1 << "\t" << add[i].getDroneName() << "\t" << add[i].getDroneCapacity() << "\t\t" << add[i].getDroneDestination() << "\t\t" << add[i].getDroneDeadline() << endl;
					}

					cout << endl << "Enter drone index to edit: ";
					cin >> eEntry;		//input option to edit

					cout << endl << "1 - Name | 2 - Capacity | 3 - Destination | 4 - Deadline" << endl;
					cout << "Select field to change: ";
					cin >> sEntry;		//input detail to edit

					switch (sEntry)
					{
						case 1:
						{
							cout << endl << "Enter new Name: ";
							cin >> dTemp;
							add[eEntry - 1].setdName(dTemp);		//editing the name

							break;
						}

						case 2:
						{
							cout << endl << "Enter new Capacity: ";
							cin >> intTemp;
							add[eEntry - 1].setdCapacity(intTemp);		//editing the destination

							break;
						}

						case 3:
						{
							cout << endl << "Enter new Destination: ";
							cin >> dTemp;
							add[eEntry - 1].setdDestination(dTemp);		//editing the deadline

							break;
						}

						case 4:
						{
							cout << endl << "Enter new Deadline: ";
							cin >> intTemp;
							add[eEntry - 1].setdDeadline(intTemp);		//editing the deadline
						}

						default:
						{
							cout << "Error encountered. Please enter another option.";		//outcome when user enters any other value
						}
					}

					for (int i = 0; i < add.size(); i++)
					{
						if (i > 0)		//print next line after line 0
							drone_edit << "\n";

						drone_edit << add[i].getDroneName() << " " << add[i].getDroneCapacity() << " " << add[i].getDroneDestination() << " " << add[i].getDroneDeadline();
					}

					cout << endl << "Entry modified successfully." << endl << endl;
					drone_edit.close();
				}

				else
				{
					cout << endl << "Invalid option. Please try again." << endl << endl;		//outcome when user enters any other value
				}
				
				break;
			}

			case 10:
			{
				readTextFile();

				unsigned int optionP;

				cout << endl << "Add/Delete/Edit parcel" << endl;		//menu for the add/delete/edit function
				cout << "1 - Add parcel | 2 - Delete parcel | 3 - Edit parcel" << endl;
				cout << "Enter Option: ";
				cin >> optionP;

				if (optionP == 1)		//add function
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

					Parcel parcel(name, destination, deadline);
					package.push_back(parcel);

					ofstream parcel_add;
					parcel_add.open("parcels.txt", ios::app);

					if (parcel_add.is_open())
					{
						parcel_add << "\n" << name << "\t " << destination << " " << to_string(deadline);		//writing in the input
						cout << endl << "Entry recorded successfully." << endl << endl;
					}

					else
					{
						cout << "Error encountered. Please try again." << endl << endl;		//outcome when user enters any other value
					}

					parcel_add.close();	
				}

				else if (optionP == 2)		//delete function
				{
					printTextFile(1);
					ofstream parcel_delete;
					parcel_delete.open("parcels.txt");

					unsigned int del;

					if (parcel_delete.is_open())
					{
						cout << "Select index to delete: ";
						cin >> del;		//input option to delete

						for (int i = del - 1; i < printIndex; i++)		//shift array elements forward
						{
							parcel.setParName(i, parcel.getParName(i + 1));
							parcel.setParDest(i, parcel.getParDest(i + 1));
							parcel.setParDead(i, parcel.getParDead(i + 1));
						}

						for (int i = 0; i < printIndex - 1; i++)
						{
							if (i > 0)		//print next line after line 0
							{
								parcel_delete << endl;
							}

							parcel_delete << parcel.getParName(i) << " " << parcel.getParDest(i) << " " << parcel.getParDead(i);
						}

						cout << endl << "Entry deleted successfully." << endl << endl;
						parcel_delete.close();
					}
				}

				else if (optionP == 3)		//edit function
				{
					printTextFile(1);
					ofstream parcel_edit;
					parcel_edit.open("parcels.txt");

					if (parcel_edit.is_open())
					{
						
					}

					int sEntry, eEntry;
					string  temp;
					int editPDeadline;

					cout << "Enter parcel index to edit: ";
					cin >> eEntry;		//input option to edit

					cout << endl << "1 - Name | 2 - Destination | 3 - Deadline" << endl;
					cout << "Select field to change: ";
					cin >> sEntry;		//input detail to edit

					switch (sEntry)
					{
						case 1:
						{
							cout << "Enter new Name: ";
							cin >> temp;
							parcel.setParName(eEntry - 1, temp);		//editing the name

							break;
						}
	
						case 2:
						{
							cout << "Enter new Destination: ";
							cin >> temp;
							parcel.setParDest(eEntry - 1, temp);		//editing the destination

							break;
						}

						case 3:
						{
							cout << "Enter new Deadline: ";
							cin >> temp;
							parcel.setParDead(eEntry - 1, temp);		//editing the deadline

							break;
						}

						default:
						{
							cout << "Error encountered. Please enter another option.";		//outcome when user enters any other value
						}
					}

					for (int i = 0; i < printIndex; i++)
					{
						if (i > 0)		//print next line after line 0
						{
							parcel_edit << "\n";
						}

						parcel_edit << parcel.getParName(i) << " " << parcel.getParDest(i) << " " << parcel.getParDead(i);
					}

					cout << endl << "Entry modified successfully." << endl << endl;
					parcel_edit.close();
				}

				else
				{
					cout << endl << "Invalid option. Please try again." << endl << endl;		//outcome when user enters any other value
				}

				break;
			}

			default:
			{
				cout << endl << "Error encountered. Please enter another option." << endl << endl;		//outcome when user enters any other value
			}
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

	text_file.open("parcels.txt");

	if (text_file.is_open())
		cout << "" << endl;

		while (!text_file.eof())
		{
			getline(text_file, temp, ' ');		//read the name and breaks at the comma
			parcel.setParName(printIndex, temp);
			getline(text_file, temp, ' ');		//read the destination and breaks at the comma
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
		cout << endl << "\tName\t\tDestination\tDeadline" << endl;		//header for the input
		cout << "--------------------------------------------------" << endl;

		for (int i = 0; i < printIndex; i++)
		{
			cout << i + 1 << "\t" << parcel.getParName(i) << "\t" << parcel.getParDest(i) << "\t\t" << parcel.getParDead(i) << endl;
		}

		cout << endl;
	}

	else if (sortP == 2)
	{
		cout << endl << "Destination\tName\t\tDeadline" << endl;		//header for the input
		cout << "---------------------------------------------" << endl;
		for (int i = 0; i < printIndex; i++)
		{
			cout << i << ": " << parcel.getParDest(i) << "\t\t" << parcel.getParName(i) << "\t" << parcel.getParDead(i) << endl;
		}

		cout << endl;
	}

	else if (sortP == 3)
	{
		cout << endl << "Deadline\tName\t\tDestination" << endl;		//header for the input
		cout << "---------------------------------------------" << endl;
		for (int i = 0; i < printIndex; i++)
		{
			cout << i << ": " << parcel.getParDead(i) << "\t\t" << parcel.getParName(i) << "\t" << parcel.getParDest(i) << endl;
		}

		cout << endl;
	}

	else
	{
		cout << endl << "Invalid option. Please try again." << endl << endl;
	}
}
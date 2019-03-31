// Dummy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Drone.h"
#include "Parcel.h"
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	Drone add;
	Parcel parcels;

	unsigned int option;

	//cout << "Wakanda Technologies and Logistics" << endl << endl;

	cout << "       __      __        __\n";
	cout << "      /  \\    /  \\ ____ |  | ____  ____    _____   ____ \n";
	cout << "      \\   \\/\\/   // __ \\|  |/ ___\\/  _ \\  /     \\ / __ \\\n";
	cout << "       \\        /|  ___/|  |  \\__(  <_> )|  Y Y  \|  ___/\n";
	cout << "        \\__/\\__/  \\____\\|__|\\_____>____/ |__|_|__|\\____\\\n";
	cout << "\n";

	cout << "1. Display all ADD information" << endl;
	cout << "2. Display all parcels information" << endl;
	cout << "3. Schedule all parcels (by Dealine)" << endl;
	cout << "4. Schedule all parcels (minimum # of ADDs)" << endl;
	cout << "5. Display ADDs that are not full" << endl;
	cout << "6. Display final scheduling plan sorted by ADDs" << endl;
	cout << "7. Display final scheduling plan sorted by parcels" << endl;
	cout << "8. Save scheduling plan" << endl;
	cout << "9. Add/Delete/Edit ADD" << endl;
	cout << "10. Add/Delete/Edit parcel" << endl << endl;

	cout << "Please enter your option: " << endl << ">";
	cin >> option;

	switch (option)
	{
	case 1:
		unsigned int sort1;

		cout << endl << "Display all add information" << endl;
		cout << "1 - Sort by Name | 2- Sort by Capacity | 3 - Sort by Destination | 4 - Sort by Deadline" << endl;
		cout << "Enter Option: ";
		cin >> sort1;

		add.displayDroneContent(sort1);
		cout << endl;
		main();		//return to main menu

		break;

	case 2:
		unsigned int sortP;

		cout << endl << "Display all parcels information" << endl;
		cout << "1 - Sort by Name | 2 - Sort by Destination | 3 - Sort by Deadline" << endl;
		cout << "Enter Option: ";
		cin >> sortP;

		parcels.displayParcelContent(sortP);
		cout << endl;
		main();		//return to main menu

		break;

	case 3:

		break;

	case 4:

		break;

	case 5:cout << "5";

		break;

	case 6:cout << "6";

		break;

	case 7:cout << "7";

		break;

	case 8:cout << "8";

		break;

	case 9:
		unsigned int optionD;

		cout << endl << "Add/Delete/Edit ADD" << endl;
		cout << "1 - Add ADD | 2 - Delete ADD | 3 - Edit ADD" << endl;
		cout << "Enter Option: ";
		cin >> optionD;

		if (optionD == 1)
		{
			add.insertDroneEntry();
			cout << endl;
			main();		//return to main menu
		}
		
		else if (optionD == 2)
		{
			add.deleteDroneEntry();
			cout << endl;
			main();		//return to main menu
		}

		else if (optionD == 3)
		{
			add.editDroneEntry();
			cout << endl;
			main();		//return to main menu
		}
		
		else
		{
			cout << endl << "Invalid option. Please try again." << endl << endl;
			main();		//return to main menu
		}
		
		break;

	case 10:
		unsigned int optionP;

		cout << endl << "Add/Delete/Edit parcel" << endl;
		cout << "1 - Add parcel | 2 - Delete parcel | 3 - Edit parcel" << endl;
		cout << "Enter Option: ";
		cin >> optionP;

		if (optionP == 1)
		{
			parcels.insertParcelEntry();
			cout << endl;
			main();		//return to main menu
		}

		else if (optionP == 2)
		{
			parcels.deleteParcelEntry();
			cout << endl;
			main();		//return to main menu
		}

		else if (optionP == 3)
		{
			parcels.editParcelEntry();
			cout << endl;
			main();		//return to main menu
		}

		else
		{
			cout << endl << "Invalid option. Please try again." << endl << endl;
			main();		//return to main menu
		}

		break;

	default:
		cout << endl << "Error encountered. Please enter another option." << endl << endl;
		main();		//return to main menu
	}
}


//--------------------------------------------------


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file










/*#include "Schedule.h"

#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	Schedule sch;

	unsigned int option;

	cout << "Wakanda Technologies and Logistics\n\n";
	cout << "1. View Schedules\n";
	cout << "2. Insert Schedule Entry\n";
	cout << "3. Modify Schedule Entry\n";
	cout << "4. Delete Schedule Entry\n";
	cout << "5. View Drones\n";
	cout << "6. Add Drones\n";
	cout << "7. Delete Drones\n";
	cout << "\nSelect an option: ";
	cin >> option;


		switch (option)
		{
		case 1:
			unsigned int sort;
			cout << "1 - Sort by Name, 2 - Sort by Destination, 3 - Sort by Deadline\nEnter Option: ";
			cin >> sort;
			sch.displayContent(sort);
			main();
			break;
		case 2:
			sch.insertEntry();
			main();
			break;
		case 3:
			sch.editEntry();
			main();
			break;
		case 4:
			sch.deleteEntry();
			main();
			break;
		case 5:cout << "5";
			break;
		case 6:cout << "6";
			break;
		case 7:cout << "7";
			break;
		case 8:cout << "8";
			break;
		case 9:cout << "9";
			break;
		default: cout << "default";
		}	
	}



//void OptionOne();
//void OptionTwo();


/*
display all add info
display parcel info
schedule by deadline
schedule by minimum no. of add
display adds that are not full
display final shceudlnig plan srted by addds
display final scheduling plan sorted by parcels
save schedulng plan
modify add
modify parcel
*/


/*
Display ALL INFO
Scheduling

Fleet
	-Show all Drones
	-S

*/

//sample method

//void Schedule(int argument); //argument = choice number in menu*/
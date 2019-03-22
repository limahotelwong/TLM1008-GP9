#include "Schedule.h"

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

//void Schedule(int argument); //argument = choice number in menu


#ifndef PARCEL_CPP
#define PARCEL_CPP

#include "Parcel.h"

using namespace std;

int parcelValue = 0;
int  z = 0;

Parcel::Parcel()
{

}

Parcel::Parcel(string pName, string pDestination, int pDeadline)
{
	nameParcel = pName;
	destinationParcel = pDestination;
	deadlineParcel = pDeadline;
}

string Parcel::getNameParcel()
{
	return nameParcel;
}

string Parcel::getDestinationParcel()
{
	return destinationParcel;
}

int Parcel::getDeadlineParcel()
{
	return deadlineParcel;
}

void Parcel::setParName(int index, string name)
{
	parcelName[index] = name;
}
void Parcel::setParDest(int index, string dest)
{
	parcelDest[index] = dest;
}
void Parcel::setParDead(int index, string dead)
{
	parcelDead[index] = dead;
}

void Parcel::setParcelArray(int index, string name, string dest, string dead, int type)
{
	if (type == 1)
		parcelArr[index] = name + "\t" + dest + "\t" + dead;
	else if (type == 2)
		parcelArr[index] = dest + "\t" + name + "\t" + dead;
	else if (type == 3)
		parcelArr[index] = dead + "\t" + name + "\t" + dest;
	else
		parcelArr[index] = name + "\t" + dest + "\t" + dead;
}

string Parcel::getParName(int i)
{
	return parcelName[i];
}
string Parcel::getParDest(int i)
{
	return parcelDest[i];
}
string Parcel::getParDead(int i)
{
	return parcelDead[i];
}

string * Parcel::getParcelArr(string arr[])
{
	return parcelArr;
}
#endif


//#include "stdafx.h"
#include "student.h"
#include <iostream>

using namespace std;


Student::Student(int MNum, string Name, string Major)
{
	MNumber = MNum;
	name = Name;
	major = Major
	//unitOfMeasure = unitOfMeas;
	//quantityOnHand = 0;
}

/*
Part::Part(int partNum, string descrip, double p, string unitOfMeas, int quanOnHand)
{
	partNumber = partNum;
	description = descrip;
	price = p;
	unitOfMeasure = unitOfMeas;
	quantityOnHand = quanOnHand;
}
*/

string Student::getStudentInfo()
{
	return to_string(MNumber) + name;
}

string Student::getMNumber()
{
	return "M" + MNumber;
}

/*
bool Student::inStock()
{
	if (quantityOnHand > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
*/

/*
bool Part::available(int date)				// Edits here!
{
	if (Part::inStock())
	{
		return true;
	}
	else
	{
		return false;
	}
}
*/

bool Student::operator > (const Student &right)
{
	if (MNumber > right.MNumber)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Student::operator < (const Student &right)
{
	if (MNumber < right.MNumber)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Student::operator == (const Student &right)
{
	if (MNumber == right.MNumber)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Student::operator != (const Student &right)
{
	if (MNumber != right.MNumber)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Student::longestString(string a, string b, string c, string d) {
	int length = a.length();
	if (b.length() > length)
		length = b.length();
	if (c.length() > length)
		length = c.length();
	if (d.length() > length)
		length = d.length();
	return length;
}

string Student::middleMaker(int size) {
	string middle = "";
	for (int i = 0; i < size; i++) {
		middle += " ";
	}
	return middle;
}

void Student::displayStudents() {
	string mnum = phrases[0] + "M" + to_string(MNumber);
	string name_ = phrases[1] + name;
	string major_ = phrases[2] + major;
	string top, bottom, middle = "";
	string rightBor = "=  ";
	string leftBor = "  =";
	int len = longestString("M" + to_string(MNumber), name, major);
	for (int i = 0; i < len + 6; i++) {
		top += "=";
	}
	bottom = top;
	cout << top + "\n";
	cout << rightBor + middleMaker(len) + leftBor + "\n";
	cout << rightBor + mnum + middleMaker(len - mnum.length()) + leftBor + "\n";
	cout << rightBor + middleMaker(len) + leftBor + "\n";
	cout << rightBor + name_ + middleMaker(len - name_.length()) + leftBor + "\n";
	cout << rightBor + middleMaker(len) + leftBor + "\n";
	cout << rightBor + major_ + middleMaker(len - major_.length()) + leftBor + "\n";
	cout << rightBor + middleMaker(len) + leftBor + "\n";
	cout << bottom + "\n";
}

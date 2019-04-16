//#include "stdafx.h"
#include "student.h"
#include <iostream>
#include <sstream>

using namespace std;

Student::Student(string MNum)
{
	MNumber = MNum;
	name = " ";
	major = " ";
}

Student::Student(string MNum, string Name, string Major)
{
	MNumber = MNum;
	name = Name;
	major = Major;

}

string Student::getStudentInfo()
{
	return MNumber + name;
}

string Student::getMNumber()
{
	/*ostringstream os;
	os << "M" << MNumber;
	return os.str();*/
	return MNumber;
}

void Student::setMNumber(string mnum)
{
	MNumber = "M" + mnum;
	return;
}

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
	string mnum = phrases[0] + "M" + MNumber;
	string name_ = phrases[1] + name;
	string major_ = phrases[2] + major;
	string top, bottom, middle = "";
	string rightBor = "=  ";
	string leftBor = "  =";
	int len = longestString("M" + MNumber, name, major, "");
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

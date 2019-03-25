#include "stdafx.h"
#include "Part.h"
#include <iostream>

using namespace std;


Part::Part(int partNum, string descrip, double p, string unitOfMeas)
{
	partNumber = partNum;
	description = descrip;
	price = p;
	unitOfMeasure = unitOfMeas;
	quantityOnHand = 0;
}

Part::Part(int partNum, string descrip, double p, string unitOfMeas, int quanOnHand)
{
	partNumber = partNum;
	description = descrip;
	price = p;
	unitOfMeasure = unitOfMeas;
	quantityOnHand = quanOnHand;
}

string Part::getPartInfo()
{
	return to_string(partNumber) + description;
}

double Part::getPrice()
{
	return price;
}

bool Part::inStock()
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

bool Part::operator > (const Part &right)
{
	if (partNumber > right.partNumber)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

bool Part::operator < (const Part &right)
{
	if (partNumber < right.partNumber)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

bool Part::operator == (const Part &right)
{
	if (partNumber == right.partNumber)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

bool Part::operator != (const Part &right)
{
	if (partNumber != right.partNumber)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Part::longestString(string a, string b, string c, string d) {
	int length = a.length();
	if (b.length() > length)
		length = b.length();
	if (c.length() > length)
		length = c.length();
	if (d.length() > length)
		length = d.length();
	return length;
}

string Part::middleMaker(int size) {
	string middle = "";
	for (int i = 0; i < size; i++) {
		middle += " ";
	}
	return middle;
}

void Part::displayProd() {
	string part = phrases[0] + to_string(partNumber);
	string desc = phrases[1] + description;
	string priceStr = phrases[2] + "$" + to_string(price);
	string quan = phrases[3] + to_string(quantityOnHand);
	string top, bottom, middle = "";
	string rightBor = "=  ";
	string leftBor = "  =";
	int len = longestString(part, desc, priceStr, quan);
	for (int i = 0; i < len + 6; i++) {
		top += "=";
	}
	bottom = top;
	cout << top + "\n";
	cout << rightBor + middleMaker(len) + leftBor + "\n";
	cout << rightBor + part + middleMaker(len - part.length()) + leftBor + "\n";
	cout << rightBor + middleMaker(len) + leftBor + "\n";
	cout << rightBor + desc + middleMaker(len - desc.length()) + leftBor + "\n";
	cout << rightBor + middleMaker(len) + leftBor + "\n";
	cout << rightBor + priceStr + middleMaker(len - priceStr.length()) + leftBor + "\n";
	cout << rightBor + middleMaker(len) + leftBor + "\n";
	cout << rightBor + quan + middleMaker(len - quan.length()) + leftBor + "\n";
	cout << rightBor + middleMaker(len) + leftBor + "\n";
	cout << bottom + "\n";
}

#include "stdafx.h"
#include "Part.h"

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

bool Part::available(int date)
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

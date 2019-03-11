#ifndef PART_H
#define PART_H
#include <string>

using namespace std;

class Part
{

	private:
		int partNumber;
		string description;
		double price;
		string unitOfMeasure;
		int quantityOnHand;
		int leadTime;

	public:
		Part(int partNumber, string description, double price, string unitOfMeasure);
		Part(int partNumber, string description, double price, string unitOfMeasure, int quantityOnHand);
		string getPartInfo();
		double getPrice();
		bool inStock();
		bool available(int date);
		bool operator > (const Part &right);
		bool operator < (const Part &right);
		bool operator == (const Part &right);

};

#endif

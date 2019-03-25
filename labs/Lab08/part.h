#ifndef PART_H
#define PART_H
#include <string>

using namespace std;

class Part
{

	private:
		int partNumber;
		string description;
		string phrases[4] = { "Part Number: ","Description: ","Price: ","Quantity On Hand: " };
		double price;
		string unitOfMeasure;
		int quantityOnHand;
		int leadTime = 7;				// Default lead time is 1 week
		int longestString(string a, string b, string c, string d);
		string middleMaker(int size);

	public:

		Part(int partNumber, string description, double price, string unitOfMeasure);
		Part(int partNumber, string description, double price, string unitOfMeasure, int quantityOnHand);
		void displayProd();
		string getPartInfo();
		double getPrice();
		bool inStock();
		bool available(int date);
		bool operator > (const Part &right);
		bool operator < (const Part &right);
		bool operator == (const Part &right);
		bool operator != (const Part &right);
};
#endif

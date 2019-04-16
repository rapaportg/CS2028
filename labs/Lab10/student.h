#ifndef STUDENT_H
#define STUDENT_H
#include <string>

using namespace std;

class Student
{

	private:
		int 	MNumber;
		string 	name;
		string	major;
		string 	phrases[4] = { "Part Number: ","Description: ","Price: ","Quantity On Hand: " };
		//double 	price;
		//string 	unitOfMeasure;
		//int 	quantityOnHand;
		//int 	leadTime = 7;				// Default lead time is 1 week
		int 	longestString(string a, string b, string c, string d);
		string 	middleMaker(int size);

	public:

		Student(string mnum);
		Student(int mnum, string name, string maj);
		//Part(int partNumber, string description, double price, string unitOfMeasure, int quantityOnHand);
		void 	displayStudents();
		string 	getStudentInfo();
		string 	getMNumber();
		void	setMNumber(string tmp);
		//bool 	inStock();
		//bool 	available(int date);
		bool 	operator > (const Student &right);
		bool 	operator < (const Student &right);
		bool 	operator == (const Student &right);
		bool 	operator != (const Student &right);
};
#endif

#include <iostream>
#include <string>
#include "Inventory.h"

using namespace std;


//int ID;
//int units;
//double price;
//string description;
//bool TaxExempt;
int Inventory::getID() {return ID;}

int Inventory::getUnits() {return units;}

double Inventory::getPrice() {return price;}
        
string Inventory::getDescription() {return description;}

bool Inventory::getTaxExempt() {return TaxExempt;}

string Inventory::getTaxExempt_str() 
{   
    string t = "True";
    string f = "False";
    if(TaxExempt == true)
        return t;
    else 
        return f;
}

void Inventory::setID(int ID_in) {ID = ID_in;}

void Inventory::setID_str(string ID_in) 
{
    ID = atoi(ID_in.c_str());
}

void Inventory::setUnits(int units_in) {units = units_in;}

void Inventory::setUnits_str(string units_in)
{
    units = atoi(units_in.c_str());
}

void Inventory::setPrice(double price_in) {price = price_in;}

void Inventory::setPrice_str(string price_in)
{
    price = atof(price_in.c_str());
}
        
void Inventory::setDescription(string desc) {description = desc;}

void Inventory::setTaxExempt(bool x) {TaxExempt = x;}

void Inventory::setTaxExempt_str(string tax)
{
    if (tax == "True")
    {
        TaxExempt = true;
    }
    else
        TaxExempt = false;
}

//Inventory(ID(0), price(0), units(0), description(""), TaxExempt(NULL)) {}

Inventory::Inventory(int ID_in, int units_in, double price_in, string description_in, bool tax)
{
    ID = ID_in;
    units = units_in;
    price = price_in;
    description = description_in;
    TaxExempt = tax;
}



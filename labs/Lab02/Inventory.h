#ifndef INVENTORY_H
#define INVENTORY_H
#include <string>

class Inventory
{
    private:
        int ID;
        int units;
        double price;
        std::string description;
        bool TaxExempt;

    public:
        Inventory() {};
        Inventory(int ID_in);
        Inventory(int ID_in, int units_in, double price_in, std::string description_in, bool tax);
        int getID();
        int getUnits();
        double getPrice();
        std::string getDescription();
        bool getTaxExempt();
        std::string getTaxExempt_str();
        void setID(int ID_in);
        void setID_str(std::string ID_in);
        void setUnits(int units_in);
        void setUnits_str(std::string units_in);
        void setPrice(double price_in);
        void setPrice_str(std::string price_in);
        void setDescription(std::string desc);
        void setTaxExempt(bool x);
        void setTaxExempt_str(std::string tax);
        
};

#endif
#include <string>
#include <iostream>
#include <fstream>
#include "Inventory.h"

using namespace std;

string getFileName(int rw) // rw- for read = 0, For write = 1  
{
    fstream file;
    string filename;
    bool check;

    if (rw == 0) // for read 
    {
        do
        {
            cout << "\nEnter the name of the in File  (Q to quit): \n";
            cin >> filename;
            if (filename == "Q")
                return NULL;
            file.open(filename, ios::in);
            check = file.good();
            if (check == false)
                cout << "Error File Does Not Exist!\n";
            file.close();
        } while(!check);
    }
    else if (rw == 1) // for write
    {
        cout << "\nEnter the name of the out File  (Q to quit): \n";
        cin >> filename;
        if (filename == "Q")
            return NULL;
        file.open(filename, ios::in);
        check = file.good();
        if (check == false)
            file.open(filename, ios::app);
        file.close();
    }

    return (filename);
}

// makes test file
void writeInventory(string outfilename, Inventory i)
{
    string tmp;
    fstream outfile;

    outfile.open(outfilename, ios::app);
    outfile << "ID: " << i.getID() << endl;
    outfile << "Units: " << i.getUnits() << endl;
    outfile << "Price: " << i.getPrice() << endl;
    outfile << "Description: " << i.getDescription() << endl;
    outfile << "TaxExempt: " << i.getTaxExempt_str() << endl << endl;
    outfile.close(); 
}

// bool checkInfileFormat(string infilename) // check to see if the infile has the appropriate information for
// Inventory class
string getWantedInfileStr(fstream *infile)
{
    string tmp_str;
    char tmp_ch = 'a';

    while (tmp_ch != ' ' && !(*infile).eof())
    {
        (*infile).get(tmp_ch);
    }
    getline(*infile, tmp_str);
    return tmp_str;
}

// checks to see to there are enough lines and sections for the required input parameter
int checkInfileFormat(string infilename)
{
    string tmp;
    fstream infile;
    int i = 0;

    infile.open(infilename, ios::in);
    while (!infile.eof())
    {
        i++;
        getline(infile, tmp);  
    }
    if (i / 6 == 9)
        return i;
    else 
        return 0;
}

int main()
{
    string outfilename;
    string infilename;
    string tmp;
    char lazyF;
    fstream infile;
    Inventory i[9];
    int count;
    int j = 0;
    
    // I got lazy and didnt feel like making a test file by hand
    cout << "Need a test file? Y/N: ";
    cin >> lazyF;
    if (lazyF == 'Y')
    {
        Inventory thing[9] = {  {1234, 2, 34.99, "I am Number 1", true},
                                {1233, 001, 54.95, "Rick Sanchez bobble head", false},
                                {1221, 030, 1000.99, "Mr. PoopyHead", true},
                                {1233, 001, 54.95, "Rick Sanchez bobble head", false},
                                {1221, 030, 1000.99, "Mr. PoopyHead", true},
                                {1233, 001, 54.95, "Rick Sanchez bobble head", false},
                                {1221, 030, 1000.99, "Mr. PoopyHead", true},
                                {1233, 001, 54.95, "Rick Sanchez bobble head", false},
                                {1221, 030, 1000.99, "Mr. PoopyHead", true}};
        int i = 0;
        outfilename = getFileName(1);
        while (i < 9)
        {
            writeInventory(outfilename, thing[i]);
            i++;
        }
    }

    infilename = getFileName(0);
    count = checkInfileFormat(infilename);
    
    if (count == 0)
    {
        cout << "Invaild In file format\n";
        return 0;
    }
    else
    {
        infile.open(infilename, ios::in);
        while (j < 9)
        {
            i[j].setID_str(getWantedInfileStr(&infile));
            cout << endl << i[j].getID() << endl;
            i[j].setUnits_str(getWantedInfileStr(&infile));
            cout << i[j].getUnits() << endl;
            i[j].setPrice_str(getWantedInfileStr(&infile));
            cout << i[j].getPrice() << endl;
            i[j].setDescription(getWantedInfileStr(&infile));
            cout << i[j].getDescription() << endl;
            i[j].setTaxExempt_str(getWantedInfileStr(&infile));
            cout << i[j].getTaxExempt_str() << endl << endl;
            getline(infile, tmp);
            j++;
        }
        infile.close();
    }
    return 0;
}
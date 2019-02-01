#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// string getFileName() Function to get file name from user and see if it exist
string getFileName(int rw) // rw- for read = 0, For write = 1  
{
    fstream file;
    string filename;
    bool check;

    if (rw == 0) // for task 1
    {
        do
        {
            cout << "\nEnter the name of the in File  (Q to quit): \n";
            cin >> filename;
            if (filename == "Q" || filename == "q")
                return NULL;
            file.open(filename, ios::in);
            check = file.good();
            if (check == false)
                cout << "Error File Does Not Exist!\n";
            file.close();
        } while(!check);
    }
    else if (rw == 1) // for task 2
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

// void displayFirstTen(string filename) // read and prints the first 10 lines of a file
void displayFirstTen(string filename)
{
    string tmp;
    fstream file; 
    int i = 1;

    file.open(filename, ios::in);
    while (i <= 10)
    {
        getline(file, tmp);
        cout << i++ << ". " << tmp << endl;
    }
}

void writeToOutFile(string infilename, string outfilename)
{
    string tmp;
    fstream infile;
    fstream outfile;
    int i = 1;

    infile.open(infilename, ios::in);
    outfile.open(outfilename, ios::app);
    while(i <= 10)
    {
        getline(infile, tmp);
        outfile << tmp << endl;
        i++;
    }
}

int main()
{
    string infile;
    string outfile;
    
    infile = getFileName(0);
    displayFirstTen(infile);
    //cout << inename << endl;

    // task 2
    outfile = getFileName(1);
    writeToOutFile(infile, outfile);
    //cout << outfile << endl;
    return 0;
}
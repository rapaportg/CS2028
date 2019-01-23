#include "hw1.h"
#include <string.h>
#include <iomanip>
#include <fstream>
#include <ifstream">
#include <iostream>
#include <vector>

using namespace std;

// get file name and check to see if it exists
string getfilename() {


}

// read file, print: (on rubric)
void printBookInfo(fstream file) {


}

// 
void printWordCount(fstream file) {
    
}

//


//


//



/*
string enterFile()
{
    bool check = false;
    string filename;
    ifstream infile;

    while (!check)
    {
        cout << "Enter the file to be read: " << endl;
        cin >> filename;
        infile(filename);
        check = infile.good();
    }
    infile.close();
    return filename;
}

int main(void)
{
    string fileName;
    string temp;
    char tmp;
    char tmp2;
    fstream file;
    story book;
    int linecount = 0;
    int wordcount = 0;

    cout << endl << "Opening File: " << fileName << endl;
    
    file.open(fileName, ios::in);
    while (!file.eof())
    {
        if (linecount == 0)
        {
            getline(file, book.title);
            getline(file, temp);
            book.author = temp;
            book.authorF = temp.substr(0, temp.find(' '));
            book.authorL = temp.substr(temp.find(' ')+1);
            linecount++;
        }
        getline(file, temp);
        linecount++;
    }
    file.close();
    book.linecount = linecount;
    cout << book.title << endl << book.author << endl << book.authorF << endl << book.authorL << endl << book.linecount << endl;

    file.open(fileName, ios::in);
    while (!file.eof())
    {
        file.get(tmp);
        if (tmp == ' ' || (tmp == '\n' && tmp2 != '\n'))
            wordcount++;
        tmp2 = tmp;
    }
    cout << wordcount << endl;
    return 0;
}
*/
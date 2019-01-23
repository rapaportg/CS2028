#include "hw1.h"
#include <string.h>
#include <iomanip>
#include <fstream>
#include <ifstream">
#include <iostream>
#include <vector>

using namespace std;

<<<<<<< HEAD
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


=======

//  string getFileName()  get file name and check if it exist. if so return filename.

// void printBooKInfo(fstream file) reads file, print: title, authors name, and line count

// void printWordCount(fstream file) read file, print word count, returns word count

// float[] findLetterFreq(fstream file) letter frequency, array[26] read pdf return array

// void putLetterFreq(array[] x) print letter frequency array 

// bool isUpper(char c). returns bool

// bool catelogExist("CardCatalog.txt") if not make it.

// void printToCatelog(story x). added story entry to catelog.
>>>>>>> f76da0a56f8d3c9548d4082ea3c404e398800e6d

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
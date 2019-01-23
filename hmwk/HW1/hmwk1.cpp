#include "hw1.h"
#include <string.h>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;


//  string getFileName()  get file name and check if it exist. if so return filename.
string getFileName() // DONE
{
    string input;
    bool check;

    do
    {
        cout << "Enter the name of the file: " << endl;
        cin >> input;
        ifstream f(input.c_str());
        check = f.good();
        if (check == false)
        {
            cout << "Error... File does not exist" << endl << endl;
        }

    }while(!check);
    return input;

}

// void printBooKInfo(fstream file) reads file, print: title, authors name, and line count
void printBookInfo(string fileName, struct story* book) 
{
    string temp;
    char tmp;
    char tmp2;
    fstream file;
    //story book;
    int linecount = 0;
    int wordcount = 0;

    cout << endl << "Opening File: " << fileName << endl << endl;;
    
    file.open(fileName, ios::in);
    while (!file.eof())
    {
        if (linecount == 0)
        {
            getline(file, book->title);
            getline(file, temp);
            book->author = temp;
            book->authorF = temp.substr(0, temp.find(' '));
            (*book).authorL = temp.substr(temp.find(' ')+1); // (*book).authorL is the same as book->authorL
            linecount++;
        }
        getline(file, temp);
        linecount++;
    }
    file.close();
    book->linecount = linecount;

    file.open(fileName, ios::in);
    while (!file.eof())
    {
        file.get(tmp);
        if (tmp == ' ' || (tmp == '\n' && tmp2 != '\n'))
            wordcount++;
        tmp2 = tmp;
    }
    book->wordcount = wordcount;
    file.close();

    cout << "Title: " << book->title << endl << "Full Author: " << book->author << endl << "Author First Name: " << book->authorF << endl << "Author Last Name: " << book->authorL << endl << "Word Count: " << book->wordcount << endl << "Line Count: " << book->linecount << endl << endl;

}

// void printWordCount(fstreamd file) read file, print word count, returns word count
void printWordCount(string filename)
{
    
    
}

// float[] findLetterFreq(fstream file) letter frequency, array[26] read pdf return array
story findLetterFreq(string filename) 
{

}

// void putLetterFreq(array[] x) print letter frequency array 
void putLetterFreq(story x) 
{

}

// bool isUpper(char c). returns bool
bool isUpper(char c) 
{
    if (c >= 'A' && c <= 'Z')
        return true;
    return false;
}

// bool catalogExist("CardCatalog.txt") if not make it. DONE
inline bool catalogExist() 
{
    string filename = "CardCatalog.txt";
    ifstream f(filename.c_str());
    return f.good();
}

// void printToCatalog(story x). added story entry to catelog.
void printToCatalog(story x)
{

}

int main()
{
    story book;
    string temp;
    temp = getFileName();
    printBookInfo(temp, &book);
    cout << catalogExist() << endl;
    cout << temp << endl;
    return 0;
}

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
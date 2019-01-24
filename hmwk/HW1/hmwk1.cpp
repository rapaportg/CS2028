#include "hw1.h"
#include <string.h>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

//  string getFileName()  get file name and check if it exist. if so return filename.
string  getFileName() // DONE
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
void    printBookInfo(string fileName, struct story* book) //DONE
{
    string temp;
    char tmp;
    char tmp2;
    fstream file;
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

// float[] findLetterFreq(fstream file) letter frequency, array[26] read pdf return array
void    findLetterFreq(string filename, struct story* book) //DONE
{
    //cout << "A\n";
    fstream file;
    char ch;
    unsigned int index = 25;

    file.open(filename, ios::in);
    while (index--)
    {
        (*book).letterFreq[index] = 0;
    }
    file.close();
    //cout << "B\n";
    file.open(filename, ios::in);
    while (!file.eof())
    {
        file.get(ch);
        if (isUpper(ch) && !isPunct(ch) && ch != '\n')
        {
            index = ch - 'A';
            //cout << index << endl;
            (*book).letterFreq[index] = (*book).letterFreq[index] + 1;
        }
        else if (!isPunct(ch) && ch != '\n')
        {
            index = ch - 'a';
            //cout << index << endl;
            (*book).letterFreq[index] = (*book).letterFreq[index] + 1;
        }
        //cout << "C\n";  
       // cout << ch << endl;
    }
    file.close();
}

// void putLetterFreq(array[] x) print letter frequency array 
void    putLetterFreq(struct story* book) //DONE
{
    int i = 26;
    int letterSum = 0;
    char letter;

    while (--i)
    {
        letterSum += (*book).letterFreq[i]; 
    }
    cout << endl << (*book).title << " letter frequency:\n";
    while (i < 26)
    {   
        letter = 'a' + i;
        cout << letter << ": " << ((*book).letterFreq[i]/(letterSum)) * 100 << "%" << endl;
        ++i;
    }
}

// bool isUpper(char c). checks for uppercase letters
bool    isUpper(char c) 
{
    if (c >= 'A' && c <= 'Z')
        return true;
    return false;
}

// bool isPunct(char c). checks for punctuation
bool    isPunct(char c)
{
    return ((c >= 32 && c <= 63) || (c >= 91 && c <= 94));
}

// bool catalogExist("CardCatalog.txt") checks to see if CardCatalog exists. if not make it
inline bool catalogExist() //DONE 
{
    bool check;
    string filename = "CardCatalog.txt";
    ifstream f(filename.c_str());
    check = f.good();
    if (!f.good())
    {
        ofstream outfile ("CardCatalog.txt");
    }
    return check;
}

// void printToCatalog(story x). added story entry to catelog.
void    printToCatalog(struct story* book) //DONE
{
    fstream outfile;

    outfile.open("CardCatalog.txt", ios::in | ios::out);
    outfile.seekp(0, std::ios_base::end);
    outfile << "Title: " << book->title << endl << "Full Author: " << book->author << endl;
    outfile << "Author First Name: " << book->authorF << endl << "Author Last Name: " << book->authorL << endl;
    outfile << "Word count : " << book->wordcount << endl << "Line count: " << book->linecount << endl << endl;
    outfile.close();
}


// Some c code i threw together because i couldnt find a function to do what i wanted
/*
char *str_clean(const char *str)
{
    char *tmp;
    int i = 0;
    int j = 0;

    while (str[i] != '\0')
        i++;
    while (*str++ != ':')
        j++;
    str++;
    i = i - j;
    if (!(tmp = (char*)malloc(sizeof(tmp) * (i))))
        return (NULL);
    j = 0;
    while (j < i)
    {
        tmp[j] = str[j];
        j++;
    }
    return tmp;
}
*/

string str_clean(string str)
{
    string tmp;
    int i = 0;
    int j = 0;
    int max = str.size();

    while (str[i] != ':')
    {
        i++;
    }
    while (i <= max)
    {
        tmp[j++] = str[i++];
    }


    return tmp;
}

// void existInCatalog(struct story* book) // checks to see if entry already exist in catalog.
// if it does output "Entry already exist. if not call on printToCatalog() to add it"
void    existInCatalog(struct story* book)
{
    fstream infile;
    string temp1;
    string temp2;
    string temp3;
    string book1 = (*book).title;
    string book2 = (*book).author;
    bool check = true;
    int i;

    infile.open("CardCatalog.txt", ios::in);
    
    /*
    while(!infile.eof() && catalogExist())
    {
        getline(infile, temp1);
        getline(infile, temp2);

        temp1 = str_clean(temp1);
        temp2 = str_clean(temp2);

        cout << "\n\n" << temp1 << "\t" << temp2 << "\n\n";

        if (temp1.compare(book1) == 0 && temp2.compare(book2) == 0)
        {
            cout << "\nEntry already exist in catalog\n\n";
            check = false;
            break;
        }
        //cout << temp1 << "\t" << book1 << endl;
        //cout << temp2 << "\t" << book2 << endl;

        i = 4;
        while (i--)
        {
            //cout << "FUCK\n" << temp1 << endl;
            getline(infile, temp3);
        }
    }
    */
    infile.close();
    if (check == true)
        printToCatalog(book);
    
    if (!catalogExist())
        printToCatalog(book);
    return;
}

int main()
{
    story book;
    string filename;
    filename = getFileName();
    printBookInfo(filename, &book);
    findLetterFreq(filename, &book);
    //cout << catalogExist() << endl;
    //cout << temp << endl;

    //catalogExist();
    existInCatalog(&book);
    //printToCatalog(&book);
    
    putLetterFreq(&book); // add ask function
    return 0;
}
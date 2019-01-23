#ifndef HW1_H
#define HW1_H
#include <string>

using namespace std;

struct story
{
    string title;
    string author;
    string authorF;
    string authorL;
    int wordcount;
    float letterFreq[26];
    int linecount;
};

string getFilename();
void printBookInfo(string filename);
void printWordCount(string filename);
story findLetterFreq(string filename);
void putLetterFreq(story x);
bool isUpper(char c);
inline bool catalogExist();
void printToCatalog(story x);

#endif
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
    int word_count;
    float letter_freq[26];
    int linecount;
};

#endif
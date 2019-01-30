/* A little script to help me find the notes i need */
//#include "finder.h"
#include <string>
#include <string.h>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

class TOC
{
    struct Node
    {
    string      content;
    string      file;
    Node   *next;
    };

    private:
        Node *head;

    public:
        TOC() // constructor
        {
            head = NULL;
        }

        ~TOC() // destructor
        {
            Node *next = head;
            
            while(next)
            {
                Node *deleteMe = next;
                next = next->next;
                delete deleteMe;
            }
        }

        void addValue(string content, string file)
        {
           Node *n = new Node();
           n->content = content;
           n->file = file;

           n->next = head;
           head = n;
        }

        string popContent()
        {
            Node *n = head;
            string ret = n->content;

            head = head->next;
            delete n;
            return ret;
        }

        string popFile()
        {
            Node *n = head;
            string ret = n->file;

            head = head->next;
            delete n;
            return ret;
        }
};

void printTOC() //print table of contents
{
    string tmp;
    ifstream tableOfContents;
    int i = 0;

    tableOfContents.open("TableOfContents.txt", ios::in);
    getline(tableOfContents, tmp);
    while (!tableOfContents.eof())
    {
        i++;
        cout << '\t' << i << ": " << tmp << endl;
        getline(tableOfContents, tmp);
    }
    tableOfContents.close();
}

/*string parseStringContent(string str)
{
    int i = 0;
    
    while (str[i] != " ")
        i++;

}*/

string parseStringFile(string str)
{

}


void openFile(int lineNum)
{
    string tmp;
    string tmp2;
    ifstream tableOfContents;
    int i = 0;

    tableOfContents.open("TableOfContents.txt", ios::in);
    getline(tableOfContents, tmp);
    while (!tableOfContents.eof() && (i != lineNum))
    {
        i++;
        //cout << '\t' << i << ": " << tmp << endl;
        getline(tableOfContents, tmp);
    }
    tableOfContents.close();
    /*if (i == lineNum)
    {
       //tmp2 = parseStringContent(tmp);
       cout << tmp2;
    }*/
}

int main()
{
    int lineNum;

    printTOC();
    cout << "\nEnter the line number you want: ";
    cin >> lineNum;
    openFile(lineNum);

    return 0;
}
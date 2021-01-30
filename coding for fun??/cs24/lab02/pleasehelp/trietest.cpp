#include <array>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <stack>
#include <utility>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;

#define ALPHABET_SIZE 26

struct Trie
{
    //VARS
    bool wordEnd;
    Trie* child[26];

    Trie(); //default constructor that sets every child* to NULL
    Trie(Trie const& other); //copy constructor that copies 'other' into this

    //FUNCTIONS
    void insert(string str); //insert str into the Trie structure
    bool search(string str); //return true if str exists in the Trie structure

};

string removeFirstChar(string str);
    //precondition: str is a string
    //postcondition: returns str, but without the first character
    //               -ex- inputting "cshard" would return "shard"

string removeLastChar(string str);
    //precondition: str is a string
    //postcondition: returns str, but without the last character
    //               -ex- inputting "cshard" would return "cshar"

int main()
{
    Trie test;
    string inTree = "c";
    string notInTree = "s";
    test.insert(inTree);
    
    cout << "-------EXISTING IN TREE TEST-------\n";
    if(test.search(inTree))
    {
        cout << "   returned true-TEST PASSED-       \n";
    }
    else
    {
        cout << "   returned false-TEST FAILED-       \n";
    }
    cout << endl;

    cout << "-----NOT EXISTING IN TREE TEST-----\n";
    if(test.search(notInTree))
    {
        cout << "   returned true-TEST FAILED-       \n";
    }
    else
    {
        cout << "   returned false-TEST PASSED-       \n";
    }
    cout << endl;

    return 0;
}

string removeFirstChar(string str)
{
    string newstr = "";
    for(int i = 1; i < str.length(); i++)
    {
        newstr = newstr + str[i];
    }
    return newstr;
}

string removeLastChar(string str)
{
    string newstr = "";
    for(int i = 0; i < str.length() - 1; i++)
    {
        newstr = newstr + str[i];
    }
    return newstr;
}

Trie::Trie()
{
    for(int i = 0; i < 26; i++)
    {
        child[i] = NULL;
    }
}

void Trie::insert(string str)
{
    if(str.length() > 1)
    {
        int alphaIndex;
        alphaIndex = str[0] - 'a'; //safe to do str[0] since the only str's that will get pass the if statement will be 1 char long strings
        Trie* newNode = new Trie;//alloc new node, where newNode is the memory address of the new node
        this->child[alphaIndex] = newNode; //put newly allocated node's mem address into the right place in current node's array
        (*newNode).wordEnd = false; //set the new node's wordEnd value to false
        Trie::insert(removeFirstChar(str));
    }
    else
    {
        int alphaIndex;
        alphaIndex = str[0] - 'a'; //safe to do str[0] since the only str's that will get pass the if statement will be 1 char long strings
        Trie* newNode = new Trie;//alloc new node, where newNode is the memory address of the new node
        this->child[alphaIndex] = newNode; //put newly allocated node's mem address into the right place in current node's array
        (*newNode).wordEnd = true; //set the new node's wordEnd value to true
    }
}


bool Trie::search(string str)
{
    int alphaIndex;
    for(int i = 0; child[i] != NULL; ++i)
    {
        alphaIndex = str[i] - 'a';
        if(child[alphaIndex] == NULL)
        {
            return false;
        }
    }
    return true;
}

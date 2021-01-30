//template.cpp
//Created by: Kevin Lu
//Created on: 10/20/2020
//Lab Partner: 

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void FunString(string string);

int main()
{
    string hello = "Hello my friend!";
    FunString(hello);
}

void FunString(string string)
{
    int length = string.length();
    int numSpaces = 0;
    for(int n = (length - 1); n >= 0; n--)
    {
        cout << string[n];
        if(string[n] == ' ')
        {
            numSpaces = numSpaces + 1;
        }
    }
    cout << endl << numSpaces + 1 << endl;
}
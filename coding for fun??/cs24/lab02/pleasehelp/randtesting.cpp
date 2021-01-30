//template.cpp
//Created by: Kevin Lu
//Created on: 10/20/2020
//Lab Partner: 

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;


int main()
{
    string str = "abc";
    int alphaIndex;
    for(int i = 0; i < str.length(); i++)
    {
        alphaIndex = str[i] - 'a';
        cout << "alphaIndex of " << str[i] << " is " << alphaIndex << ".\n";
    }
    return 0;
}
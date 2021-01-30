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
    int v = 4337152; //1
    //int v = 8531456; //0
    //int v = 12725760; //1
    cout << ((0x00400000 & v) >> 22) << endl;
    cout << ((v | 0x003FFFFF) >> 22) << endl;
    cout << ((v >> 22) & 0x007FFFFF) << endl;
    cout << ((v << 23) | 0x00400000) << endl;
    return 0;
}
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

int ifBit7is1(int v);
int ifBit7is1(int v)
{
    v = v & 480;
    v = v >> 5;
    return v;
}

int main()
{
    cout << ifBit7is1(1007);
    return 0;
}
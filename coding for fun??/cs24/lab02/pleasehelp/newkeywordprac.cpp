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
    int a = 500000;
    int *pointer = nullptr;
    pointer = &a;

    cout << "Address of a is " << pointer << endl;
    cout << "Value of a is " << *pointer << endl;
    return 0;
}
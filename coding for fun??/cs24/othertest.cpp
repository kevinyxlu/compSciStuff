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
    int *pt;
    pt = new int[10];
    pt[1] = 15;
    pt[2] = 16;
    cout << pt[1] << endl;
    cout << *(pt+2) << endl;
    return 0;
}
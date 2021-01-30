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
    ifstream tin;
    char c;
    tin.open("t.txt");
    tin.get(c);
    while (!tin.eof())
    {
        if ( (c != 'e') && (c != 'C') )
        {
            cout << c;
        }
        tin.get(c); 
    }
}

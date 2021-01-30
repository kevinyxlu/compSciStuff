//template.cpp
//Created by: Kevin Lu
//Created on: 10/20/2020
//Lab Partner: 

#include <iostream>
using namespace std;

int main()
{
	int number = 7;
    int denom = 5;
    double var1 = number/denom;
    double var2 = static_cast<double>(number)/denom;
    int var3 = static_cast<double>(number)/denom;
    cout << var1 << endl << var2 << endl << var3 << endl;
    return 0;
}

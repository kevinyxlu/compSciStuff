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
	ifstream inf;
    double num, sum(0), av;
    int count(0);

    inf.open("MyInputs.txt");
    while(inf >> num)
    {
        sum += num;
        count++;
    }
    av = sum / count;

    cout << "The average is: " << av << endl;
    return 0;
}

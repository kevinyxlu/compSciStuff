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
    int num;
    int answer = 1;
    int counter = 1;

    cout << "Enter a number\n";
    cin >> num;

    while (counter < num + 1)
    {
        answer = answer * counter;
        counter = counter + 1;
    }
    cout << "Factorial of " << num << " is:\n" << answer << endl;
    return 0;
}
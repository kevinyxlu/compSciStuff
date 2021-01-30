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
    //declare variables
    int num1, num2, num3, min;
    string prompt = "Enter the next number\n";
    string minimum = "Minimum: ";
    string newline = "\n";

    //get first variable
    cout << prompt;
    cin >> num1;

    //get second variable
    cout << prompt;
    cin >> num2;

    //get 3rd variable
    cout << prompt;
    cin >> num3;

    //set min to num1
    min = num1;

    //update min if num2 or num3 is smaller than num1;
    if(num2 < min)
    {
        min = num2;
    }
    if(num3 < min)
    {
        min = num3;
    }

    //print out minimum
    cout << minimum;
    cout << min;
    cout << newline;

    //exit program
    return 0;
}
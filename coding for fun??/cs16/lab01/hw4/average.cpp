//template.cpp
//Created by: Kevin Lu
//Created on: 10/20/2020
//Lab Partner: 

#include <iostream>
using namespace std;

double average(int integer, double decimal);
//Precondition: Takes in one argument of type int, another of type double
//Postcondition: returns a value of type double that is the real-number
//average of the two values

double average(int integer, double decimal)
{
    double result = (((static_cast<double>(integer)) + decimal) / 2);
    return result;
}

int main()
{
    int num1;
    double num2;
	cin >> num1 >> num2;
    cout << average(num1, num2);
    return 0;
}

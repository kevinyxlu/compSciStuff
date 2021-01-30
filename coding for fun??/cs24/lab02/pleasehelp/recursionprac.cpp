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

int findFactorial(int a);
//precondition: a is an positive integer input
//postcondition: returns an int value equivalent to (a!)

int main()
{
    int input;
    cout << "Enter a number and I'll find it's factorial: ";
    cin >> input;
    cout << findFactorial(input) << " is the solution." << endl;
    return 0;
}

int findFactorial(int a)
{
    int solution;
    if(a == 0)
    {
        solution = 1;
    }
    else
    {
        solution = a * findFactorial(a - 1);
    }
    return solution;
}
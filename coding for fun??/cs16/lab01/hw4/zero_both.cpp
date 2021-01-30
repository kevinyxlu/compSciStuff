//template.cpp
//Created by: Kevin Lu
//Created on: 10/20/2020
//Lab Partner: 

#include <iostream>
using namespace std;

void zero_both(int& num1, int& num2);
//Precondition: Takes in 2 variables of type int
//Postcondition: Sets the value of both variables to 0

void zero_both(int& num1, int& num2)
{
    num1 = 0;
    num2 = 0;
    return;
}

int main()
{
    int x, y;
	cin >> x >> y;
    cout << x << y << endl;
    zero_both(x, y);
    cout << x << y << endl;
    return 0;
}

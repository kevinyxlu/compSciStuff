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

class TwoNumbers
{
    public:
    TwoNumbers(int n1, int n2);
    TwoNumbers();
    double sum();
    double difference();
    double max();

    private:
    double num1, num2;
}

int main()
{
    TwoNumbers thisOne, thatOne(5,7);
    thisOne.num++;
    return 0;
}

TwoNumbers::TwoNumbers(int n1, int n2)
{
    num1 = n1;
    num2 = n2;
}

TwoNumbers::TwoNumbers()
{
    num1 = 0;
    num2 = 0;
}

double TwoNumbers::sum()
{
    return num1 + num2;
}

double TwoNumbers::difference()
{
    return abs(num1 - num2);
}

double TwoNumbers::max()
{
    if(num1 < num2)
    {
        return num2;
    }
    else
    {
        return num1;
    }
}
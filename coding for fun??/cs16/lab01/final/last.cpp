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

int findMode(int array[], int Asize);
//precondition: array is an int array with entries between 0 and 4, Asize is the size of array
//postcondition: returns the mode of array

int main()
{
    int array[8] = {2, 1, 2, 3, 0, 2, 4, 1};
    int array1[5] = {4, 0, 4, 2, 0};
    cout << findMode(array, 8);
    return 0;
}

int findMode(int array[], int Asize)
{
    int num0(0), num1(0), num2(0), num3(0), num4(0), max(-99999);
    for(int n = 0; n < Asize; n++)
    {
        if(array[n] == 0)
        {
            num0 = num0 + 1;
        }
        if(array[n] == 1)
        {
            num1 = num1 + 1;
        }
        if(array[n] == 2)
        {
            num2 = num2 + 1;
        }
        if(array[n] == 3)
        {
            num3 = num3 + 1;
        }
        if(array[n] == 4)
        {
            num4 = num4 + 1;
        }
    }

    if(num0 > max)
    {
        max = num0;
    }
    if(num1 > max)
    {
        max = num1;
    }
    if(num2 > max)
    {
        max = num2;
    }
    if(num3 > max)
    {
        max = num3;
    }
    if(num4 > max)
    {
        max = num4;
    }

    if(num0 == max)
    {
        return 0;
    }
    if(num1 == max)
    {
        return 1;
    }
    if(num2 == max)
    {
        return 2;
    }
    if(num3 == max)
    {
        return 3;
    }
    if(num4 == max)
    {
        return 4;
    }
    return -1;
}
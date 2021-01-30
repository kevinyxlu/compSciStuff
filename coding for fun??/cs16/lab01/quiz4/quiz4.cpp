//template.cpp
//Created by: Kevin Lu
//Created on: 10/20/2020
//Lab Partner: 

#include <iostream>
using namespace std;

void ArrayFunct(int a[], int asize, int &varX);
int main() {
   int az[100] = {1,2,3};
   int size = 100, tester = 7;
   // call the function ArrayFunct
   ArrayFunct(az, az[0], az[42]);
}

void ArrayFunct(int a[], int asize, int &varX)
{
    cout << "Test PASSED" << endl;
}
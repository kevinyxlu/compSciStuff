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

int sumOdds(int N);

int main()
{
    cout << sumOdds(8);
    return 0;
}

int sumOdds(int N)
{
    if((N % 2 == 0) && (N != 1))
    {
        N = N - 1;
    }

    if(N >= 1)
    {
        return N + sumOdds(N - 2);
    }
    else
    {
        return 0;
    }
}
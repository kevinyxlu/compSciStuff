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

int MultN(int array[], int Asize, int N);
//precon: array is an int array, Asize is the size of array, N is an int
//post cond: prints indices of members of array that are multiples of N on their own line
          //  prints how many elements found on final line, returns sum of elements found

int main()
{
    int array[6] = {1,2,3,4,5,6};
    cout << MultN(array, 6, 3);
    return 0;
}

int MultN(int array[], int Asize, int N)
{
    int moduloVar, sum = 0, count = 0;
    for(int n = 0; n < Asize; n++)
    {
        moduloVar = array[n] % N;
        if(moduloVar == 0)
        {
            cout << n << endl;
            sum = sum + array[n];
            count = count + 1;
        }
    }
    cout << "Found " << count << " element(s)" << endl;
    return sum
}

//q18, q21
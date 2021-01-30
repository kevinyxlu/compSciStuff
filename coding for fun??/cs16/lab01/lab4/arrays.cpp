//template.cpp
//Created by: Kevin Lu
//Created on: 10/27/2020

//code for primesArray function definition inspired from quiz 3, question 4

/*
/ Skeleton File for ARRAYS.CPP for CS16, 2020, UCSB
/ Copyright © 2020 by Ziad Matni. All rights reserved.
/
*/

// DO NOT MODIFY THESE NEXT 6 LINES - DO NOT ADD TO THEM
#include <iostream> // for cout, cin
#include <fstream>  // for ifstream
#include <cstdlib>  // for exit
using namespace std;
#include "headers.h"    // contains the function declarations
#include "constants.h"  // contains 4 global variables

int main( )
{
    // DO NOT MODIFY THESE NEXT 3 LINES - DO NOT ADD TO THEM
    ifstream ifs;
    int size = MAXSIZE, array[MAXSIZE];
    getArray(ifs, FILENAME, array, size);


    // hints for the tasks: 
    // all that needs to be in here is simple calls the functions, like these: 
    // in addition to, some print to std.out statements.
    // 
    // Your main() will ideally look clean and uncluttered and be made up
    // mostly of function calls.
    // 
    // Example:
    // ...
    // printArray(array, size);
    // max = maxArray(array, size);
    // min = minArray(array, size);
    // ...
    // ...etc...
    print_array(array, size);
    cout << endl;
    cout << "Max = " << maxArray(array, size) << endl;
    cout << "Min = " << minArray(array, size) << endl;
    cout << "Sum = " << sumArray(array, size) << endl;
    cout << "Evens: ";
    evensArray(array, size);
    cout << "end" << endl;
    cout << "Primes: ";
    primesArray(array, size);
    cout << "end" << endl;
    cout << "Searches:\n";
    AllSearches(array, size);

    // PUT MISSING CODE HERE

    return 0;
}

// PUT MISSING FUNCTION DEFINITIONS HERE

void print_array(int arr[], int asize)
// Pre-Condition: takes in an integer array and its size.
// Post-Condition: prints all elements in the array.
{
    for(int n = 0; n < (asize - 1); n++)
    {
        cout << arr[n] << ", ";
    }
    cout << arr[asize - 1];
    return;
}

int maxArray(int arr[], int asize)
// Pre-Condition: takes in an integer array and its size.
// Post-Condition: returns the maximum number in the array.
{
    int max = arr[0];
    for(int n = 0; n < asize; n++)
    {
        if(max < arr[n])
        {
            max = arr[n];
        }
    }
    return max;
}

int minArray(int arr[], int asize)
// Pre-Condition: takes in an integer array and its size.
// Post-Condition: returns the minimum number in the array.
{
    int min = arr[0];
    for(int n = 0; n < asize; n++)
    {
        if(min > arr[n])
        {
            min = arr[n];
        }
    }
    return min;
}

int sumArray(int arr[], int asize)
// Pre-Condition: takes in an integer array and its size.
// Post-Condition: returns the sum of the array.
{
    int sum = 0;
    for(int n = 0; n < asize; n++)
    {
        sum = sum + arr[n];
    }
    return sum;
}

void evensArray(int arr[], int asize)
// Pre-Condition: takes in an integer array and its size.
// Post-Condition: prints all the even numbers in the array.
{
    for(int n = 0; n < asize; n++)
    {
        if ((arr[n] % 2) == 0)
        {
            cout << arr[n] << ", ";
        }
    }
    return;
}


void primesArray(int arr[], int asize)
// Pre-Condition: takes in an integer array and its size
// Post-Condition: prints all the prime numbers in the array.
{
    for(int n = 0; n < asize; n++)
    {
        bool prime = true;
        int i = 2;
        while ((i < arr[n]) && prime) 
        {
            if (arr[n] % i == 0)
            {
                prime = false;
            }
            i++;
        }
        if(prime)
        {
            if((arr[n] > 0) && (arr[n] != 1))
            {
                cout << arr[n] << ", ";
            }
        }
    }
}

int SeqSearch(int arr[], int array_size, int target)
// Pre-Condition: takes in an integer array, its size, and an int target.
//                  This function must be called within AllSearches().
// Post-Condition: if the function finds "target", it returns its index in the array, otherwise it returns -1.
//                  the function only takes ONE integer (at a time) when searching.
{
    int index = -1;
    for(int n = 0; n < array_size; n++)
    {
        if(arr[n] == target)
        {
            index = n;
            return index;
        }
    }
    return index;
}

void AllSearches(int array[], int array_size)
// Pre-Condition: runs a loop of SeqSearch() of an array, given the array and its size.
//                  This function has to call on SeqSearch() function.
// Post-Condition: outputs either of the following for every iteration of the loop:
//              Looking for <search parameter>. Not found
//              Looking for <search parameter>. Found at index: <index value>
{
    for(int n = 0; n < NSEARCHES; n++)
    {
        cout << "Looking for " << SEARCHES[n] << ". ";
        if(SeqSearch(array, array_size, SEARCHES[n]) == -1)
        {
            cout << "Not Found!\n";
        }
        else
        {
            cout << "Found at index: " << SeqSearch(array, array_size, SEARCHES[n]) << endl;
        }
    }
}
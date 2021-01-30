//template.cpp
//Created by: Kevin Lu
//Created on: 10/20/2020
//Lab Partner: 

#include <iostream> // for cout, cin
#include <fstream>  // for ifstream
#include <cstdlib>  // for exit
using namespace std;
#include "headers.h"    // contains the function declarations
#include "constants.h"  // contains 4 global variables

int main()
{
	int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    AllSearches(array, 10);
    return 0;
}

int SeqSearch(int arr[], int array_size, int target)
// Pre-Condition: takes in an integer array, its size, and an int target.
//                  This function must be called within AllSearches().
// Post-Condition: if the function finds "target", it returns its index in the array, otherwise it returns -1.
//                  the function only takes ONE integer (at a time) when searching.
{
    int index = -1;
    for(int n = array_size; n > 0; n--)
    {
        if(arr[n] == target)
        {
            index = n;
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
        if(SeqSearch(array, array_size, SEARCHES[n]) != -1)
        {
            cout << "Found at index: " << SeqSearch(array, array_size, SEARCHES[n]) << endl;
        }
        else
        {
            cout << "Not Found!\n";
        }
    }
}
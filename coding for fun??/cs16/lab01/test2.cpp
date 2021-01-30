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

int find_index_of_swap(bool descend, int arr[], int siz, int startIndex);
//precondition: descending being true will make the largest value in the array be returned, false for smallest
                //array is an integer arrray
                //arraysize is the size of the array(or subarray)
                //startingIndex is an int that indicates the starting index of the array that needs sorting
//Postcondition: returns the index of the smallest value in the array if descending is false
                //return the index of the largest value in the array if descending is true


int main()
{
    int testArray[15] = {16, 5, 3, 44, 5, 6, 72, 85, 9, 1, 11, 12, 135, 14, 19};
                        //0  1  2   3  4   5  6   7  8  9   10  11  12  13  14
    int simpleArray[2] = {5, 2};
    cout << find_index_of_swap(0, testArray, 15, 12) << endl;
    return 0;
}


int find_index_of_swap(bool descend, int arr[], int siz, int startIndex)
{
    int min = arr[startIndex];
    int index_of_min = startIndex;

    for(int index = startIndex + 1; index < siz; index++)
    {
        if(descend)
        {
            if(arr[index] >= min)
            {
                min = arr[index];
                index_of_min = index;
            }
        }
        else
        {
            if(arr[index] <= min)
            {
                min = arr[index];
                index_of_min = index;
            }
        }
    }
    return index_of_min;
}

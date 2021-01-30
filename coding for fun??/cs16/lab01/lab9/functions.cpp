//functions.cpp
//Created by: Kevin Lu
//Created on: 12/2/2020
//Lab Partner: Vince Nguyen
//swap_values function retreived from slide 29 of lecture 11

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

void swap_values(int& v1, int& v2)
{
    int temp; //temporary variable to hold first variable and switch it into the second
    temp = v1;
    v1 = v2;
    v2 = temp;
}

int find_index_of_swap(bool descending, int array[], int arraySize, int startingIndex)
{
    int temp; //temporary variable to compare to current index
    int outputIndex; //variable to store the index of the current smallest or largest value
    if(descending == true)
    {
        temp = -9999999; //initializing temp for finding greatest number
        for(int n = startingIndex; n < arraySize; n++)
        {
            if(array[n] > temp)
            {
                temp = array[n];
                outputIndex = n;
            }
        }
    }
    if(descending == false)
    {
        temp = 9999999; //initializing temp for finding smallest number
        for(int n = startingIndex; n < arraySize; n++)
        {
            if(array[n] < temp)
            {
                temp = array[n];
                outputIndex = n;
            }
        }
    }
    return outputIndex;
}

void sort(bool descending, int array[], int arraySize, int startingIndex)
{
    if(startingIndex >= arraySize - 1)
    {
        return;
    }
    else
    {
        swap_values(array[startingIndex], array[find_index_of_swap(descending, array, arraySize, startingIndex)]);
        cout << "Swapping " << array[startingIndex] << " with " << array[find_index_of_swap(descending, array, arraySize, startingIndex)] << endl;
        //swaps first and the greatest/smallest element of the array
        sort(descending, array, arraySize, startingIndex + 1); //compares all past the first element of the previous array
    }
}

void getArray(ifstream& in, string fname, int arr[], int size)
{
    in.open(fname);
    if ( in.fail() ) 
    { 
        cerr << "Input file opening failed.\n"; 
        exit(1); 
    }
    for (int i = 0; i < size; i++)
    {
        in >> arr[i];
    }
}
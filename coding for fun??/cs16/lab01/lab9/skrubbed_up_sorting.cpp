//template.cpp
//Created by: Kevin Lu
//Created on: 10/20/2020
//Lab Partner: 

#include <iostream>
using namespace std;

int find_index_of_swap(bool descending, int array[], int arraySize, int startingIndex);
void swap_values(int& v1, int& v2);
void sort(bool descending, int array[], int arraySize, int startingIndex);

int main()
{
	int testArray[15] = {16, 5, 3, 44, 5, 6, 72, 85, 9, 1, 11, 12, 135, 14, 1};
    int simpleArray[2] = {5, 2};
    sort(false, testArray, 15, 0);
    sort(false, testArray, 15, 0);
    sort(false, testArray, 15, 0);

    sort(false, testArray, 15, 0);
    sort(false, testArray, 15, 0);
    sort(false, testArray, 15, 0);
    sort(false, testArray, 15, 0);
    sort(false, testArray, 15, 0);
    sort(false, testArray, 15, 0);
    sort(false, testArray, 15, 0);
    sort(false, testArray, 15, 0);
    sort(false, testArray, 15, 0);
    sort(false, testArray, 15, 0);
    sort(false, testArray, 15, 0);
    
    for(int n = 0; n < 15; n++)
    {
        cout << testArray[n] << " ";
    }
    return 0;
}

void swap_values(int& v1, int& v2)
{
    int temp;
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
        temp = -9999999;
        for(int n = startingIndex; n < arraySize; n++)
        {
            cout << temp << " " << outputIndex << endl;
            if(array[n] > temp)
            {
                temp = array[n];
                outputIndex = n;
            }
        }
    }
    if(descending == false)
    {
        temp = 9999999;
        for(int n = startingIndex; n < arraySize; n++)
        {
            cout << temp << " " << outputIndex << endl;
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
        if(array[startingIndex] > array[startingIndex + 1])
        {
            swap_values(array[startingIndex], array[startingIndex + 1]);
        }
        sort(descending, array, arraySize, startingIndex + 1);
    }
}
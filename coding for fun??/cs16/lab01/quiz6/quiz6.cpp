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

void bubbleSort(int array[], int size, bool descending);
//bubblesort

int main()
{
    int array[5] = {6, 2, 4, 1, 9};
    cout << array[0] << array[1] << array[2] << array[3] << array[4] << endl;
    bubbleSort(array, 5, true);
    cout << array[0] << array[1] << array[2] << array[3] << array[4] << endl;
	
    return 0;
}

void bubbleSort(int array[], int size, bool desending)
{
  int temp;
  if(desending){
    for (int i = size-1; i >= 0; i--) {
        for (int j = 1; j <= i; j++) {
        if (array[j-1] < array[j]) {
            temp = array[j-1];
            array[j-1] = array[j];
            array[j] = temp;
        } // if
        } // for j
    } // for i
  }
  else{
        for (int i = size-1; i >= 0; i--) {
        for (int j = 1; j <= i; j++) {
        if (array[j-1] > array[j]) {
            temp = array[j-1];
            array[j-1] = array[j];
            array[j] = temp;
        } // if
        } // for j
    } // for i
  }
}
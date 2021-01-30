//headers.h
//Created by: Kevin Lu
//Created on: 12/2/2020
//Lab Partner: Vince Nguyen

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

void sort(bool descending, int array[], int arraySize, int startingIndex);
//Precondition: descending is a boolean that determines direction of sort, true for descending, false for ascending
                //array is an integer array that needs sorting
                //arraySize is the size of the array(or subarray) that needs sorting
                //startingIndex is the starting index of the array that needs sorting

void swap_values(int& v1, int& v2);
//Precondition: v1 and v2 are two integer values
//Postcondition: v1's value is set to v2, and v2's value is set to v1

int find_index_of_swap(bool descending, int array[], int arraySize, int startingIndex);
//precondition: descending being true will make the largest value in the array be returned, false for smallest
                //array is an integer arrray
                //arraysize is the size of the array(or subarray)
                //startingIndex is an int that indicates the starting index of the array that needs sorting
//Postcondition: returns the index of the smallest value in the array if descending is false
                //return the index of the largest value in the array if descending is true

void getArray(ifstream& in, string fname, int arr[], int size);
// Pre-Condition: takes in an ifstream object for input file, a string for an input filename, an integer array and its size
// Post-Condition: the array will be populated with all the numbers from the input file



// Constants for the data file that your program is reading in
// Only change these if you want to test your program with a different array file
// than the one provided for you (ArrayFile.txt).
//
const int MAXSIZE = 20;     // amount of integers in the file (you need this to declare your array size)
const std::string FILENAME = "ArrayFile.txt";    // The file name with the integers
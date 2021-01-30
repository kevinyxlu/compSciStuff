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

void FindMedian(string fname, ifstream &ifs);
//Precondition: fname is an input file that contains a list of int numbers
// ifs is the input values from the input files
//Postcondition: returns the median of the numbers in the input file to an output file called median_output.dat

double calcMedian(double array[], int size);
//Precondition: takes in 2 arguments, an array of numbers of type double
// size is the number of values in the array
//Postcondition: returns the median of the values in the array

int main()
{
	ifstream ifs;
    string fname = "inputs.txt"; //file could have other names too
    FindMedian(fname, ifs);

    return 0;
}

void FindMedian(string fname, ifstream &ifs)
{
    double array[1000], next, median;
    int counter = 0;
    ofstream ofs;
    ifs.open(fname);
    ofs.open("median_output.dat");
    while(ifs >> next)
    {
        array[counter] = next;
        counter = counter + 1;
    }
    median = calcMedian(array, counter); //calculates the median

    ofs << median; //outputs the median to output stream
    ifs.close(); //closing of the input stream
    ofs.close(); //closing of the output stream
}

double calcMedian(double array[], int size)
{
    int midIndex, oddMedianIndex, evenMedianIndex1, evenMedianIndex2;
    double evenMedian, temp;
        for(int i = 0; i < size - 1; i++){ //Use bubble sort to sort the array
            for(int j = 0; j < size - i - 1; j++){
                if(array[j+1] < array[j]){
                    temp = array[j];
                    array[j] = array[j+1];
                    array[j+1] = temp;
                }
            }
        }
    
    midIndex = size / 2;
    if (size == 1)
    {
        return array[0];
    }
    else if ((size % 2) == 0) //runs this block if size is even
    {
        evenMedianIndex1 = midIndex;
        evenMedianIndex2 = midIndex - 1;
        evenMedian = (array[evenMedianIndex1] + array[evenMedianIndex2]) / 2;
        return evenMedian;
    }
    else //runs this block if size is not even (odd)
    {
        oddMedianIndex = (midIndex) + 0;
        return array[oddMedianIndex];
    }
}
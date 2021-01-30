//stats.cpp
//Created by: Kevin Lu
//Created on: 11/10/2020
//Lab Partner: Vince Nguyen

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

//FUNCTION DECLARATIONS
double calcMean(double array[], int size);
//Precondition: takes in 2 arguments, an array of numbers of type double
// size is the number of values in the array
//Postcondition: returns the Mean of the values in the array

double calcMedian(double array[], int size);
//Precondition: takes in 2 arguments, an array of numbers of type double
// size is the number of values in the array
//Postcondition: returns the median of the values in the array

double calcStd(double array[], int size);
//Precondition: takes in 2 arguments, an array of numbers of type double
// size is the number of values in the array
//Postcondition: returns the standard deviation of the values in the array

double calcSum(double array[], int size);
// Pre-Condition: takes in an array of doubles and its size.
// Post-Condition: returns the sum of the array

int main()
{
	ifstream inStream;
    ofstream outStream;
    string inputName;
    double array[1000], next;
    int counter = 0;
    //double testArray[4] = {6, 9, 7, 8}, num1, num2, num3; //testing vars
    //const int ARRAYSIZE = 4;

    //prompts user for file name and saves it in inputName
    cout << "Enter filename: "; 
    cin >> inputName;
    inStream.open(inputName); //opens the input file
    if (inStream.fail())
    {
        cerr << "Input file opening failed.\n";
        exit(1);
    }
    while(inStream >> next)
    {
        array[counter] = next;
        counter = counter + 1;
    }
    //cout << array[0] << array[1] << array[2] << array[3] << endl << counter << endl;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);
    cout << "Mean = " << calcMean(array, counter) << endl;
    cout << "Median = " << calcMedian(array, counter) << endl;
    cout << "Stddev = " << calcStd(array, counter) << endl;
    inStream.close();
    return 0;
}

//FUNCTION DEFINITIONS
double calcSum(double array[], int size)
{
    double sum = 0;
    for(int n = 0; n < size; n++)
    {
        sum = sum + array[n];
    }
    return sum;
}

double calcMean(double array[], int size)
{
    double mean, sum;
    sum = calcSum(array, size);
    mean = sum / size; 
    return mean;
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
    if ((size % 2) == 0) //runs this block if size is even
    {
        evenMedianIndex1 = midIndex;
        evenMedianIndex2 = midIndex - 1;
        evenMedian = (array[evenMedianIndex1] + array[evenMedianIndex2]) / 2;
        return evenMedian;
    }
    else //runs this block if size is not even (odd)
    {
        oddMedianIndex = (midIndex / 2) + 1;
        return array[oddMedianIndex];
    }
}

double calcStd(double array[], int size)
{
    double average, standardDeviation, firstHalf = 0; //where firstHalf is (x1-a)^2 + (x2-a)^2 + (x3-a)^2 + ...
    average = calcMean(array, size);
    for(int n = 0; n < size; n++)
    {
        firstHalf = firstHalf +  ((array[n] - average) * (array[n] - average));
    }
    standardDeviation = sqrt((firstHalf) / (size - 1));
    return standardDeviation;
}
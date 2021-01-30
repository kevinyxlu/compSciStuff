//headers.h
//Created by: Kevin Lu
//Created on: 12/1/2020
//Lab Partner: Vince Nguyen

#include <string>
using namespace std;

class AString 
{
    public:
    AString(); //default contructor that initializes StringValue to an empty string
    AString(string str); //constructor that initializes StringValue to the argument inputted
    void getAString(); //accessor function that asks use for input and assigns to StringValue (input can have space chars)
    void cleanUp(); //mutator function to remove all non alpha chars and transforming all alpha chars to lowercase
    void countLetters(int array[]); //mutator function:
                        //precondition:
                        //takes 2 int arrays of size 26 
                        //postcondition:
                        //counts the freq of occurance of all letters in StringValue and places that count in the int
                        //array in the appropriate index (0 is for a, 1 is for b, etc...)
    void printString(); //prints out the value of StringValue

    private:
    string StringValue; //private member variable
};

bool compareCounts(int array1[], int array2[]);
//Precondition: takes in two integer arrays
//Postcondition: returns a boolean value that says if the 2 arrays are
//               equivalent in their values or not
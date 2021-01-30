//headers.h
//Created by: Kevin Lu
//Created on: 11/17/2020
//Lab Partner: Vince Nguyen

// DEFINE STRUCTURE HERE -- MISSING!
struct UndergradStudents
{
    int studentID;
    string firstName, lastName, major;
    double gpa1, gpa2, gpa3, gpa4;
};

// DECLARE FUNCTIONS HERE.
// I've already declared 2 functions for you (in records.cpp)
// 
// You may add other function declarations in here as well, if you want to.
// See hint in the lab description document.

void sortStudents(UndergradStudents us[], int size);
//Precondition: takes in an array of type UndergradStudents
//Postcondition: sorts the array of type UndergradStudents by last name (alphabetically incrementing)

struct EmployeeRecord
{
    int accruedVacation; //in whole days
    char payStatus; //represented in either 'H' or 'S'
    double wage; //in dollars per hour
};
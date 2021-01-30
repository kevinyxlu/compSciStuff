//calculate.cpp
//By: Kevin Lu
//Created on: 10/23
//Lab Partner: Irene Cho

#include <iostream>
#include <cstdlib>
using namespace std;

//Function Declaration:
int calcModulo(int num1, int num2);
//Precondition: function takes 2 integer inputs
//Post condition: function returns num1 % num2
//if num2 = 0, returns an error message

int calcTimes(int num1, int num2);
//Precondition: function takes 2 integer inputs
//Post condition: function returns num1 * num2

int calcPlus(int num1, int num2);
//Precondition: function takes 2 integer inputs
//Post condition: function returns num1 + num2

//Function Defintion:
int calcModulo(int num1, int num2)
{
    int result;
    if (num2 == 0)
    {
        cerr << "Cannot divide by zero." << endl;
        exit(1);
    }
    else
    {
        result = num1 % num2;
    }
    return result;
}

int calcTimes(int num1, int num2)
{
    int result;
    result = num1 * num2;
    return result;
}

int calcPlus(int num1, int num2)
{
    int result;
    result = num1 + num2;
    return result;
}

// Usage: ./calculate int char int
// char can be one of 3 things: + x or %
int main(int argc, char *argv[])
{
    const char PLUS = '+';
    const char TIMES = 'x';
    const char MODULO = '%';
    char *operation = argv[2];
    int result;
    if (argc != 4) //checks to make sure there are 3 arguments
    {
        cerr << "Number of arguments is incorrect.\n";
        exit(1);
    }
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[3]);

    if(*operation == PLUS)
    {
        result = calcPlus(num1, num2);
    }
    else if(*operation == TIMES)
    {
        result = calcTimes(num1, num2);
    }
    else if(*operation == MODULO)
    {
        result = calcModulo(num1, num2);
    }
    else
    {
        cerr << "Bad operation choice.\n";
        exit(1);
    }
    

	//cout << num1 << argv[2] << num2 << "=" << result << endl;
    //cout << "Done!" << endl;
    cout << result << endl;
    return 0;
}
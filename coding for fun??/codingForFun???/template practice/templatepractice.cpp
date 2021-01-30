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

template <typename T>
void print(T input);
//Precondition: takes in an input
//Postcondition: prints the input and a new line via std::cout

int main()
{
    string str = "A String";
    int num = 123;
    double dec = 1.23;
    print(str);
    print(num);
    print(dec);
    return 0;
}

template <typename T>
void print(T input)
{
    cout << input << endl;
}

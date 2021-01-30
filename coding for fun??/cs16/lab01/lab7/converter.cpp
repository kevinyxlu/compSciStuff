//converter.cpp
//Created by: Kevin Lu
//Created on: 11/17/2020
//Lab Partner: Vince Nguyen
//took inspiration from Matthew Wang's conversion algorithm

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

string convertFromDec(unsigned int decnum, unsigned int base);
//Precondition: takes in 2 arguments: decnum represents a decimal number
//              base represents the converting base
//              binary (base 2), octal (base8), hexadecimal (base16)
//Postcondition: Converts decimal number into number in converting base
//                and returns converted number as a string

int main()
{
    string input;
    int decimalNum = 1;
    while(decimalNum > 0) //keeps asking user for input until invalid input is given
    {
        cout << "Enter positive decimal number (anything else quits): ";
        cin >> input;
        decimalNum = stoi(input);
        if(decimalNum > 0) //checks if input is valid
        {
            cout << decimalNum << " in binary is: " << convertFromDec(decimalNum, 2) << endl;
            cout << decimalNum << " in octal is: " << convertFromDec(decimalNum, 8) << endl;
            cout << decimalNum << " in hex is: " << convertFromDec(decimalNum, 16) << endl << endl;
        }
        else
        {
        }
    }
    return 0;
}

string convertFromDec(unsigned int decnum, unsigned int base)
{
    string output;
    string characters = "0123456789ABCDEF"; //array of characters for different bases
    if(base == 2 && decnum != 0)
    {
        while(decnum > 0)
        {
            int remainder;
            remainder = decnum % 2;
            decnum = decnum / 2;
            output = characters[remainder] + output;
        }
        return output;
    }
    else if(base == 8 && decnum != 0)
    {
        while(decnum > 0)
        {
            int remainder;
            remainder = decnum % 8;
            decnum = decnum / 8;
            output = characters[remainder] + output;
        }
        return output;
    }
    else if(base == 16 && decnum != 0)
    {
        while(decnum > 0)
        {
            int remainder;
            remainder = decnum % 16;
            decnum = decnum / 16;
            output = characters[remainder] + output;
        }
        return output;
    }
    else if(decnum == 0) //edge case of 0
    {
        return "0";
    }
    else //tells user the function wasn't used correctly
    {
        return "ERROR: convertFromDec FUNCTION WAS USED INCORRECTLY";
    }
}
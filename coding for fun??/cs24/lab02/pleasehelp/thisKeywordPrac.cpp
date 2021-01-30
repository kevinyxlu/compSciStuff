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

class testClass
{
    private:
        int x;
        int y;
    public:
        int getx() const;
        int gety() const;
        testClass();
        testClass(int x, int y);
};

int main()
{
    testClass test;
    testClass test1(1,3);
    cout << test.getx() << endl;
    cout << test.gety() << endl;
    cout << test1.getx() << endl;
    cout << test1.gety() << endl;
    return 0;
}

//accessor for private variable x
int testClass::getx() const
{
    return x;
}

//accessor for private variable y
int testClass::gety() const
{
    return y;
}

//default constructor
testClass::testClass()
{
    x = 6663;
    y = 6663;
}

//constructor with inputs
testClass::testClass(int x, int y) //<--- theses are what 'this->x' and 'this->y' reference
{
    this->x = x; //if you remove the 'this->', this function doesn't work
    this->y = y; //since 'this->' references the current instance of x and y
}
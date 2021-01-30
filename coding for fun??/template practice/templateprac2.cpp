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

template<typename T, int N>
class Array
{
    private:
        T theArray[N];
    public:
        int getSize() const {return N;}
};

int main()
{
    Array<string, 50> myArray;
    cout << myArray.getSize();
    return 0;
}

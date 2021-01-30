//template.cpp
//Created by: Kevin Lu
//Created on: 10/20/2020
//Lab Partner: 

#include <iostream>
using namespace std;

bool CheckIfNumbers(string string);

int main()
{
	cout << CheckIfNumbers("432") << endl;
    return 0;
}

bool CheckIfNumbers(string string)
{
    int length = string.length();
    bool result = true;
    for(int n = 0; n < length; n++)
    {
        if(isdigit(string[n]))
        {
        }
        else
        {
            result = false;
        }
    }
    return result;
}
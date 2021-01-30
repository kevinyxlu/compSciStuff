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


int main()
{
    string sushi, sashimi;
    sushi = "netflix";
    sashimi = "fox_cnn";
    if( sushi.erase(1, 6) == sashimi.erase(0, 6) ) 
        {
            cout << "is true";
        }
    return 0;
}

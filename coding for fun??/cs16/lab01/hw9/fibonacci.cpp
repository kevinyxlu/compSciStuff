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

int Fibo(int num);
void SFS(int num);

int main()
{
	cout << Fibo(8) << endl;
    SFS(10);
    return 0;
}

int Fibo(int num)
{
    if(num == 1)
    {
        return 0;
    }
    if(num == 2)
    {
        return 1;
    }
    else
    {
        return Fibo(num - 1) + Fibo(num - 2);
    }
}

void SFS(int num)
{
    for(int n = 1; n <= num; n++)
    {
        cout << pow(Fibo(n), 2) << " ";
    }
}
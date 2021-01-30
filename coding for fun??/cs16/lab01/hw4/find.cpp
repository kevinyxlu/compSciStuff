//template.cpp
//Created by: Kevin Lu
//Created on: 10/20/2020
//Lab Partner: 

#include <iostream>
using namespace std;

int find(int list[], int asize, int target);
//Precondition: takes 3 arguments:
//list: an integer array asize: an integer greater than or equal to 0 and indicates the size of the array
//target: an integer value that is being searched
//Postcondition: returns integer number that indicates how many times the target integer appears in the input array
//returns 0 if the value is not in the array

int find(int list[], int asize, int target)
{
    int count = 0; //var to keep track of times target int appears in the array
    for(int n = asize; n > 0; n--)
    {
        if (list[n-1] == target)
        {
            count++;
        }
        cout << list[n-1] << endl;
    }
    return count;
}

int main()
{
    int children[4] = {1, 1, 1, 1};
	cout << find(children, 4, 2) << endl;
    return 0;
}
//change.cpp
//Created by: Kevin Lu
//Created on: 10/20/2020
//Lab Partner: Irene Cho
#include <iostream>
using namespace std;

//Function Declaration:

void compute_coins(int amount);
//Precondition: 0 < amount < 100
//Postconmdition: The function prings out the number of quarters, dimes,
//and pennies needed to make the amount value.

//Function Defintion:
void compute_coins(int amount)
{
    int numQuarters, numDimes, numPennies, remAmount;
    numQuarters = amount / 25;
    remAmount = amount - (numQuarters * 25); //updates the balance remaining
    numDimes = remAmount / 10;
    remAmount = remAmount - (numDimes * 10);
    numPennies = remAmount;
    if (amount == 1)
    {
        cout << amount << " cent can be given in ";
    }
    else
    {
        cout << amount << " cents can be given in ";
    }

    if (numQuarters > 1)
    {
        cout << numQuarters << " quarters";
    }
    else if (numQuarters == 1)
    {
        cout << numQuarters << " quarter";
    }

    if ((numDimes > 1) && (numQuarters == 0))
    {
        cout << numDimes << " dimes";
    }
    else if (numDimes > 1)
    {
        cout << ", " << numDimes << " dimes";
    }

    if ((numDimes == 1) && (numQuarters == 0))
    {
        cout << numDimes << " dime";
    }
    else if ((numDimes == 1) && (numQuarters >= 1))
    {
        cout << ", " << numDimes << " dime";
    }

    if ((numPennies > 1) && ((numQuarters == 0) && (numDimes == 0)))
    {
        cout << numPennies << " pennies";
    }
    else if (numPennies > 1)
    {
        cout << ", " << numPennies << " pennies";
    }

    if ((numPennies == 1) && ((numQuarters == 0) && (numDimes == 0)))
    {
        cout << numPennies << " penny";
    }
    else if (numPennies == 1)
    {
        cout << ", " << numPennies << " penny";
    }

    cout << "." << endl;
}

int main()
{
    int amount = 1;
    while ((amount > 0) || (amount < 0))
    {
        if (amount == 0) //quits program if 0 or a negative number is input
		{
            return 0;
        }
        else
        {
            cout << "Enter number of cents (or zero to quit):" << endl;
            cin >> amount;
            if (amount == 0)
            {
                return 0;
            }
            else if ((amount >= 0) && (amount <= 99))
            {
                compute_coins(amount);
            }
            else
            {
                cout << "Amount is out of bounds. Must be between 1 and 99." << endl;
            }
        }
    }
}
//template.cpp
//Created by: Kevin Lu
//Created on: 10/20/2020
//Lab Partner: 

#include <iostream>
using namespace std;

int main()
{
	int q(1), d(0), n(0), sum;
    while (q + d + n != 0)
    {
        cout << "Enter number of quarters, dimes, and nickels " <<
                "separated by space characters (all 0s to quit): ";
        cin >> q >> d >> n;
        sum = (25 * q) + (d * 10) + (n * 5);
        cout << "That's worth " << sum << " cents in total!\n";
    }
    return 0;
}

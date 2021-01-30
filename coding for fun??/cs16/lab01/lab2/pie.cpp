#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int terms(1);
	while (terms > 0)
	{
		int denominator, numNegativeTerms, numPositiveTerms;
		double negativeSum(0), positiveSum(0);
		double piValue(0);
		cout << "Enter the number of terms to approximate (or zero to quit):\n";
		cin >> terms;
		if (terms <= 0) //quits program if 0 or a negative number is input
		{
		}
		else 
		{
			numNegativeTerms = ((terms + 1) / 2); //finds number of negative terms
			numPositiveTerms = (terms / 2); //finds number of positive terms
			for (int n = 1; n <= numNegativeTerms; n++) //calculates sum of negative nums
			{
				negativeSum = negativeSum + (1.0 / (1.0 - (n * 4.0) ));
			}

			for (int n = 1; n <= numPositiveTerms; n++) //calculates sum of positive nums
			{
				positiveSum = positiveSum + (1.0 / (1.0 + (n * 4.0) ));
			}
			piValue = 4 * (1 + negativeSum + positiveSum); //calculates pi
			cout.setf(ios::fixed);
			cout.setf(ios::showpoint);
			cout.precision(5);
			cout << "The approximation for Leibniz's Formula is " << piValue << " using " << terms << " terms.\n";
		}
	}

// You need to do something about the formatting requirement here!

// You also need to do a loop here that keeps asking for number of terms and then calculates pi!

// HINT: You can use cmath for its pow() function, which calculates x raised to the power y when used like: pow(x,y)

	return 0;
}
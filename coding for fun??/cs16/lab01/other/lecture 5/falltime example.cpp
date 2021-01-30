#include <iostream>
#include <cmath>
using namespace std;

//FUNCTION DECLARATION:

double FallTime(double d);
//Precondition: The function takes in 1 argument: a double variable d
//Postcondition: The function returns a double value of sqrt(0.2038 * d)

//FUNCTION DEFINITION:

double FallTime(double d)
{
    return sqrt(0.2038 * d);
}

int main()
{
	//Algorithm
    double h;
    cout << "Give me the height in meters: ";
    cin >> h;

    //Call the function:
    double t = FallTime(h);

    //Pring the result;
    cout << "The time it takes to drop in seconds is: " << t << endl;
    return 0;
}

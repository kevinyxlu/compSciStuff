#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void roll();
//prints a random number
void roll()
{
    int randomNumber(0);
    randomNumber = (rand() % 12) + 2;
    cout << randomNumber << endl;
}

int main()
{
    srand(time(0)); //seeds the random number generator
	for (int k = 0; k < 5; k++)
    {
        roll();
    }
    return 0;
}

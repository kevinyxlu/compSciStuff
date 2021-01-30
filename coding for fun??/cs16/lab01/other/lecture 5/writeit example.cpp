#include <iostream>
#include <string>
using namespace std;

//FUNCTION DECLARATION:

void WriteIt(string message, int r);
//precondition: takes in a string and integer
//postcondition: prints out the string r times

int main()
{
    int times = 7;
    cout << "How many times to repeat Watermelon?" << endl;
    cin >> times;
	string thing = "Watermelon";

    WriteIt(thing, times);
    return 0;
}

//FUNCTION DEFINITION:

void WriteIt(string message, int r)
{
    for(int i = 0; i < r; i++)
    {
        cout << message << "! ";
    }
    cout << endl;
    return;
}
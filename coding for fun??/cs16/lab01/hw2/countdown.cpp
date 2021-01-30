#include <iostream>
using namespace std;

int main()
{
	int count = 5;
    while (count > 0)
    {
        count--;
        if (count > 0)
        {
            cout << "COUNTDOWN TO ZERO: " << count << endl;
        }
        else
        {
            cout << "COUNTDOWN TO ZERO: LIFT OFF!" << endl;
        }
        
    }
    return 0;
}
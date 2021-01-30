#include <iostream>
using namespace std;

int main()
{
	int int1, int2, int3, max, min, mid;
    cin >> int1 >> int2 >> int3;
    
    if ((int1 <= int3) && (int2 <= int3)) //finds maximum value
    {
        max = int3;
    }
    else if ((int1 <= int2) && (int3 <= int2))
    {
        max = int2;
    }
    else if ((int2 <= int1) && (int3 <= int1))
    {
        max = int1;
    }
    
    if ((int1 >= int3) && (int2 >= int3)) //finds minimum value
    {
        min = int3;
    }
    else if ((int1 >= int2) && (int3 >= int2))
    {
        min = int2;
    }
    else if ((int2 >= int1) && (int3 >= int1))
    {
        min = int1;
    }

    if (((int2 <= int3) && (int3 <= int1)) || ((int1 <= int3) && (int3 <= int2)))//finds middle value
    {
        mid = int3;
    }
    else if (((int1 <= int2) && (int2 <= int3)) || ((int3 <= int2) && (int2 <= int1)))
    {
        mid = int2;
    }
    else if (((int2 <= int1) && (int1 <= int3)) || ((int3 <= int1) && (int1 <= int2)))
    {
        mid = int1;
    }

    cout << max << " " << mid << " " << min << endl;
    return 0;
}
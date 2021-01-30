#include <iostream>
using namespace std;

void check_it(int int1, int int2, int int3);
void check_it(int int1, int int2, int int3)
{
    if ((int1 >= int2) && (int2 >= int3))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
    return;
}

int main()
{
    int int1, int2, int3;
	cout << "Input 3 integer arguments seperated by a space: ";
    cin >> int1 >> int2 >> int3;
    check_it(int1, int2, int3);
    return 0;
}
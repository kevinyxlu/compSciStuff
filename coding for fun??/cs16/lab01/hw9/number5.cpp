#include <iostream>
using namespace std;
int RecursiveFunc(int num);

int main()
{
    int elementN;
    cout << "Which element of the sequence would you like to know? ";
    cin >> elementN;
    cout << "Element number " << elementN << " in the sequence is " << RecursiveFunc(elementN) << endl;
    return 0;
}

int RecursiveFunc(int num)
{
    if(num <= 1)
    {
        return 3;
    }
    return 5 + 2 * RecursiveFunc(num - 1);
}
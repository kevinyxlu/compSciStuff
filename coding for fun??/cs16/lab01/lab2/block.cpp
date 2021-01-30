#include <iostream>
using namespace std;

int main()
{
    int rows, columns;
    while ((rows >0) || (columns > 0))
    {
        cout << "Enter number of rows and columns:" << endl;
        cin >> rows >> columns;
        for (int n = 1; n <= rows; n++)
        {
            for (int n = 1; n <= columns; n++)
            {
                cout << "X.";
            }
           cout << endl;
        }
    }
    return 0;
}

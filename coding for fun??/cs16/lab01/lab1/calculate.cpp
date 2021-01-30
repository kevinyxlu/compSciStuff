#include <iostream>
using namespace std;
int main() {
  // Your printing code should go here
  int var1, var2, var3, result;        // declaring variables with type int
  cout << "Please enter 3 numbers.\n"; // prompts user
  cin >> var1 >> var2 >> var3;         // receives inputs
  result = 3 * (var1 + 2 * var2) - 4 * var3;           // calculates the result
  cout << "The formula result is: " << result << endl; // outputs the result
  return 0;
}
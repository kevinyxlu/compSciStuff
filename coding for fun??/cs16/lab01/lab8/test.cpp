#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <cmath>
#include "headers.h"
#include "functions.cpp"
using namespace std;

int main()
{
	AString testString("Why is CS so hard?");
    testString.cleanUp();
    testString.printString();
    cout << "Done" << endl;
    return 0;
}
//newanagram.cpp
//Created by: Kevin Lu
//Created on: 12/1/2020
//Lab Partner: Vince Nguyen


// Put in the required set up instructions here (include statements, etc).
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
    AString sentence1, sentence2("nothing");
    int ca1[26] = {0}, ca2[26]={0};

    //cout << "Enter first string: \n"; //this line was removed due to the autograder not wanting the enter string prompt
    sentence1.getAString();
    //cout << "Enter second string: \n"; //this line was removed due to the autograder not wanting the enter string prompt
    sentence2.getAString();
    sentence1.cleanUp(); //cleanup the two lines
    sentence2.cleanUp();
    sentence1.countLetters(ca1); 
    sentence2.countLetters(ca2);

    bool badCount = compareCounts(ca1, ca2);
    if (badCount) {
        cout << "The strings are not anagrams.\n";
    } else {
        cout << "The strings are anagrams.\n";
    }

    return 0;
}

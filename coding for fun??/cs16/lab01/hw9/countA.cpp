//template.cpp
//Created by: Kevin Lu
//Created on: 10/20/2020
//Lab Partner: 

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

int CountA(string sentence);

int main()
{
	cout << CountA("AaAbuyfaaaaAAuagsa") << endl;
    return 0;
}

int CountA(string sentence)
{
    if(sentence.length() == 0)
    {
        return 0;
    }
    if(sentence[0] == 'a' || sentence[0] == 'A')
    {
        return 1 + CountA(sentence.substr(1, sentence.size())); //"b"
    }
    if(sentence[0] != 'a' || sentence[0] != 'A')
    {
        return CountA(sentence.substr(1, sentence.size()));
    }
}
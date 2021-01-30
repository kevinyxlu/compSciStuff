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
#include "trie.hpp"
#include "trie.cpp"
using namespace std;


int main()
{
    Trie word;
    word.end_of_word = true;
    cout << word.end_of_word << endl;
    return 0;
}
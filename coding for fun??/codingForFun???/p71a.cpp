//https://codeforces.com/problemset/problem/71/A

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

string updateWord(string word);
//Precondition:
//inputs a word of type string (screw cstrings those things suck)
//Postcondition:
//will return the input if the length of the string is > 10, it will shorten
//it with a special abbreviation <firstletter><wordlength - 2><lastletter>
//for example, "localization" will be spelt as "l10n", 
//and "internationalization» will be spelt as "i18n"

int main()
{
    int numWords;
    string words[100];
    cin >> numWords;
    for(int i = 0; i < numWords; i++) //loop to get word inputs
    {
        cin >> words[i];
    }
    for(int i = 0; i < numWords; i++) //loop to update words
    {
        words[i] = updateWord(words[i]);
    }
    for(int i = 0 ; i < numWords; i++) //loop to print updated words
    {
        cout << words[i] << endl;
    }
    return 0;
}

string updateWord(string word)
{
    int wordLength = word.length();
    string wordLengthStrMinus2 = to_string(word.length() - 2);
    string newWord = "";
    if(wordLength <= 10)
    {
        return word;
    }
    else
    {
        newWord = newWord + word[0];
        newWord = newWord + wordLengthStrMinus2;
        newWord = newWord + word[wordLength - 1];
        return newWord;
    }
}
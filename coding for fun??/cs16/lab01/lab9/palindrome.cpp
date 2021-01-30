//palindrome.cpp
//Created by: Kevin Lu
//Created on: 12/2/2020
//Lab Partner: Vince Nguyen

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

// DECLARE THE FUNCTIONS HERE:
void cleanUp(string& word);
//Precondition: takes in the output from extractLastWord()
//Postcondition: removes all characters from word that are not alphabetic

bool isPalindrome(string word);
//Precondition: takes in a string that has been cleaned up by the function cleanUp
//postcondition: returns true if the string is a palindrome, false otherwise

int main() {
    
    string p;
    cout << "Enter sentence:\n";
    getline(cin, p);
    
    cleanUp(p);
    cout << p << endl;
    bool answer = isPalindrome(p);
   
    if (answer) {
        cout << "It is a palindrome.\n";
    } else {
        cout << "It is not a palindrome.\n";
    }
    
    return 0;
}

// DEFINE THE FUNCTIONS HERE:
void cleanUp(string& word)
{
    int wordLength = word.size();
    string filteredWord;
    for(int i = 0; i < wordLength; i++)
    {
        if(isalpha(word[i])) //nothing happens if character is alphabet
        {
        }
        else
        {
            word[i] = '#'; //sets all non alpha characters to sentinel char #
        }
    }

    for(int i = 0; i < wordLength; i++) //gets rid of all sentinel char #'s
    {
        if(word[i] != '#')
        {
            filteredWord = filteredWord + word[i];
        }
    }
    int filteredWordLen = filteredWord.length(); //find length of filtered sentence to change it all into lowercase
    for(int n = 0; n < filteredWordLen; n++)
    {
        filteredWord[n] = tolower(filteredWord[n]);
    } 
    word = filteredWord;
}

bool isPalindrome(string word)
{
    if(word.size() == 0)
    {
        return 1;
    }
    return ((word[0] == word[word.size() - 1]) && isPalindrome(word.substr(1, word.size() - 2))); 
    //returns false if the first char and last char of word is not equivalent
}
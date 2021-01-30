//anagrams.cpp
//Created by: Kevin Lu
//Created on: 11/3/2020
//Lab Partner: Vince Nguyen

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// FUNCTION DECLARATIONS
void allLowercase(string &sentence, int size);
//Precondition: sentence is a string consisting of only alphabetical characters
//Postcondition: changes the string into all lowercase characters

string printFreq(string &sentence, int size);
//Precondition: sentence is a string consisting of only alphabetical characters
//Postcondition: returns out all unique characters of a string and their frequencies

int main()
{
    // MISSING CODE HERE (you can remove these comments)
	// Get strings from user
	// Clean strings
	// Check to see if they are anagrams
	// Report if they are or not anagrams
    
    string firstSentence, secondSentence;
    int sentence1Length, sentence2Length;

    cout << "Enter first string:\n";
    getline(cin, firstSentence);
    cout << "Enter second string:\n";
    getline(cin, secondSentence);

    string filteredSentence1, filteredSentence2;
    sentence1Length = firstSentence.size();
    sentence2Length = secondSentence.size();

    //creates filteredSentence1
    for(int i = 0; i < sentence1Length; i++)
    {
        if(isalpha(firstSentence[i])) //nothing happens if character is alphabet
        {
        }
        else
        {
            firstSentence[i] = '#'; //sets all non alpha characters to sentinel char #
        }
    }
    for(int i = 0; i < sentence1Length; i++)
    {
        if(firstSentence[i] != '#')
        {
            filteredSentence1 = filteredSentence1 + firstSentence[i];
        }
    }

    //creates filteredSentence2
    for(int i = 0; i < sentence2Length; i++)
    {
        if(isalpha(secondSentence[i])) //nothing happens if character is alphabet
        {
        }
        else
        {
            secondSentence[i] = '#'; //sets all non alpha characters to sentinel char #
        }
    }
    for(int i = 0; i < sentence2Length; i++)
    {
        if(secondSentence[i] != '#')
        {
            filteredSentence2 = filteredSentence2 + secondSentence[i];
        }
    }    
    allLowercase(filteredSentence1, filteredSentence1.size());
    allLowercase(filteredSentence2, filteredSentence1.size());
    if((printFreq(filteredSentence1, filteredSentence1.size())) == (printFreq(filteredSentence2, filteredSentence2.size())))
    {
        cout << "The strings are anagrams." << endl;
    }
    else
    {
        cout << "The strings are not anagrams." << endl;
    }
    return 0;
}

// FUNCTION DEFINITIONS
void allLowercase(string &sentence, int size)
{
    for(int n = 0; n < size; n++)
    {
        sentence[n] = tolower(sentence[n]);
    }
}

string printFreq(string &sentence, int size)
{
    char currentCharacter;
    int characterIndex;
    int alphabet[26] = {0};
    string key;
    for(int i = 0; i < size; i++)
    {
        characterIndex = sentence[i] - 'a';
        alphabet[characterIndex]++;
    }

    for(int i = 0; i < 26; i++)
    {
        if(alphabet[i] > 0)
        {
            currentCharacter = i + 'a';
            key = key + currentCharacter + to_string(alphabet[i]);
        }
    }
    return key;
}
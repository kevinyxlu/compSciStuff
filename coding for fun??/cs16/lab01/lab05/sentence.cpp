//sentence.cpp
//Created by: Kevin Lu
//Created on: 11/3/2020
//Lab Partner: Vince Nguyen

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

//FUNCTION DECLARATIONS
void sortString(string &sentence, int size);
//Precondition: sentence is a string consisting of only alphabetical characters
//Postcondition: prints the string but alphabetically sorted by ASCII characters

void printFreq(string &sentence, int size);
//Precondition: sentence is a string consisting of only alphabetical characters
//PostconditionL prints out all unique characters of a string and their frequencies

int main()
{
    string sentence;
    // MISSING (short) CODE HERE TO GET SENTENCE FROM USER (you can remove these comments)
    cout << "Enter sentence: ";
    getline(cin, sentence);
    int sentenceLength;
    string filteredSentence;
    sentenceLength = sentence.size();
    for(int i = 0; i < sentenceLength; i++)
    {
        if(isalpha(sentence[i])) //nothing happens if character is alphabet
        {
        }
        else
        {
            sentence[i] = '#'; //sets all non alpha characters to sentinel char #
        }
    }

    for(int i = 0; i < sentenceLength; i++)
    {
        if(sentence[i] != '#')
        {
            filteredSentence = filteredSentence + sentence[i];
        }
    }

    cout << "Sorted and cleaned-up sentence:";
    sortString(filteredSentence, filteredSentence.size());
    printFreq(filteredSentence, filteredSentence.size());

	return 0;
}

// MISSING FUNCTION DEFINITIONS HERE (you can remove these comments)
void sortString(string &sentence, int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = i; j < size; j++)
        {
            if(sentence[i] > sentence[j])
            {
                char temp;
                temp = sentence[i];
                sentence[i] = sentence[j];
                sentence[j] = temp;
            }
        }
    }
    cout << sentence << endl;
}

void printFreq(string &sentence, int size)
{
    char currentCharacter;
    int characterIndex;
    int alphabet[58] = {0};
    for(int i = 0; i < size; i++)
    {
        characterIndex = sentence[i] - 'A';
        alphabet[characterIndex]++;
    }

    for(int i = 0; i < 58; i++)
    {
        if(alphabet[i] > 0)
        {
            currentCharacter = i + 'A';
            cout << currentCharacter << ": " << alphabet[i] << endl;
        }
    }
}
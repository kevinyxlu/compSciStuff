//rhymes.cpp
//Created by: Kevin Lu
//Created on: 11/10/2020
//Lab Partner: Vince Nguyen

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

//FUNCTION DECLARATIONS:
string extractLastWord(string line);
//Precondition: line is a line of words
//Postcondition: returns the last word of the line

bool compareWords(string word1, string word2);
//Precondition: word1 and word2 are two strings of alphabetic characters
//Postcondition: returns true if the last 2 characters of both words are the same
//               returns false otherwise

string wordClean(string word);
//Precondition: takes in the output from extractLastWord()
//Postcondition: removes all characters from word that are not alphabetic

int main()
{
    ifstream inStream;
    ofstream outStream;
    string inputName, currentWord, lastWord, currentLine;
    char currentChar;
    int numLines = -1, numRhymes = 0; //numLines will be 0 if a blank text document is input


    //prompts user for file name and saves it in inputName
    cout << "Enter filename: "; 
    cin >> inputName;
    cout << endl;
    inStream.open(inputName); //opens the input file
    if (inStream.fail())
    {
        cerr << "Input file opening failed.\n";
        exit(1);
    }
    while(! inStream.eof())
    {
        do
        {
            inStream.get(currentChar);
            currentLine += currentChar;
        } while(currentChar != '\n' && !inStream.eof());
        numLines = numLines + 1;
        currentWord = wordClean(extractLastWord(currentLine));

        if(lastWord != "")
        {
            if(compareWords(lastWord,currentWord))
            {
                cout << lastWord << " and " << currentWord << '\n';
                numRhymes = numRhymes + 1;
            }
        }
        lastWord = currentWord;
        currentLine = "";
    }
    double density = static_cast<double>(numRhymes) / numLines;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    if(numRhymes == 0) //print statements for the results
    {
        cout << "No rhymes found." << '\n';
        if(numLines == 1)
        {
            cout << "There is 1 line in this poem.";
        }
        else
        {
            cout << "There are " << numLines << " lines in this poem.\n";
        }
    }
    else
    {
        if(numRhymes == 1)
        {
            cout << "There is 1 pair of rhyming words." << '\n';
        }
        else
        {
            cout << "There are " << numRhymes << " pairs of rhyming words.\n";
        }
        if(numLines == 1)
        {
            cout << "There is 1 line in this poem, so the rhyme-line density is: " << density << endl;
        }
        else
        {
            cout << "There are " << numLines << " lines in this poem, so the rhyme-line density is: " << density << endl; 
        }
    }

    inStream.close();
    return 0;
}


//FUNCTION DEFINITIONS:
string extractLastWord(string line)
{
    string lastWord;
    int lastSpaceIndex;
    for(int n = line.size() - 1; n > 0; n--)
    {
        if(line[n] == ' ')
        {
            lastWord = line.substr(n, line.size());
            return lastWord;
        }
    }
}

string wordClean(string word)
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
    return filteredWord;
}

bool compareWords(string word1, string word2)
{
    char word1last1, word1last2, word2last1, word2last2;
    word1last1 = word1[word1.size() - 1];
    word1last2 = word1[word1.size() - 2];
    word2last1 = word2[word2.size() - 1];
    word2last2 = word2[word2.size() - 2];
    if((word1last1 == word2last1) && (word1last2 == word2last2)) //returns true or false depending on if the last 2
    {                                                            //of both words match
        return true;
    }
    else
    {
        return false;
    }
}
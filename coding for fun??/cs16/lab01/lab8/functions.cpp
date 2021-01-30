//functions.cpp
//Created by: Kevin Lu
//Created on: 12/1/2020
//Lab Partner: Vince Nguyen

AString::AString() //default constructor that just makes the string value an empty string to rid garbage values
{
    StringValue = "";
}

AString::AString(string str) //string that allows user to set value of the object
{
    StringValue = str;
}

void AString::getAString() //alows the program to get a string with whitespace
{
    getline(cin, StringValue);
}

void AString::cleanUp()
{
    string firstSentence = "";
    string filteredSentence = ""; //variable for output with non alphabet characters removed and all characters to lowercase
    firstSentence = StringValue;
    int sentenceLength;
    sentenceLength = StringValue.length();

    for(int i = 0; i < sentenceLength; i++)
    {
        if(isalpha(firstSentence[i])) //nothing happens if character is alphabet
        {
        }
        else
        {
            firstSentence[i] = '#'; //sets all non alpha characters to sentinel char #
        }
    }
    for(int i = 0; i < sentenceLength; i++)
    {
        if(firstSentence[i] != '#')
        {
            filteredSentence = filteredSentence + firstSentence[i];
        }
    }

    int filteredSentenceLen = filteredSentence.length();
    for(int n = 0; n < filteredSentenceLen; n++)
    {
        filteredSentence[n] = tolower(filteredSentence[n]);
    }
    StringValue = filteredSentence; //updates the value of stringvalue to the filtered sentence
}

void AString::printString() //test function for printing out the string
{
    cout << StringValue << endl;
}

void AString::countLetters(int array[])
{
    char currentChar;
    for(int i = 0; i < StringValue.size(); i++)
    {
        currentChar = StringValue[i];
        array[currentChar - 'a']++;
    }
}

bool compareCounts(int array1[], int array2[]) 
{
    bool result = false;
    for(int n = 0; n < 26; n++)
    {
        if(array1[n] == array2[n])
        {
        }
        else
        {
            result = true;
        }
    }
    return result;
}
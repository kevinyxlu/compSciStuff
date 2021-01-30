//rhymes.cpp
//Vince Nguyen
//8699449
//Lab Partner: Kevin Lu
#include <iostream>
#include <string>
#include <fstream>
using namespace std;



string extractLastWord(string line);
//PreCondition: Takes in a string, a line of the input.
//PostCondition: Returns the last word of the string
bool compareLastWords(string word1, string word2);
//PreCondition: Takes in 2 words that are only contain alphabetical characters
//PostCondition: Returns True if the words share the same last 2 characters.  Else false
string cleanUpWord(string word);
//PreCondition: Takes in a string, the last word of a line.
//PostCondition: Returns the string without any non-alphabetical characters.

int main(){
	//Set precision to 2
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	//Declare input stream
	ifstream inStream;

	//Recieve filename as input
	string inputFile = "";
	cout << "Enter filename: ";
	cin>>inputFile;
	cout<< '\n';

	//Connect stream to input file
	inStream.open(inputFile);  

	//Check if the stream failed to conenct to the file.  If so, display error message and exit
	if(inStream.fail()){
		cerr << "Input file opening failed.";
		exit(1);
	}

	//variables are declared or initialized
	string previousWord = "", currentWord = "", currentLine = "";
	char currentCharacter;
	int numberOfRhymes = 0,numberOfLines = -1;

	//Read input from the file from start to end
	while(!inStream.eof()){
		//Take in a line
		do{
			inStream.get(currentCharacter);
			currentLine += currentCharacter;
		} while(currentCharacter != '\n' && !inStream.eof());

		//Increment number of lines
		numberOfLines++;	

		//Extract the last word from the line and clean it up.
		currentWord = extractLastWord(currentLine);
		currentWord = cleanUpWord(currentWord);

		//Compare current word with the line before it.  If they "rhyme", print out the pair and increment number of rhymes
		if(previousWord != ""){
			if(compareLastWords(previousWord,currentWord)){
				cout << previousWord << " and " << currentWord << '\n';
				numberOfRhymes++;
			}
		}

		//Asign previousWord to currentWord
		previousWord = currentWord;
		currentLine = "";
	}

	//calculate rhyme-line density
	double density = static_cast<double>(numberOfRhymes)/numberOfLines;

	//Output results.  Grammer varies depending whether the number of rhymes or lines are plural or singular.
	if(numberOfRhymes == 0){
		cout << "No rhymes found." << '\n';
		if(numberOfLines == 1){
			cout << "There is 1 line in this poem.";
		}else{
			cout << "There are " << numberOfLines << " lines in this poem.";
		}
	}else{
		if(numberOfRhymes == 1){
			cout << "There is 1 pair of rhyming words." << '\n';
		}else{
			cout << "There are " << numberOfRhymes << " pairs of rhyming words." << '\n';
		}
		if(numberOfLines == 1){
			cout << "There is 1 line in this poem, so the rhyme-line density is: " << density;
		}else{
			cout << "There are " << numberOfLines << " lines in this poem, so the rhyme-line density is: " << density;
		}
	}
	
	//Close connection from stream to file
	inStream.close();
}

string extractLastWord(string line){
	string sentence = " " + line; //This is for edge cases where the line is 1 word
	for(int i = sentence.size()-1; i >= 0; i--){ //starting at the end, go backwards.  If a space is found, whatever is to the right of the space is the last word.
		if(sentence[i] == ' '){
			return sentence.substr(i+1,sentence.size()-i-1);
		}
	}
}

bool compareLastWords(string word1, string word2){
	int wordOneSize = word1.size(), wordTwoSize = word2.size();  //If the last 2 characters of the words are equal, then return true. else return false
	if(word1[wordOneSize-1] == word2[wordTwoSize-1] && word1[wordOneSize-2] == word2[wordTwoSize-2]){
		return true;
	}
	return false;
} 

string cleanUpWord(string word){
	string filteredWord = "";
	for(int i = 0; i < word.size(); i++){ //If the word is alphabetical, it is appened to the filteredWord.
		if(isalpha(word[i])){
			filteredWord += word[i];
		}
	}
	return filteredWord;
}
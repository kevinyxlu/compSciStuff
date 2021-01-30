//converter.cpp
//Vince Nguyen
//8699449

#include <iostream>
#include <string>
using namespace std;
string convertFromDec(unsigned int decum, unsigned int base);
//Precondition: Takes in 2 positive integers in decimal form.
//Postcondition: Returns a string that converts decum to base.


string numberToCharacterIndex = "0123456789ABCDEF"; //converts the number into a character string[number] = character
int main(){
	//declare current Number and ask for the first input
	int currentNumber;
	cout << "Enter positive decimal number (anything else quits): ";
	cin >> currentNumber;

	//while currentNumber > 0, run the program.  If currentNumber <=0 quit.
	while(currentNumber > 0){
		cout << currentNumber << " in binary is: " << convertFromDec(currentNumber,2) << '\n';
		cout << currentNumber << " in octal is: " << convertFromDec(currentNumber,8) << '\n';
		cout << currentNumber << " in hex is: " << convertFromDec(currentNumber,16) << "\n\n";
		cout << "Enter positive decimal number (anything else quits): ";
		cin >> currentNumber;
	}

	return 0;
}


string convertFromDec(unsigned int decum, unsigned int base){
	//Declare variables
	string convertedString = "";
	int remainder;

	while(decum > 0){
		remainder = decum%base; //get the remainder of the current number and add it to the beginning of convertedString
		decum /= base;
		convertedString = numberToCharacterIndex[remainder] + convertedString;
	}

	return convertedString;
}
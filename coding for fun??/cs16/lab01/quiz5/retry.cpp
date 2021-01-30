//template.cpp
//Created by: Kevin Lu
//Created on: 10/20/2020
//Lab Partner: 

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void findAllStrings(string input_string, string sub_string);

int main()
{
    findAllStrings("With a banjo on my knee and ban the bomb-ban!", "ban");
}


// pre-Condition: function is given an input_string and a sub_string.
//                Assume the sub_string is found at least ONCE 
//                in the input_string
// post-Condition: function prints out, on separate lines, the
//                 string indices of the start of each occurrence of 
//                 the sub-string in the given string.
// Example: 
// input_string = "With a banjo on my knee and ban the bomb-ban!"
// sub_string = "ban"
// The function prints this:
// 7
// 28
// 41
void findAllStrings(string input_string, string sub_string) {
    int index_of_found = 0, next_position = 0;

    while (index_of_found != -1) {
        int sub_string_size = sub_string.size();
        index_of_found = input_string.find(sub_string, next_position);
        next_position = index_of_found + 1;
        if(index_of_found != -1)
        {
            cout << index_of_found << endl;
        }
// MISSING CODE HERE
}
}
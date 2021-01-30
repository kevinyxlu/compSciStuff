#include "trie.hpp"

#include <algorithm>
#include <cctype>
#include <stack>
#include <utility>
#include <cstring>
#include <string>
using namespace std;

string removeFirstChar(string str);
string removeFirstChar(string str)
//precondition: str is a string
//postcondition: returns str, but without the first character
//               -ex- inputting "cshard" would return "shard"
{
    string newstr = "";
    for(int i = 1; i < str.length(); i++)
    {
        newstr = newstr + str[i];
    }
    return newstr;
}

string removeLastChar(string str);
string removeLastChar(string str)
//precondition: str is a string
//postcondition: returns str, but without the last character
//               -ex- inputting "cshard" would return "cshar"
{
    string newstr = "";
    for(int i = 0; i < str.length() - 1; i++)
    {
        newstr = newstr + str[i];
    }
    return newstr;
}

string cstringToString(char const* const str);
string cstringToString(char const* const str)
//precondition: str is a cstring
//postcondition: returns a string equivalent to the cstring
{
    string newStr = "";
    int cstringLen;
    cstringLen = strlen(str);
    for(int i = 0; i < cstringLen; i++)
    {
        newStr = newStr + str[i];
    }
    return newStr;
}

char* stringToCstring(string str);
char* stringToCstring(string str)
//precondition: str is a string
//postcondition: returns a cstring equivalent to str
{
    char* cstr = new char [str.length() + 1];
    strcpy(cstr, str.c_str());
    return cstr;
}

//default constructor
Trie::Trie():end_of_word(false) 
{
    // TODO: There's a little more initialization to do here, but what?
    end_of_word = false;
    for(int x = 0; x < 26; x++)
    {
        roots[x] = NULL;
    }
}

//copy constructor
Trie::Trie(Trie const& other):end_of_word(other.end_of_word)
{
    end_of_word = other.end_of_word; 
    // TODO: Remember to do a deep copy of your structure!
    for(int x = 0; x < other.roots.size(); x++)
    {
        if(other.roots[x] == NULL)
        {
            this->roots[x] = NULL;
        }
        else
        {
            Trie *temp = new Trie;
            temp->roots[x] = other.roots[x];
            this->roots[x] = temp->roots[x];
            delete temp; 
        }
    }
}

Trie::~Trie(){
    // TODO: Clean up your children!
    
}

Trie& Trie::operator=(Trie const& other){
    // TODO: Remember to do a deep copy of your structure!
    if(this == &other)
    {
        return *this;
    }
    return *this;
}


void Trie::insert(char const* const str)
{
    // Skip any characters that don't pass std::islower() after
    //  being put through std::tolower; they're not letters.
    // If you encounter a '\0', what flag should be set
    //  to note this point as the end of an input?
    // For other characters, identify a position in your 
    //  roots array by which letter you were given.
    // Remember, characters are numbers in computers!
    // What could you do to have an ID of 0 for 'a'?
    // (Hint: Take a look at an ASCII table!)

    // (Hint: This operation is easier if you use recursion.)

    // TODO: Fix this function
    Trie* current = this;
    string stdStr; // just str but in string and not cstring form
    stdStr = cstringToString(str);
    int alphaIndex;
    alphaIndex = stdStr[0] - 'a'; //safe to do str[0] since the only str's that will get pass the if statement will be 1 char long strings
    if(roots[alphaIndex] == NULL)
    {
        Trie* newNode = new Trie; //alloc new node, where newNode is the memory address of the new node
        current->roots[alphaIndex] = newNode; //put newly allocated node's mem address into the right place in current node's array   
        (*newNode).end_of_word = false; //set the new node's wordEnd value to false
        /////////JUST CODE FOR TRACING///////
        for(int i = 0; i < 26; i++)
        {
            cout << current->roots[i] << " ";
        }  
        cout << endl;
        //////////////////////////////////////      
        current = newNode; //update "current" pointer to point to one generation lower
    }
    stdStr = removeFirstChar(stdStr); //remove first char of the string

    for(int i = 0; i < stdStr.length() - 1; i++)
    {
        if(current->roots[alphaIndex] == NULL)
        {
            alphaIndex = stdStr[i] - 'a'; //update alphaIndex
            Trie* newNode = new Trie; //alloc new node
            current->roots[alphaIndex] = newNode; //put newly allocated node's mem address into the right place in current node's array
            (*newNode).end_of_word = false;
            /////////JUST CODE FOR TRACING///////
            for(int i = 0; i < 26; i++)
            {
                cout << current->roots[i] << " ";
            }  
            cout << endl;
            //////////////////////////////////////  
            current = newNode;
            //stdStr = removeFirstChar(stdStr);
        }
    }

    if(current->roots[alphaIndex] == NULL)
    {
        alphaIndex = stdStr[stdStr.length() - 1] - 'a'; //update alphaIndex
        Trie* newNode = new Trie; //alloc new node
        current->roots[alphaIndex] = newNode; //put newly allocated node's mem address into the right place in current node's array
        (*newNode).end_of_word = true;
        /////////JUST CODE FOR TRACING///////
        for(int i = 0; i < 26; i++)
        {
            cout << current->roots[i] << " ";
        }  
        cout << "SECOND TO LAST NODE CONTAINING PTR AT INDEX OF LAST LETTER" << endl;
        //////////////////////////////////////
        current = newNode; //update current pointer to point at one generation lower  
    }

    for(int i = 0; i < 26; i++)
    {
        cout << current->roots[i] << " ";
    }
    cout << "LAST NODE (SHOULD BE ALL NULL)\n";
}

bool Trie::check(char const* const str) const
{
    // Iterate through the same way as you insert.
    // What should you check to determine whether the current point
    //  is the end of the input? When you get there, of course.
    // You're trying to match the exact, entire input.

    // (Hint: This operation is easier if you use recursion.)

    // TODO: Fix this stub
    return false;
}

char* Trie::firstWithPrefix(char const* const str,unsigned depth) const{
    // You'll need two paths to solve this problem:
    
    // Case 1: You've used up all characters in str and are looking for
    //  the next stored input. Search depth-first in lexographic (a-z) order, 
    //  stopping when you encounter the first endpoint you marked in insert().

    // Case 2: You have characters left in the input. Act like check(),
    //  but when you run out of input, proceed to the other case.

    // If you can't find any matching roots to a chunk of input, return NULL.
    // If you encounter unrecognized characters in the input, skip them.
    // Increment depth on every recursion, except unrecognized characters.

    // For your return value, you can't allocate your cstring in advance 
    //  because you do not know how deep in the structure you will have to 
    //  search. Instead, increment depth on every (not-unrecognized) recursion.
    //  Then, when you reach an end of word you want to return, allocate your
    //  new char[depth+1] and fill it backward, based on your depth!

    // Remember to check whether your recursive call gave you back NULL!

    // TODO: Fix this stub.
    return NULL;
}


Trie load_trie(std::istream& is){
    // Given an open input stream, read words on separate lines into a new Trie.
    // If no lines can be read from the input stream, return a default-constructed Trie.
    // Otherwise, return a Trie filled with all words that can be read until the
    //  first empty line.

    // Words will be placed on individual lines, like:
    //     apple
    //     application
    //     applied
    //     apply
    //
    // (The last line there was empty, indicating the end of the dictionary.)
    // You can read these easily with one of the formats of std::getline().
    // Remember, you already skip whitespace in Trie::insert(), so don't worry
    //  about stripping any whitespace here!

    // TODO: Fix this stub.
    return Trie();
}

Trie load_trie(std::string filename){
    // Open an input stream to the file `filename`, 
    //  then pass that input stream to the other form of load_trie().

    // Should be easy!

    return Trie();
}

int main()
{
    Trie test;
    test.insert("there");

    cout << "-------EXISTING IN TREE TEST-------\n";
    if(test.check("there"))
    {
        cout << "   returned true-TEST PASSED-       \n";
    }
    else
    {
        cout << "   returned false-TEST FAILED-       \n";
    }
    cout << endl;

    cout << "-----NOT EXISTING IN TREE TEST-----\n";
    if(test.check("they"))
    {
        cout << "   returned true-TEST FAILED-       \n";
    }
    else
    {
        cout << "   returned false-TEST PASSED-       \n";
    }    

    return 0;
}

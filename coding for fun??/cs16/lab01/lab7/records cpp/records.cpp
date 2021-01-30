// USE THIS FILE AS-IS - DO NOT CHANGE ANY OF THIS
//
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "headers.h"
#include "functions.cpp"

void InitializeStructures(UndergradStudents us[], int &size);
void WriteResults(ofstream &outf, UndergradStudents us[], int size);

// YOU HAVE TO COMPLETE THESE 2 FILES:

int main() {
    UndergradStudents ObjArray[20];
    int ObjArraySize;
    ofstream outf;

    InitializeStructures(ObjArray, ObjArraySize);
    WriteResults(outf, ObjArray, ObjArraySize);
    
    return 0;
}

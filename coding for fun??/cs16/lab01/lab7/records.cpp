// USE THIS FILE AS-IS - DO NOT CHANGE ANY OF THIS
//
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct UndergradStudents
{
    int studentID;
    string firstName, lastName, major;
    double gpa1, gpa2, gpa3, gpa4;
};

void InitializeStructures(UndergradStudents us[], int &size);
void WriteResults(ofstream &outf, UndergradStudents us[], int size);
void sortStudents(UndergradStudents us[], int size);

// YOU HAVE TO COMPLETE THESE 2 FILES:
//#include "headers.h"
//#include "functions.cpp"

int main() {
    UndergradStudents ObjArray[20];
    int ObjArraySize;
    ofstream outf;

    InitializeStructures(ObjArray, ObjArraySize);
    WriteResults(outf, ObjArray, ObjArraySize);
    
    return 0;
}



void sortStudents(UndergradStudents us[], int size)
{
    //sort algorithm
    UndergradStudents temp;
    for (int i = size; i > 0; i--) 
    {
        for (int j = 1; j < i; j++) 
        {
            if (us[j-1].lastName > us[j].lastName) 
            {
                temp = us[j-1];
                us[j-1] = us[j];
                us[j] = temp;
            } // if
        } // for j
    } // for i
}

void InitializeStructures(UndergradStudents us[], int &size) {
    string firstName = "default";
    int currentIndex = 0;
    while(firstName != "X" && (currentIndex <= 19)) //keeps asking for new input until 20 students or until X is typed in for first name
    {
        us[currentIndex].studentID = currentIndex + 1;
        cout << "Enter first name for student " << currentIndex + 1 << " (or X to quit): ";
        cin >> firstName;
        if(firstName != "X") //exits program if first name is 
        {
            us[currentIndex].firstName = firstName;
            cout << "Enter last name for student " << currentIndex + 1 << ": ";
            cin >> us[currentIndex].lastName;
            cout << "Enter major for student " << currentIndex + 1 << ": ";
            cin >> us[currentIndex].major;
            cout << "Enter GPA Year 1 for student " << currentIndex + 1 << ": ";
            cin >> us[currentIndex].gpa1;
            cout << "Enter GPA Year 2 for student " << currentIndex + 1 << ": ";
            cin >> us[currentIndex].gpa2;
            cout << "Enter GPA Year 3 for student " << currentIndex + 1 << ": ";
            cin >> us[currentIndex].gpa3;
            cout << "Enter GPA Year 4 for student " << currentIndex + 1 << ": ";
            cin >> us[currentIndex].gpa4;
            cout << endl;
            currentIndex = currentIndex + 1; //goes on the next student
        }
        else
        {
        }
    }
}

void WriteResults(ofstream &outf, UndergradStudents us[], int size) 
{
    outf.open("Results.txt");
    sortStudents(us, 20);
    outf << "These are the sorted results:\n";
    int i = 0;
    while(i < 20)
    {
        double averageGPA;
        averageGPA = (us[i].gpa1 + us[i].gpa2 + us[i].gpa3 + us[i].gpa4) / 4; //finds average GPA
        outf << "ID# " << us[i].studentID << ", " << us[i].lastName << ", " << us[i].firstName << ", Average GPA: " << averageGPA << endl;
        i = i + 1;
    }
    outf.close();
}

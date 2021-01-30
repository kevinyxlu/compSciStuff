//file: headers.h
//name: Matthew Ho
//date: 17 nov 2020
//skeleton: Prof. Matni

struct UndergradStudents {
	int id;
	string first;
	string last;
	string major;
	double gpa[4];
};


//instructions say not to edit records.cpp so I'm writing conditions here

//void InitializeStructures(UndergradStudents us[], int &size);
//Pre-condition: takes an array of size 20 of student structs, and an int variable size
//Post-condition: fills array with user inputted student data and sets size to
//the number of students inputted (stops prompting when 20 students are inputted or
//user inputs "X" for first name).

//void WriteResults(ofstream &outf, UndergradStudents us[], int size);
//Pre-condition: takes an ofstream variable, an array of students, and the number of students
//Post-condition: writes student data to "Results.txt" in alphabetical order

void ReadStudent(int id, UndergradStudents& temp);
//Pre-condition: takes a student id and student struct
//Post-condition: sets student's last name, major, and yearly gpa with standard input

void SortStudents(UndergradStudents us[], int size);
//Pre-condition: takes an array of student structs and its integer size
//Post-condition: sorts array by ascending alphabetical last name order


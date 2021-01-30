// Vince Nguyen

// DEFINE STRUCTURE HERE -- MISSING!
struct UndergradStudents{
	int ID;
	string firstName;
	string lastName;
	string major;
	double GPAyear1;
	double GPAyear2;
	double GPAyear3;
	double GPAyear4;
};

// DECLARE FUNCTIONS HERE.
void InitializeStructures(UndergradStudents us[], int &size);
//PreCondition: Takes an in empty array of struct UndergradStudents and 0 for size.
//PostCondition: Takes in user-input in order to initialize the struct array while getting the size of the array as well.
void BubbleSort(UndergradStudents us[], int size);
//PreConddition: Takes in an array of struct UndergradStudent and its size
//PostCondition: Sorts the struct in the struct array by last name in ascending alphabetical order using bubble sort
void WriteResults(ofstream &outf, UndergradStudents us[], int size);
//PreCondition: Takes in an output stream, a UndergradStudents struct array, and the size of the array.
//PostCondition: Outputs the contents of each struct in the array by alphabetical order by last name.

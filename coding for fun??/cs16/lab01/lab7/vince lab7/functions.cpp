// Vince Nguyen

// DEFINE YOUR FUNCTIONS HERE
// They have to be declared in the "headers.h" file.
//
// You *have* to use these 2 functions (already declared in records.cpp), 
// but you may add other functions in here as well, if you want.
// See hint in the lab description document.
void InitializeStructures(UndergradStudents us[], int &size) {
	bool exit = false;
	string buffer = "";
	while(size < 20 && !exit){
		cout << "Enter first name for student " << size + 1<< " (or X to quit): ";
		
		getline(cin,us[size].firstName);

	    if(us[size].firstName == "X"){ //If firstName is X, the while loop will be exited
	    	exit = true;
	    }

	    //Ask the User which data to input and stores the input into a struct in the array.
	    if(!exit){
	    	cout << "Enter last name for student " << size + 1 << ": ";
	    	getline(cin,us[size].lastName);
	    	cout << "Enter major for student " << size + 1 << ": ";
	    	getline(cin,us[size].major);
	    	cout << "Enter GPA Year 1 for student " << size + 1 << ": ";
	    	cin >> us[size].GPAyear1;
	    	cout << "Enter GPA Year 2 for student " << size + 1 << ": ";
	    	cin >> us[size].GPAyear2;
	    	cout << "Enter GPA Year 3 for student " << size + 1 << ": ";
	    	cin >> us[size].GPAyear3;
	    	cout << "Enter GPA Year 4 for student " << size + 1 << ": ";
	    	cin >> us[size].GPAyear4;
	    	getline(cin,buffer); //Clears the input buffer "\n" left after cin.  This is so the next getline doesn't store "\n".
	    	us[size].ID = size + 1;
	    	size++;
	    }

	    cout<<'\n';
	}
}

void BubbleSort(UndergradStudents us[], int size){
	UndergradStudents temp;
	for(int i = 0; i < size-1; i++){
		for(int j = 0; j < size-i-1; j++){
			if(us[j+1].lastName < us[j].lastName){
				temp = us[j+1];
				us[j+1] = us[j];
				us[j] = temp;
			}
		}
	}
}

void WriteResults(ofstream &outf, UndergradStudents us[], int size) {
	//Connect output stream to file
	outf.open("Results.txt");
	
	//Set Precision
	outf.setf(ios::fixed);
	outf.setf(ios::showpoint);
	outf.precision(2);

	//Sort Array
	BubbleSort(us,size);

	//Output Sorted Array
	double averageGPA = 0;
	outf << "These are the sorted results:" << '\n';
	for(int i = 0; i < size; i++){
		averageGPA = (us[i].GPAyear1 + us[i].GPAyear2 + us[i].GPAyear3 + us[i].GPAyear4)/4;
		outf << "ID# " << us[i].ID << ", " << us[i].lastName << ", " << us[i].firstName << ", " <<us[i].major << ", Average GPA: " << averageGPA << '\n';
	}

	//Close connection
	outf.close();
}


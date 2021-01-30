//file: functions.cpp
//name: Matthew Ho
//date: 17 nov 2020
//skeleton: Prof. Matni

void ReadStudentInfo(int id, UndergradStudents& temp){
	//declare temporary student struct, set student id
	temp.id = id;

	//read in last name and major
	cout << "Enter last name for student " << id << ": ";
	getline(cin, temp.last);
	cout << "Enter major for student " << id << ": ";
	getline(cin, temp.major);

	//read gpa with a loop
	for(int i = 0; i < 4; i++){
		cout << "Enter GPA Year " << i + 1
		     << " for student " << id << ": ";
		cin >> temp.gpa[i];
	}

	//discard extra newline left by cin
	string garbage;
	getline(cin, garbage);
}

void InitializeStructures(UndergradStudents us[], int &size){
	//set size to 0, declare temporary student struct, get first input
	size = 0;
	UndergradStudents temp;
	cout << "Enter first name for student 1 (or X to quit): ";
	getline(cin, temp.first);

	//keep getting input until list is full or user enters X
	while(size < 20 && temp.first != "X"){
		//read input into student array, increment size
		ReadStudentInfo(size + 1, temp);
		us[size] = temp;
		size++;

		cout << endl;
		//read input for next iteration)
		if(size < 20){
			cout << "Enter first name for student "
		     	     << size + 1 << " (or X to quit): ";
			getline(cin, temp.first);
		}
	}
}

void WriteResults(ofstream &outf, UndergradStudents us[], int size){
	//alphabetize students, open file, write first line of output
	//and declare variables for calculating gpa average
	SortStudents(us, size);
	outf.open("Results.txt");
	outf << "These are the sorted results:" << endl;
	double sum, avg;

	//write ouput for each student in array
	for(int i = 0; i < size; i++){
		//find average gpa
		sum = 0;
		for(int j = 0; j < 4; j++){
			sum += us[i].gpa[j];
		}
		avg = sum / 4;

		//format and write output
		outf.setf(ios::fixed);
		outf.setf(ios::showpoint);
		outf.precision(2);
		outf << "ID# " << us[i].id << ", "
		     << us[i].last << ", "
		     << us[i].first << ", "
		     << us[i].major << ", "
		     << "Average GPA: " << avg << endl;
	}	
	outf.close();
}

void SortStudents(UndergradStudents us[], int size){
	//standard bubble sort
	//order of two students are determined by their last name
	UndergradStudents temp;
	for(int i = size; i > 0; i--){
		for(int j = 1; j < i; j++){
			if(us[j - 1].last > us[j].last){
				temp = us[j - 1];
				us[j - 1] = us[j];
				us[j] = temp;
			}
		}
	}
}

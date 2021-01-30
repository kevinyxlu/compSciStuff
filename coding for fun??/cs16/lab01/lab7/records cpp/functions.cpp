//functions.cpp
//Created by: Kevin Lu
//Created on: 11/17/2020
//Lab Partner: Vince Nguyen
//sort algorithm inspired from quiz 6

// DEFINE YOUR FUNCTIONS HERE
// They have to be declared in the "headers.h" file.
//
// You *have* to use these 2 functions (already declared in records.cpp), 
// but you may add other functions in here as well, if you want.
// See hint in the lab description document.

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
    string tempFirstName = "default";
    string garbage;
    int currentIndex = 0;
    while(tempFirstName != "X" && (currentIndex <= 19)) //keeps asking for new input until 20 students or until X is typed in for first name
    {
        us[currentIndex].studentID = currentIndex + 1;
        cout << "Enter first name for student " << currentIndex + 1 << " (or X to quit): ";
        getline(cin, tempFirstName);
        if(tempFirstName != "X") //exits program if first name is 
        {
            us[currentIndex].firstName = tempFirstName;
            cout << "Enter last name for student " << currentIndex + 1 << ": ";
            getline(cin, us[currentIndex].lastName);
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
            getline(cin, garbage);
            cout << endl;
            currentIndex = currentIndex + 1; //goes on the next student
        }
        else
        {
        }
    }
    size = currentIndex;
}

void WriteResults(ofstream &outf, UndergradStudents us[], int size) 
{
    outf.open("Results.txt");
    sortStudents(us, size);
    outf << "These are the sorted results:\n";
    int i = 0;
    double averageGPA;
    while(i < size)
    {
        averageGPA = (us[i].gpa1 + us[i].gpa2 + us[i].gpa3 + us[i].gpa4) / 4; //finds average GPA
        outf.setf(ios::fixed);
		outf.setf(ios::showpoint);
		outf.precision(2);
        outf << "ID# " << us[i].studentID << ", " << us[i].lastName << ", " << us[i].firstName << ", " << us[i].major << ", Average GPA: " << averageGPA << endl;
        i = i + 1;
    }
    outf.close();
}

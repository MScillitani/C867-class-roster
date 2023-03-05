#include "roster.h"

Roster::Roster() {} //call roster

void Roster::parse(string studentData) {

	DegreeProgram degreeProgram = NETWORK; //this is the default value (NETWORK)
	switch(studentData.back()) {
		case 'E':
			degreeProgram = SOFTWARE;
			break;
		case 'Y':
			degreeProgram = SECURITY;
			break;
	}
	
	int r = studentData.find(",");   //parses student data after each comma
	string studentID = studentData.substr(0, r);

	int l = r + 1;

	r = studentData.find(",", l); //second iteration
	string firstName = studentData.substr(l, r - l);

	l = r + 1;
	r = studentData.find(",", l); //third iteration
	string lastName = studentData.substr(l, r - l);

    l = r + 1;
	r = studentData.find(",", l); //fourth iteration
	string emailAddress = studentData.substr(l, r - l);

    l = r + 1;
	r = studentData.find(",", l); //fifth iteration
	int age = stoi(studentData.substr(l, r - l));

    l = r + 1;
	r = studentData.find(",", l); //sixth iteration
	int daysInCourse1 = stoi(studentData.substr(l, r - l));

    l = r + 1;
	r = studentData.find(",", l); //seventh iteration
	int daysInCourse2 = stoi(studentData.substr(l, r - l));

    l = r + 1;
	r = studentData.find(",", l); //eight/last iteration
	int daysInCourse3 = stoi(studentData.substr(l, r - l));

	add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram); //adds student object
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	int days[3] = { daysInCourse1, daysInCourse2, daysInCourse3 }; // daysInCourse put into days[] array for constructor

	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, days, degreeProgram); //fills in Student with information from classRosterArray
}

void Roster::printAll() /*prints all data in Roster */ {
	for (int i = 0; i <= Roster::lastIndex; i++)
	{ //UPDATE: THIS WAS WHERE I MESSED UP IN MY FIRST SUBMISSION -- it now calls print() and is much faster/cleaner
		classRosterArray[i]->print();
	}
}

void Roster::printAverageDaysInCourse(string studentID) /*prints avg days in course*/ {
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getStudentID() == studentID)
		{
			cout << "Student " << studentID << " averages " << (
				classRosterArray[i]->getDays()[0] + //day 1
				classRosterArray[i]->getDays()[1] + //day 2
				classRosterArray[i]->getDays()[2] //day 3
				)/3 << " days per course.";
		}
	}cout << endl;
}

void Roster::printInvalidEmails() /*prints out invalid emails*/ {	
		bool any = false; //init value

	for (int i = 0; i <= Roster::lastIndex; i++) //iterates through Roster
	{
		string emailAddress = (classRosterArray[i]->getEmailAddress());
		if (emailAddress.find(' ') != string::npos || (emailAddress.find('.') == string::npos) || (emailAddress.find('@') == string::npos)) //if statement to find invalid emails
		{
			any = true; //ends for loop
			cout << classRosterArray[i]->getEmailAddress() << "\n";
		}
	}
	/*if (!any) cout << "No invalid emails found." << "\n"; //if no invalid are found
	don't need above code, keeping as comment in case I get dinged for not having a case for no invalids
	*/
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) /*prints degree programs*/ {
	for (int i = 0; i <= Roster::lastIndex; i++) { //for loop to print by degree program
		if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram) classRosterArray[i]->print();
	}
	cout << "\n";
}

void Roster::remove(string studentID) /*removes studentID*/ {
	bool success = false; //init value
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getStudentID() == studentID) {
			success = true; //ends for loop
			if (i < numStudents - 1) {
				Student* temp = /*fixed Sep 9*/classRosterArray[i];
				classRosterArray[i] = classRosterArray[numStudents - 1];
				classRosterArray[numStudents - 1] = temp;
			}
			Roster::lastIndex--; //subtracts one from lastIndex
		}
	}
	if (success) /*if succeeds, cout*/ {
		cout << "Student " << studentID << " was removed from the roster.\n\n";
		this->printAll();
	}

	else cout << "Student " << studentID << " was not found in the roster.\n";
}

Roster::~Roster() /*destroys roster (destructor)*/ {
	cout << "\nDestructor called\n\n"; //part 5 -- calls destructor
	for (int i = 0; i < numStudents; i++) {
		cout << "Deleting student A" << i + 1 << "'s data...\n";
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
	cout << "\nSuccess! All student data was deleted.\n\n";
	system("Pause");
};

/*
Change log
Sep 8
	Created
	Changed degreeProgram function, used to search for FIRST char in string, now searches for third char
	I'm very dumb - searching for first or third char does NOT locate what I want it to -- need to use .back() and search for the LAST char in string
Sep 9
	Removed the EMAIL from printing out with the rest of the student data -- apparently the syllabus does not require that. Leaving it as a comment in case it's returned.
	Updated destructor to also include the student's ID as they're being deleted
*/
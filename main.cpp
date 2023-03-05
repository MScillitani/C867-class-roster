#include "roster.h"
#include "student.h"

int main() // main method -- part 3F
{ //part 3.1 -- print out student info
	cout << "\nCourse Title: Scripting and Programming - Applications (C867)\nProgramming Language: C++\nWGU Student ID: 007160348\nName: Matthew Scillitani\n\n";

	//Part A: studentData with my personal information as the last student (A5)
	const string studentData[] =
	{ 
		"A1,John,Smith,John1989@g mail.com,20,30,35,40,SECURITY", //student 1
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", //student 2
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", //student 3
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", //student 4
		"A5,Matthew,Scillitani,mscilli@wgu.edu,26,41,27,22,SOFTWARE"  //student 5 (me)
	};

	const int numStudents = 5;
	Roster classRoster; //for part 3.3 -- create a classRoster

	for (int i = 0; i < numStudents; i++) classRoster.parse(studentData[i]);

	cout << "Class Roster:\n\n"; //part 4a
	classRoster.printAll();
	cout << "\n";

	cout << "Invalid email addresses:\n\n"; //part 4b
	classRoster.printInvalidEmails();
	cout << "\n";

	cout << "The student's average number of days in the three courses: \n\n"; //part 4c
	for (int i = 0; i < numStudents; i++) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
	}
	
	cout << "\nDisplaying students in the " << degreeProgramStrings[0] /*0=SECURITY*/<< " degree program.\n\n"; //displays students by degree program (SOFTWARE)
	classRoster.printByDegreeProgram(SECURITY); //shows students in SECURITY
	
	cout << "Removing student A3...\n"; //removes student A3
	classRoster.remove("A3");
	cout << "\n";

	cout << "Removing student A3...\n"; //a second time to show that student A3 is NOT FOUND
	classRoster.remove("A3");
	cout << "\n";

	system("Pause");
	return 0;
};

/*
Changelog
Sep 7 - main.cpp created
Sep 8 - other files created, but can't compile
Sep 8 - figured out how to compile:
	to compile: g++ main.cpp roster.cpp student.cpp
	to run: .\a
Sep 8 - the tabs look atrocious - trying to figure out how to make them evenly spaced without using  a library.
Sep 9 - realized that I was supposed to not have the student's emails printed out -- fixed tab issue
*/
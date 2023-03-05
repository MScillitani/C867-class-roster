#pragma once
#include "student.h"

class Roster {

public: //note to self: order is necessary
	void parse(string student);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram); //part 3a
	void printAll(); //part 3c
	void printAverageDaysInCourse(string studentID); //part 3d - prints average days in course
	void printInvalidEmails(); //part 3e
	void printByDegreeProgram(DegreeProgram degreeprogram); //part 3f
	void remove(string studentID); //for part 3b

	const static int numStudents = 5;
	Student* classRosterArray[numStudents]; //pointer array for roster of students
	int lastIndex = -1;

Roster(); //constructor
~Roster(); //destructor
};

/*
Change log
Sep 8 - created
Sep 9 - checked for accuracy
*/
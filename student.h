#pragma once
#include <string>
#include <iostream>
#include "degree.h"

using namespace std;

class Student {
public:
	const static int daysInCourse = 3; //array constant
	
private: // Student ariables for part D
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int days[daysInCourse];
	DegreeProgram degreeProgram;

public:
	Student(); //empty constructor
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int days[], DegreeProgram degreeProgram); //constructor using all the input parameters
	~Student(); //destructor
	//accessors for part D1
	string getStudentID(); //gets student ID
	string getFirstName(); //gets first name
	string getLastName(); //gets last name
	string getEmailAddress(); //gets email
	int getAge(); //gets age
	int* getDays(); //gets days
	DegreeProgram getDegreeProgram(); //gets degree program
	//mutators for part D1
	void setStudentID(string studentID); //sets student ID
	void setFirstName(string firstName); //sets first name
	void setLastName(string lastName); //sets last name
	void setEmailAddress(string emailAddress); //sets email
	void setAge(int age); //sets age
	void setDays(int days[]); //sets days
	void setDegreeProgram(DegreeProgram degreeProgram); //sets degree program

	void print();
};

/*
Change log
Sep 8 - created
Sep 9 - fixed issue -- array "days[]" was capitalized in Student class -- caused issues like the whole avg days to bug out and say huge numbers
*/
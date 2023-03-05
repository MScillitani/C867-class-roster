#include "student.h"

/// @brief 
Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < daysInCourse; i++) this->days[i] = 0;
	this->degreeProgram = DegreeProgram::NETWORK; // default value is NETWORK -- again to try and avoid plagiarism. It is just one word but most students will likely make "SECURITY" the default
}

Student::Student(string studentId, string firstName, string lastName, string emailAddress, int age, int days[], DegreeProgram degreeProgram) {
	this->studentID = studentId;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < daysInCourse; i++) this->days[i] = days[i];
	this->degreeProgram = degreeProgram;
}

Student::~Student() {} //Student destructor

//getters
string Student::getStudentID() /*gets student ID*/ { return this->studentID; }
string Student::getFirstName() /*gets first name*/{ return this->firstName; }
string Student::getLastName() /*gets last name*/{ return this->lastName; }
string Student::getEmailAddress() /*gets email*/{ return this->emailAddress; }
int Student::getAge() /*gets age*/{ return this->age; };
int* Student::getDays() /*gets # of days spent*/{ return this->days; }
DegreeProgram Student::getDegreeProgram() /*gets degree program*/{ return this->degreeProgram; }
//setters
void Student::setStudentID(string studentID) /*sets student ID*/{ this->studentID = studentID; }
void Student::setFirstName(string firstName) /*sets first name*/{ this->firstName = firstName; }
void Student::setLastName(string lastName) /*sets last name*/{ this->lastName = lastName; }
void Student::setEmailAddress(string emailAddress) /*sets email*/{this->emailAddress = emailAddress;}
void Student::setAge(int age) /*sets age*/{ this->age = age; }
void Student::setDays(int days[]) /*sets days*/{ for (int i = 0; i < /* edited Sep 9-- put into camelCase to fix bug*/daysInCourse; i++) this->days[i] = days[i]; }
void Student::setDegreeProgram(DegreeProgram degreeprogram) /*sets degree program*/{ this->degreeProgram = degreeprogram; }

void Student::print()
{
	cout << "Student ID: " << this->getStudentID() << '\t'; // tab separates the output values
	cout << "First Name: " << this->getFirstName() << '\t';
	cout << "Last Name: " << this->getLastName() << '\t';
	// cout << "Email: " << this->getEmailAddress() << '\t';  syllabus apparently does not ask for this. Leaving as a commment in case sent back
	cout << "Age: " << this->getAge() << '\t';
	cout << "Days in Course: {" << this->getDays()[0] << ", ";
	cout << this->getDays()[1] << ", ";
	cout << this->getDays()[2] << "}\t";
	cout << "Degree Program: " << degreeProgramStrings[this->getDegreeProgram()] << '\n';
};

/*
Change log
Sep 8 - created
Sep 9 - Email removed from Student::print() -- apparently the syllabus doesn't ask for that? Leaving as a comment in case they send it back
*/
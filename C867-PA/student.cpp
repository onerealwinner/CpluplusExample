#include <string>
#include "student.h"
#include "degree.h"
using namespace std;

#pragma region "Constructor / Destructor"
//Create
Student::Student(string studentId, string firstName, string lastName, string eMail, int age, int* daysToComplete, DegreeProgram degreeProgram) {
	this->StudentId = studentId;
	this->FirstName = firstName;
	this->LastName = lastName;
	this->EmailAddress = eMail;
	this->Age = age;
	this->DaysToCompleteCourse[0] = daysToComplete[0];
	this->DaysToCompleteCourse[1] = daysToComplete[1];
	this->DaysToCompleteCourse[2] = daysToComplete[2];
	this->StudentDegreeProgram = degreeProgram;
}

//And Destroy
Student::~Student() {}

#pragma endregion

#pragma region "Methods"
//Prints a complete tab-separated list of student data 
void Student::print()
{
	// that prints a complete tab-separated list of student data in the provided format: 
	//A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security
	//email isn't included in the instructions so it is not included in the list
	std::cout 
	<< this->getStudentId() << "\t"
	<< "First Name: " + FirstName << "\t"
	<< "LastName: " + LastName << "\t"
	<< "Age: " + to_string(Age)  << "\t"
	<< "daysInCourse: {" + to_string(DaysToCompleteCourse[0]) + "," + to_string(DaysToCompleteCourse[1]) + "," + to_string(DaysToCompleteCourse[2]) << "} \t";

	switch (StudentDegreeProgram) {
	case DegreeProgram::SECURITY:
		cout << "Degree Program: Security";
		break;
	case DegreeProgram::SOFTWARE:
		cout << "Degree Program: Software";
		break;
	case DegreeProgram::NETWORK:
		cout << "Degree Program: Network";
		break;
	}
	cout << endl;
}

#pragma endregion

#pragma region "Property Mutators and Accessors"
//StudentId
string Student::getStudentId() { return this->StudentId; }
void Student::setStudentId(string sId) { this->StudentId = sId; }

//FirstName
string Student::getFirstName() { return this->FirstName; }
void Student::setFirstName(string fName) { this->FirstName = fName; }

//LastName
string Student::getLastName() { return this->LastName; }
void Student::setLastName(string lName) { this->LastName = lName;}

//Email Address
string Student::getEmailAddress() { return this->EmailAddress; }
void Student::setEmailAddress(string eMail) { this->EmailAddress = eMail; }

//Age
int Student::getAge() { return this->Age; }
void Student::setAge(int age) { this->Age = age; }

//DegreeProgram
DegreeProgram Student::getDegreeProgram() { return this->StudentDegreeProgram; }
void Student::setDegreeProgram(DegreeProgram dProgram) { this->StudentDegreeProgram = dProgram; }

//Days To complete
int* Student::getDaysToCompleteCourse() { return this->DaysToCompleteCourse; }
void Student::setDaysToCompleteCourse(int daysToComplete1, int daysToComplete2, int daysToComplete3) { 
	this->DaysToCompleteCourse[0] = daysToComplete1;
	this->DaysToCompleteCourse[1] = daysToComplete2;
	this->DaysToCompleteCourse[2] = daysToComplete3;
}

#pragma endregion

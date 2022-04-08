/*
WGU student project
By; Daniel Mudge
Student ID: 004124446
Program Mentor: Susannah Dobson

Created: 5/2/2021
*/
#pragma once

#include "degree.h"
#include <string>
#include <iostream>
using namespace std;

class Student
{

private:
#pragma region "Private Property Declarations"
	string StudentId;
	string FirstName;
	string LastName;
	string EmailAddress;
	int Age;
	DegreeProgram StudentDegreeProgram;
	int DaysToCompleteCourse[3];
#pragma endregion

public:
#pragma region "Property Mutators and Accessors"
	void setStudentId(string sId);
	string getStudentId();

	void setFirstName(string fName);
	string getFirstName();
	
	void setLastName(string lName);
	string getLastName();

	void setEmailAddress(string eMail);
	string getEmailAddress();

	void setAge(int age);
	int getAge();

	void setDegreeProgram(DegreeProgram dProgram);
	DegreeProgram getDegreeProgram();

	void setDaysToCompleteCourse(int daysToComplete1, int daysToComplete2, int daysToComplete3);
	int* getDaysToCompleteCourse();
#pragma endregion

#pragma region "Constructor and Destructor"
	Student(string studentId, string firstName, string lastName, string eMail, int age, int* daysToComplete, DegreeProgram degreeProgram);
	~Student();
#pragma endregion

#pragma region "Methods"
	void print();
#pragma endregion
};


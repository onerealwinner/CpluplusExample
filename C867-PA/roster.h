#include "student.h"
#include "degree.h"
#include <string>
using namespace std;

#pragma once
class Roster
{
private:
	//Array of pointers for the student data
	const int StudentsArrayLength = 5;
	Student* StudentsInRoster[5];

public:
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	Student* getStudentFromClassRosterArray(int i);

	Roster(); //construct
	~Roster();// and deconstruct
};


#include "roster.h"
#include "degree.h"
#include <string>
#include <iostream>
using namespace std;

Roster::Roster()
{
	for (int i = 0; i < StudentsArrayLength; i++) {
		StudentsInRoster[i] = nullptr;
	}
}

//Destruct
Roster::~Roster() {}

Student* Roster::getStudentFromClassRosterArray(int i)
{
	return StudentsInRoster[i];
}

//Add a student to the roster 
void Roster::add(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
{
	int days[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	//find an empty spot for the student
	for (int i = 0; i < StudentsArrayLength; i++) {
		if (StudentsInRoster[i] == nullptr) {
			//Create a student object and add to the class Roster
			StudentsInRoster[i] = new Student(studentId, firstName, lastName, emailAddress, age, days, degreeprogram);
			break; //exit for
		}
	}
}

//Remove a student from the roster
void Roster::remove(string studentID)
{
	bool isRemoved = 0; //flag to identify if we found a student

	//Remove student by studentId
	for (int i = 0; i < StudentsArrayLength; i++) {
		//check student exists and id matches
		if (StudentsInRoster[i] != nullptr && StudentsInRoster[i]->getStudentId() == studentID) {
			StudentsInRoster[i] = nullptr;
			isRemoved = 1;
			break; //No student has the same ID... leave this loop at once.
		}
	}

	if (isRemoved) {
		cout << "The Student with ID " + studentID + " has been removed from the roster" << endl;
	}
	else {
		cout << "Unable to find Student with ID " + studentID + " - no student removed from roster" << endl;
	}
}

//Print all the students in the roster
void Roster::printAll()
{
	for (int i = 0; i < StudentsArrayLength; i++) {
		if (StudentsInRoster[i] != nullptr) {
			StudentsInRoster[i]->print();
		}
	}
}

//Print the average days in course by student
void Roster::printAverageDaysInCourse(string studentID)
{
	bool isFound = 0;
	double avg = 0;

	for (int i = 0; i < StudentsArrayLength; i++) {
		//Since we can delete students lets ensure a value exists before we check the studentID
		if (StudentsInRoster[i] != nullptr && StudentsInRoster[i]->getStudentId() == studentID) {
			int* days = StudentsInRoster[i]->getDaysToCompleteCourse();
			avg = ((double)days[0] + (double)days[1] + (double)days[2]) / 3.0;
			isFound = 1;
			break;
		}
	}
	
	if (isFound) {
		cout << "Student with ID " + studentID + " average days is " + to_string((int)(avg)) << endl;
	}
	else {
		cout << "Unable to find Student with ID " + studentID + " - no student removed from roster" << endl;
	}
}

//that verifies student email addressesand displays all invalid email addresses to the user.
//Note: A valid email should include an at sign('@') and period('.') and should not include a space(' ').
void Roster::printInvalidEmails()
{
	for (int i = 0; i < StudentsArrayLength; i++) {
		//Since we can delete students lets ensure a value exists
		if (StudentsInRoster[i] != nullptr) {
			string emailErrors = "";
			string eMail = StudentsInRoster[i]->getEmailAddress();

			//Check @ 
			if (eMail.find("@") == std::string::npos) {
				emailErrors += "missing '@'";
			}

			//Check .
			if (eMail.find(".") == std::string::npos) {
				if (emailErrors.length() > 0) { emailErrors += ", "; }
				emailErrors += "missing '.'";
			}

			//Check space
			if (eMail.find(" ") != std::string::npos) {
				if (emailErrors.length() > 0) { emailErrors += ", "; }
				emailErrors += "contains a space";
			}

			if (emailErrors.length() > 0) {
				cout << "Student " << StudentsInRoster[i]->getStudentId() << " email [" << eMail << "] is invalid " << emailErrors << endl;
			}
		}
	}

}

// prints out student information for a degree program specified by an enumerated type.
void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	switch (degreeProgram) {
	case DegreeProgram::SECURITY:
		cout << "Students in Degree Program: SECURITY \n";
		break;
	case DegreeProgram::SOFTWARE:
		cout << "Students in Degree Program: SOFTWARE \n";
		break;
	case DegreeProgram::NETWORK:
		cout << "Students in Degree Program: NETWORK \n";
		break;
	}

	for (int i = 0; i < StudentsArrayLength; i++) {
		if (StudentsInRoster[i] != nullptr && StudentsInRoster[i]->getDegreeProgram() == degreeProgram) {
			StudentsInRoster[i]->print();
		}
	}
}
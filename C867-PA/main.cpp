// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "student.h"
#include "roster.h"
#include "degree.h"
#include <vector>
#include <sstream>

using namespace std;

int main()
{
	//Intro Message
	std::cout << "C867 - Scripting and Programming - Applications Class \n"
		<< "Student Roster Application in C++ \n"
		<< "By: Daniel Mudge - 5/3/2021 \n"
		<< "Student Id: 004124446 \n------------------\n" << endl;

	//Create instance of the roster class
	Roster* classRoster = new Roster();

	//Student Data
	const string studentData[] = { 
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY"
		,"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK"
		,"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE"
		,"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY"
		,"A5,Daniel,Mudge,dmudge1@wgu.edu,38,5,4,3,SOFTWARE"
	};

	//Add each student to the Roster Class
	for (int i = 0; i < 5; i++) {	
		string dataRow = studentData[i]; 
		vector<string> dataParts;
		stringstream myStream(dataRow);
		while (myStream.good()) {
			string dPart;
			getline(myStream, dPart, ',');
			dataParts.push_back(dPart);
		}

		//Set the degree program from the 8th data part
		DegreeProgram dp;
		if (dataParts[8] == "SECURITY") {
			dp = DegreeProgram::SECURITY;
		}
		if (dataParts[8] == "NETWORK") {
			dp = DegreeProgram::NETWORK;
		}
		if (dataParts[8] == "SOFTWARE") {
			dp = DegreeProgram::SOFTWARE;
		}

		//Add to Roster - 0 = studentid, 1= firstName, 2=lastName, 3=Email, 4=age, 5,6,7= days in class, 8=degree
		classRoster->add(dataParts[0], dataParts[1], dataParts[2], dataParts[3], stoi(dataParts[4]), stoi(dataParts[5]), stoi(dataParts[6]), stoi(dataParts[7]), dp);
	} //end for

	//
	cout << "Students List: \n";
	classRoster->printAll();
	cout << "\n";

	cout << "Students With Invalid Emails: \n";
	classRoster->printInvalidEmails();
	cout << "\n";

	cout << "Students Average Days In Course: \n";
	//loop through classRosterArray and for each element:
	for (int i = 0; i < 5; i++) {
		Student* s = classRoster->getStudentFromClassRosterArray(i);
		classRoster->printAverageDaysInCourse(s->getStudentId());
	}
	cout << "\n";

	//remove A3
	cout << "Remove Student 'A3' \n";
	classRoster->remove("A3");
	cout << "\n";

	//Print everything again
	cout << "Current Student List: \n";
	classRoster->printAll();
	cout << "\n";

	//Check error message
	cout << "Attempt To remove Student A3 again: \n";
	classRoster->remove("A3");
	cout << "\n";

	classRoster->~Roster(); //destruct

}

/**
//Test function
cout << "Students in SOFTWARE \n";
classRoster->printByDegreeProgram(DegreeProgram::SOFTWARE);
cout << "\n";

cout << "Students in SECURITY \n";
classRoster->printByDegreeProgram(DegreeProgram::SECURITY);
cout << "\n";

cout << "Students in NETWORK \n";
classRoster->printByDegreeProgram(DegreeProgram::NETWORK);
cout << "\n";
*/

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

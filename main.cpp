
#include "header\stdafx.h"

#include "header\degree.h"
#include "header\student.h"
#include "header\rooster.h"


#include <iostream>
#include <string>

#include <iomanip>
#include <cstring>

#include <sstream>

using namespace std;

// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 


// WGU STUDENT INFORMATION - START

// WGU STUDENT INFORMATION - END


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 

// Project Required Data:
	// Student Data Table Arrary Input FOR PRFA YMJ1

const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Danty,Cook,DCoo230@wgu.edu,34,77,42,60,SOFTWARE"
	};

// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 


int main() {

	// Student test[5];
	/*
	Student* test = new Student[5];
	Student* test2 = new Student[5];
	*/


	/*

	Rooster* r = new Rooster[5];

	*/	
    DegreeProgram degreeProgram = DegreeProgram::SECURITY;

	int cr;
	int classSize = 5;

	Rooster** classRooster = new Rooster * [classSize];

	for (cr = 0; cr < classSize; ++cr) {

		classRooster[cr] = new Rooster();

	}



	std::cout << "---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----" << endl;
	std::cout << "---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----" << endl;
	std::cout << "---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----" << endl << endl;

	string parseTestObj2;
	string parseTestObj2Temp;

	string myStream3;
	string variableParseArray2[9] = {};

	DegreeProgram __degreeProgram = DegreeProgram::NETWORK;
	int jyx = 0;

	for (int i = 0; i < 5; i++) {

		// Student Object Array

		// for (int j = 0; j < 5; j++) {

			// Student Data Input Array


		parseTestObj2 = studentData[i];
		stringstream myStream3(parseTestObj2);
		jyx = 0;

		while (getline(myStream3, parseTestObj2Temp, ',')) {
			//std::getline (parseTest2, parseTest2Temp, ",");

			variableParseArray2[jyx++] = parseTestObj2Temp;

			// std::cout << parseTestObj2Temp << endl;
		}

		/*
		std::cout << "---- TEMP variable Assignment ----" << endl;
		string __studentID = variableParseArray2[0];
		string __firstName = variableParseArray2[1];
		string __lastName = variableParseArray2[2];
		string __emailAddress = variableParseArray2[3];
		int __age = (stoi(variableParseArray2[4]));
		int __daysInCourse1 = (stoi(variableParseArray2[5]));
		int __daysInCourse2 = (stoi(variableParseArray2[6]));
		int __daysInCourse3 = (stoi(variableParseArray2[7]));
		*/

		/*
		func(DegreeProgram::NETWORK);
		*/


		/*
		std::cout << __studentID << endl;
		std::cout << __firstName << endl;
		std::cout << __lastName << endl;
		std::cout << __emailAddress << endl;
		std::cout << __age << endl;
		std::cout << __daysInCourse1 << endl;
		std::cout << __daysInCourse2 << endl;
		std::cout << __daysInCourse3 << endl;
		*/


		if (variableParseArray2[8] == "NETWORK") {
			std::cout << "Degree Program Is Network" << endl;
			__degreeProgram = DegreeProgram::NETWORK;
			__degreeProgram = DegreeProgram::NETWORK;
			__degreeProgram = DegreeProgram::NETWORK;
		}
		else if (variableParseArray2[8] == "SOFTWARE") {
			std::cout << "Degree Program Is Software" << endl;
			__degreeProgram = DegreeProgram::SOFTWARE;
		}
		else if (variableParseArray2[8] == "SECURITY") {
			std::cout << "Degree Program Is Security" << endl;
			__degreeProgram = DegreeProgram::SECURITY;
		}
		else
			std::cout << "Degree Program Not Matched" << endl;

		// std::cout << __degreeProgram;

		std::cout << endl << endl;



		//r->add2(variableParseArray2[0], variableParseArray2[1], variableParseArray2[2], variableParseArray2[3], (stoi(variableParseArray2[4])), (stoi(variableParseArray2[5])), (stoi(variableParseArray2[6])), (stoi(variableParseArray2[7])));
		//r[i].add2(__studentID, __firstName, __lastName, __emailAddress, __age, __daysInCourse1, __daysInCourse2, __daysInCourse3);
		//r[i].add2(variableParseArray2[0], variableParseArray2[1], variableParseArray2[2], variableParseArray2[3], (stoi(variableParseArray2[4])), (stoi(variableParseArray2[5])), (stoi(variableParseArray2[6])), (stoi(variableParseArray2[7])));
		// r[i].add3(variableParseArray2[0], variableParseArray2[1], variableParseArray2[2], variableParseArray2[3], (stoi(variableParseArray2[4])), (stoi(variableParseArray2[5])), (stoi(variableParseArray2[6])), (stoi(variableParseArray2[7])), (__degreeProgram));
		//classRooster[i]->add3(variableParseArray2[0], variableParseArray2[1], variableParseArray2[2], variableParseArray2[3], (stoi(variableParseArray2[4])), (stoi(variableParseArray2[5])), (stoi(variableParseArray2[6])), (stoi(variableParseArray2[7])), (__degreeProgram));



	}


	// r->printAll();


/*
std::cout << "---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----" << endl;
std::cout << "---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----" << endl;
std::cout << "---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----" << endl << endl;


std::cout << test2[3].getStudentID();

std::cout << endl;
*/

	std::cout << "---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----" << endl;
	std::cout << "---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----" << endl;
	std::cout << "---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----" << endl << endl;

	/*
		string studentIDTestMaster = "A2";

		for (int ixy = 0; ixy < 5; ixy++) {

			// std::cout << "Current Student ID: " << r[ixy].getStudentID() << endl;
			std::cout << "Current Student ID: " << classRooster[ixy]->getStudentID() << endl;

			// if (r[ixy].getStudentID() == "A5") {
			if (classRooster[ixy]->getStudentID() == "A5") {

				//r[ixy].printCustom();
				classRooster[ixy]->printCustom();
				break;
			}

			/// if (r[ixy].getStudentID() == studentIDTestMaster) {
			if (classRooster[ixy]->getStudentID() == studentIDTestMaster) {

				std::cout << "String Successfully Matched To Student ID" << endl;
				//r[ixy].printCustom();
				classRooster[ixy]->printCustom();
			};

			*/

			/*
			if (test2[ixy].getStudentID() == studentIDTestMaster) {
				//std::cout << test2[ixy].printCustom();
				//break;
			}

			std::cout << "Student ID Does Not Match Student Test2 Object " << ixy << endl;

		*/
		/*
		}
		*/


	std::cout << "---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----" << endl;
	std::cout << "---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----" << endl;
	std::cout << "---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----" << endl << endl;

	//for (int i = 0; i < 5; i++) {

		// std::cout << "Rooster Student Object #: " << i << "Is Located At: " << &r[i] << endl;
		//std::cout << "Rooster Student Object #: " << i << " Is Located At: " << &classRooster[i] << endl;

		// string temp = r[i].getStudentID();
		//string temp = classRooster[i]->getStudentID();

		//std::cout << "\t" << "Rooster Student Object #: " << i << "'s Data Member - Student ID, value is " << temp << " And Is Located At : " << &temp << endl;

	//}

	//std::cout << endl;

	std::cout << "---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----" << endl;
	std::cout << "---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----" << endl;
	std::cout << "---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----" << endl << endl;

	std::cout << "Print All Test" << endl << endl;

	// r->printAll();

	//classRooster[this]->printAll();
	//classRooster->printAll();

	// classRooster->printAllStudent();

	std::cout << "---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----" << endl;
	std::cout << "---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----" << endl;
	std::cout << "---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----" << endl << endl;

	std::cout << "Prints Each Student Object on a loop";


	for (int i = 0; i < 5; i++) {

		//classRooster[i]->printCustom();
	}
	for (int i = 0; i < 5; i++) {

		//classRooster[i]->print();
	}


	std::cout << "---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----" << endl;
	std::cout << "---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----" << endl;
	std::cout << "---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----" << endl << endl;

	/*
	delete[] test;
	delete[] test2;
	*/

	// delete[] r;
	


	for (int i = 0; i < 5; ++i) {
	
		delete classRooster[i];
		classRooster[i] = nullptr;
	}

	delete[] classRooster;






	return 0;


}
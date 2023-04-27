
#include "stdafx.h"

#include "degree.h"
#include "student.h"

#include <iostream>
#include <string>

#include <iomanip>
#include <cstring>

#include <sstream>

	using namespace std;







// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 

// Classes

	// Enumerated Data Class

	enum class DegreeProgram {
		NETWORK = 0,
		SOFTWARE,
		SECURITY

	};

	/*
		DegreeProgram convertStringToEnum(string _degreeProgram)
	{

		if (_degreeProgram == "NETWORK") return NETWORK;
		else if (_degreeProgram == "SECURITY") return SECURITY;
		else return SOFTWARE;
	}

	*/

	// Student Class 

	class Student {

		private:

			string studentID = "";
			string firstName = "";
			string lastName;
			string emailAddress;

			int age = 0;

			int daysInCourse1 = 0;
			int daysInCourse2 = 0;
			int daysInCourse3 = 0;

			int daysInCourse[3] = { 0,0,0 };

			double AverageDaysInCourse = 0.00;

			DegreeProgram degreeProgram = DegreeProgram::SECURITY;
			int degreeProgramInt = 0;

			string arrayInputData;


		public:

			// Mutators

			string a;

			void setStudentID(string _studentID) {
				studentID = _studentID;
			}

			void setStudentFirstName(string _firstName) {
				firstName = _firstName;
			}

			void setStudentLastName(string _lastName) {
				lastName = _lastName;
			}

			void setStudentEmailAddress(string _emailAddress) {
				emailAddress = _emailAddress;
			}

			void setStudentAge(int _age) {
				age = _age;
			}

			void setStudentDaysInCourse1(int _daysInCourse1) {
				daysInCourse1 = _daysInCourse1;
			}

			void setStudentDaysInCourse2(int _daysInCourse2) {
				daysInCourse2 = _daysInCourse2;
			}

			void setStudentDaysInCourse3(int _daysInCourse3) {
				daysInCourse3 = _daysInCourse3;
			}

			void setStudentDegreeProgram(DegreeProgram _degreeProgram) {
				degreeProgram = _degreeProgram;
			}


			void setArrayInputData(string _arrayInputData) {
				arrayInputData = _arrayInputData;

			}

			// Accessors

			string getStudentID() {
				return studentID;
			}

			string getStudentFirstName() {
				return firstName;
			}

			string getStudentLastName() {
				return lastName;
			}

			string getStudentEmailAddress() {
				return emailAddress;
			}

			int getStudentAge() {
				return age;
			}

			string getArrayInputData() {
				return arrayInputData;
			}

			int* getDaysInCourse() {
				return daysInCourse;
			}

			DegreeProgram getStudentDegreeProgram() {
				return degreeProgram;
			}


			// Constructor

				// Default Constructor
			Student() {
			}

				// Parameterized Constructor

			Student(string arrayInputData) {
				this->arrayInputData;
			
			}

			// Parameterized Constructor
			Student(string studentID,
				string firstName,
				string lastName,
				string emailAddress,
				int age,
				int daysInCourse1,
				int daysInCourse2,
				int daysInCourse3,
				/*int _daysInCourse[], */
				DegreeProgram degreeProgram
			) {


				this->studentID = studentID;
				this->firstName = firstName;
				this->lastName = lastName;
				this->emailAddress = emailAddress;
				this->age = age;
				this->daysInCourse1 = daysInCourse1;
				this->daysInCourse2 = daysInCourse2;
				this->daysInCourse3 = daysInCourse3;
				this->degreeProgram = degreeProgram;

				this->degreeProgramInt = static_cast<int>(degreeProgram);
				//DegreeProgram degreeProgramIntToEnum = static_cast<DegreeProgram>(degreeProgramInt);

				/*
				studentID = _studentID;
				firstName = _firstName;
				lastName = _lastName;
				emailAddress = _emailAddress;
				age = _age;
				daysInCourse1 = _daysInCourse1;
				daysInCourse2 = _daysInCourse2;
				daysInCourse3 = _daysInCourse3;
				//daysInCourse[] = _daysInCourse[];
				*/

			}


			// Member Functions

				// Member Function: 
				// Add Int daysInCourse(x) to daysInCourse Array

				//int addDaysToArray(int _daysInCourse1, int _daysInCourse2, int _daysInCourse3) {
			void addDaysToArray() {

				int _daysInCourse1 = daysInCourse1;
				int _daysInCourse2 = daysInCourse2;
				int _daysInCourse3 = daysInCourse3;

				daysInCourse[0] = _daysInCourse1;
				daysInCourse[1] = _daysInCourse2;
				daysInCourse[2] = _daysInCourse3;

				//return daysInCourse[];
			}

			// Member Function:
			// Calculate Average Days In Courses

			double getAverageDaysInCourse() {

				int size = 3;
				int sum = 0;

				for (int i = 0; i < size; ++i) {

					sum += daysInCourse[i];

				}

				AverageDaysInCourse = double(sum) / size;

				return AverageDaysInCourse;

			}

			// Member Function:
			// Prints All Data For Student:

			void printCustom() {


				std::cout << "---- ---- ---- ---- ---- ---- ---- ----" << endl;
				std::cout << "---- ---- --Student Details-- ---- ----" << endl;
				std::cout << "---- ---- ---- ---- ---- ---- ---- ----" << endl << endl;
				std::cout << "Student ID: " << studentID << endl;
				std::cout << "Student Name: " << lastName << ", " << firstName << endl;
				std::cout << "Studnet Email: " << emailAddress << endl;
				std::cout << "Student Age: " << age << endl;

				std::cout << "Number of Days In Course 1: " << daysInCourse1 << endl;
				std::cout << "Number of Days In Course 2: " << daysInCourse2 << endl;
				std::cout << "Number of Days In Course 3: " << daysInCourse3 << endl;

				std::cout << "Number Of Days In Course Array: ";
				cout << "{";
					for (int i = 0; i < 3; i++) {
						if (i != 2) {
							std::cout << daysInCourse[i] << ", ";
						}
						else {
							std::cout << daysInCourse[i] << "}" << endl;
						}
				}

				std::cout << "Average Number Of days In Courses: " << fixed << setprecision(2) << AverageDaysInCourse << endl;

				//std::cout << "Number of Days In Course Array: " << daysInCourse << endl; 


				//std::cout << "Average Days in Courses: " << AverageDaysInCourse << endl;



				std::cout << "Student's Degree Program (Int): " << degreeProgramInt << endl;

				std::cout << "Degree Program: ";

				if (degreeProgram == DegreeProgram::NETWORK) {
					cout << "NETWORK";
				}
				else if (degreeProgram == DegreeProgram::SOFTWARE) {
					cout << "SOFTWARE";
				}
				else if (degreeProgram == DegreeProgram::SECURITY) {
					cout << "SECURITY";
				}
				else {
					cout << "ERROR";
				}

				std::cout << endl;

				std::cout << "Print is from student object" << endl << endl;

				//std::cout << "Student's Degree Program (String): " << degreeProgramIntToEnum << endl;

				std::cout << "---- ---- ---- ---- ---- ---- ---- ----" << endl << endl;






			}
			
			void print() {


				std::cout << "---- ---- ---- ---- ---- ---- ---- ----" << endl;
				std::cout << "---- ---- --Student Details-- ---- ----" << endl;
				std::cout << "---- ---- ---- ---- ---- ---- ---- ----" << endl << endl;

				std::cout << this->getStudentID() << "\t";
				std::cout << "First Name: " << getStudentFirstName() << "\t"; 
				std::cout << "Last Name: " << this->getStudentLastName() << "\t";
				std::cout << "Age: " << this->getStudentAge() << "\t";
				std::cout << "daysInCourse: "; 
				cout << "{";
				for (int i = 0; i < 3; i++) {
					if (i != 2) {
						std::cout << this->daysInCourse[i] << ", ";
					}
					else {
						std::cout << this->daysInCourse[i] << "} ";
					}
				}
				std::cout << "DegreeProgram: ";

				if (degreeProgram == DegreeProgram::NETWORK) {
					cout << "NETWORK";
				}
				else if (degreeProgram == DegreeProgram::SOFTWARE) {
					cout << "SOFTWARE";
				}
				else if (degreeProgram == DegreeProgram::SECURITY) {
					cout << "SECURITY";
				}
				else {
					cout << "ERROR";
				}

				std::cout << endl;


			}

		

			void printArrayInputData() {

				std::cout << arrayInputData << endl << endl;
			}
	};

		// End Of Student Class

		///*

		// Rooster Class


	class Rooster: public Student{

		private:
				
			//Student objStudent[5];
			

			//enum DegreeProgram degreeProgram;

	
		public:
			/*
			int i, jyx;
			string parseInputData;
			string parseInputData = studentData[i];
			*/

			int* getDaysInCourseArray(Student daysInCourseArray) {
				return daysInCourseArray.getDaysInCourse();
			}




			Rooster() {
				
				/*
				parseInputData = studentData[i];
				stringstream inputStream(parseInputData);;
				jyx = 0;

				while (getline(inputStream, parseInputData, ',')) {
					//std::getline (parseTest2, parseTest2Temp, ",");

					variableParseArray2[jyx++] = parseInputData;

					// cout << parseTestObjTemp << endl;
				}

				*/



			}


			void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
				
				this->setStudentID(studentID);
				this->setStudentFirstName(firstName);
				this->setStudentLastName(lastName);
				this->setStudentEmailAddress(emailAddress);
				this->setStudentAge(age);

				this->setStudentDaysInCourse1(daysInCourse1);
				this->setStudentDaysInCourse2(daysInCourse2);
				this->setStudentDaysInCourse3(daysInCourse3);

				this->addDaysToArray();
				this->getAverageDaysInCourse();





				/*
				if (variableParseArray2[8] == "NETWORK") {
					this->setStudentDegreeProgram(DegreeProgram::NETWORK);
				}
				else if (variableParseArray2[8] == "SECRUITY") {
					this->setStudentDegreeProgram(DegreeProgram::SECURITY);
				}
				else {
					this->setStudentDegreeProgram(DegreeProgram::SOFTWARE);
				}

				*/

			}

			
			void add2(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3) {

				this->setStudentID(studentID);
				this->setStudentFirstName(firstName);
				this->setStudentLastName(lastName);
				this->setStudentEmailAddress(emailAddress);
				this->setStudentAge(age);

				this->setStudentDaysInCourse1(daysInCourse1);
				this->setStudentDaysInCourse2(daysInCourse2);
				this->setStudentDaysInCourse3(daysInCourse3);

				this->addDaysToArray();
				this->getAverageDaysInCourse();

				/*
				if (variableParseArray2[8] == "NETWORK") {
					this->setStudentDegreeProgram(DegreeProgram::NETWORK);
				}
				else if (variableParseArray2[8] == "SECRUITY") {
					this->setStudentDegreeProgram(DegreeProgram::SECURITY);
				}
				else {
					this->setStudentDegreeProgram(DegreeProgram::SOFTWARE);
				}
				
				*/
				
				cout << endl;
				cout << studentID << endl;
				cout << firstName << endl;
				cout << lastName << endl;
				cout << emailAddress << endl;
				cout << age << endl;
				cout << daysInCourse1 << endl;
				cout << daysInCourse2 << endl;
				cout << daysInCourse3 << endl;
				cout << getAverageDaysInCourse();
				cout << endl;


			}


			void add3(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {

				this->setStudentID(studentID);
				this->setStudentFirstName(firstName);
				this->setStudentLastName(lastName);
				this->setStudentEmailAddress(emailAddress);
				this->setStudentAge(age);

				this->setStudentDaysInCourse1(daysInCourse1);
				this->setStudentDaysInCourse2(daysInCourse2);
				this->setStudentDaysInCourse3(daysInCourse3);

				this->addDaysToArray();
				this->getAverageDaysInCourse();
				this->setStudentDegreeProgram(degreeProgram);

				/*
				if (variableParseArray2[8] == "NETWORK") {
					this->setStudentDegreeProgram(DegreeProgram::NETWORK);
				}
				else if (variableParseArray2[8] == "SECRUITY") {
					this->setStudentDegreeProgram(DegreeProgram::SECURITY);
				}
				else {
					this->setStudentDegreeProgram(DegreeProgram::SOFTWARE);
				}

				*/
				cout << endl;
				cout << studentID << endl;
				cout << firstName << endl;
				cout << lastName << endl;
				cout << emailAddress << endl;
				cout << age << endl;
				cout << daysInCourse1 << endl;
				cout << daysInCourse2 << endl;
				cout << daysInCourse3 << endl;
				cout << getAverageDaysInCourse() << endl;
				
				if (degreeProgram == DegreeProgram::NETWORK) {
					cout << "NETWORK";
				}
				else if (degreeProgram == DegreeProgram::SOFTWARE) {
					cout << "SOFTWARE";
				}
				else if (degreeProgram == DegreeProgram::SECURITY) {
					cout << "SECURITY";
				}
				else {
					cout << "ERROR";
				}

				cout << endl;
			}


			
			void remove(string studentId) {
				


				bool isFound = false;
				int i = 0;

				for (int i = 0; i < 5; i++) {

					if (this[i].getStudentID() == studentId) {

						isFound = true;
						cout << "Student Object Was Located In Array Position: " << i << endl << endl;
						break;
					}

					cout << "Student Object Was NOT In Array Position: " << i << endl << endl;

				}
			}




			void printAllStudents() {

				for (int i = 0; i < 5; i++) {

					this[i].print();
					/*
					std::cout << "---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----" << endl;
					std::cout << "---- ---- --Student Details-- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----" << endl;
					std::cout << "---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----" << endl << endl;
					
					std::cout << this[i].getStudentID() << "\t";
					std::cout << "First Name: " << this[i].getStudentFirstName() << "\t";
					std::cout << "Last Name: " << this[i].getStudentLastName() << "\t";
					std::cout << "Age: " << this[i].getStudentAge() << "\t";
					
					std::cout << "daysInCourse: {";
					for (int i = 0; i < 3; i++) {
						if (i != 2) {
							std::cout << this[i].getDaysInCourseArray(this[i])[i] << ", ";
						}
						else {
							std::cout << this[i].getDaysInCourseArray(this[i])[i];
						}
					}
					std::cout << "} ";

					std::cout << "Degree Program: ";
						
					if (this[i].getStudentDegreeProgram() == DegreeProgram::NETWORK) {
						cout << "NETWORK";
					}
					else if (this[i].getStudentDegreeProgram() == DegreeProgram::SOFTWARE) {
						cout << "SOFTWARE";
					}
					else if (this[i].getStudentDegreeProgram() == DegreeProgram::SECURITY) {
						cout << "SECURITY";
					}
					else {
						cout << "ERROR";
					}


					std::cout << endl;
					std::cout << "---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----" << endl;
					std::cout << "---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----" << endl;
					std::cout << "---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----" << endl << endl;
					*/



				}


			}
				
			void printAverageDaysInCourse(string studentID) {
				
			}
				
			void printInvalidEmails() {
				
				
				
			}

			void printByDegreeProgram(DegreeProgram degreeProgram) {
				
				
			}

	};

		// END Of The Rooster Class
			


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

	*/	DegreeProgram degreeProgram = DegreeProgram::SECURITY;

	int cr;
	int classSize = 5;

	Rooster** classRooster = new Rooster * [classSize];

	for (cr = 0; cr < classSize; ++cr) {

		classRooster[cr] = new Rooster();

	}




	/*
	Student s("A1", "Danty", "Cook", "DCoo230@WGU.edu", 34, 22, 47, 59, DegreeProgram::SOFTWARE);
	s.addDaysToArray();
	s.getAverageDaysInCourse();
	s.printCustom();

	*/


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
		classRooster[i]->add3(variableParseArray2[0], variableParseArray2[1], variableParseArray2[2], variableParseArray2[3], (stoi(variableParseArray2[4])), (stoi(variableParseArray2[5])), (stoi(variableParseArray2[6])), (stoi(variableParseArray2[7])), (__degreeProgram));



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

	//std::cout << r[1].getStudentID();

	classRooster[2]->print();

	std::cout << endl << endl;


	std::cout << "---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----" << endl;
	std::cout << "---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----" << endl;
	std::cout << "---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----" << endl << endl;

	//r->remove("A4");

// classRooster->remove("A4");





	std::cout << "---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----" << endl;
	std::cout << "---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----" << endl;
	std::cout << "---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----" << endl << endl;


	for (int i = 0; i < 5; i++) {

		// std::cout << "Rooster Student Object #: " << i << "Is Located At: " << &r[i] << endl;
		std::cout << "Rooster Student Object #: " << i << " Is Located At: " << &classRooster[i] << endl;

		// string temp = r[i].getStudentID();
		string temp = classRooster[i]->getStudentID();

		std::cout << "\t" << "Rooster Student Object #: " << i << "'s Data Member - Student ID, value is " << temp << " And Is Located At : " << &temp << endl;

	}

	std::cout << endl;

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

		classRooster[i]->printCustom();
	}
	for (int i = 0; i < 5; i++) {

		classRooster[i]->print();
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
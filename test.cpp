#include <iostream>
#include <string>

using namespace std;


class Student {

	private:

		string studentID;
		string firstName; 
		string lastName;
		string emailAddress;

		int age;
		
		int daysInCourse1;
		int daysInCourse2;
		int daysInCourse3;

		int daysInCourse[3]; 

		enum DegreeProgram { SECURITY, NETWORK, SOFTWARE } degreeProgram;

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

		// Accessors

		void getStudentID() {
			return studentID;
		}

		void getStudentFirstName() {
			return firstName;
		}

		void getStudentLastName() {
			return lastName;
		}

		void getStudentEmailAddress() {
			return emailAddress;
		}
}
		void getStudentAge() {
			return age;
		}

		// Constructor

		Student() {
			cout << "Enter Student Details" << endl;
			cout << "Student ID: ";
			cin >> a;
			studentID = a;
			cout << Student ID;
		
		}
		// Member Function 

};

int main() {

	Student s;



	return 0;


}
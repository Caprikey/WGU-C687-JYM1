#include "..\header\student.h"
#include "..\header\degree.h"

#include <iomanip> 

using namespace std;


// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 

// CONSTRUCTORS - START
//

    //DEFAULT CONSTRUCTOR
    Student::Student() {};

    // Constructor - Requirement D, Number 2, Part d
    Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram) {

        this->studentID = studentID;
        this->firstName = firstName;
        this->lastName = lastName;
        this->emailAddress = emailAddress;
        this->age = age;

        this->daysInCourse[0] = daysInCourse[0];
        this->daysInCourse[1] = daysInCourse[1];
        this->daysInCourse[2] = daysInCourse[2];

        this->degreeProgram = degreeProgram;
    };


// CONSTRUCTORS - END
//
// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
// 
// DECONSTRUCTORS - START
//

    Student::~Student() {
    
    };


// DECONSTRUCTORS - END
// 
// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
//
// MUTATORS - START

    void Student::setStudentID(string studentID) {
        this->studentID = studentID;
    }

    void Student::setStudentFirstName(string firstName) {
        this->firstName = firstName;
    }

    void Student::setStudentLastName(string lastName) {
        this->lastName = lastName;
    }

    void Student::setStudentEmailAddress(string emailAddress) {
        this->emailAddress = emailAddress;
    }

    void Student::setStudentAge(int age) {
        this->age = age;
    }

    void Student::setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3) {
        this->daysInCourse[0] = daysInCourse1;
        this->daysInCourse[1] = daysInCourse2;
        this->daysInCourse[2] = daysInCourse3;
    }

    void Student::setDaysInCourse(int daysInCourse[]) {
        this->daysInCourse[0] = daysInCourse[0];
        this->daysInCourse[1] = daysInCourse[1];
        this->daysInCourse[2] = daysInCourse[2];
    }

    void Student::setStudentDegreeProgram(DegreeProgram degreeProgram) {
        this->degreeProgram = degreeProgram;
    }


// MUTATORS - END
//
// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
//
// ACCESSORS - START

    string Student::getStudentID() {
        return studentID;
    }

    string Student::getStudentFirstName() {
        return firstName;
    }

    string Student::getStudentLastName() {
        return lastName;
    }

    string Student::getStudentEmailAddress() {
        return emailAddress;
    }

    int Student::getStudentAge() {
        return age;
    }

    int* Student::getStudentDaysInCourse() {
        return daysInCourse;
    }

    DegreeProgram Student::getStudentDegreeProgram() {
        return degreeProgram;
    }

// ACCESSORS - END
//
// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
//
// MEMBER FUNCTIONS - START

    void Student::print() {
        cout << this->getStudentID() << "\t";
        cout << "First Name: " << this->getStudentFirstName() << "\t";
        cout << "Last Name: " << this->getStudentLastName() << "\t";
        cout << "Age: " << this->getStudentAge() << "\t";
        cout << "daysInCourse: ";

        cout << "{";

        for (int i = 0; i < 3; i++) {
            if (i != 2) {
                cout << this->daysInCourse[i] << ", ";
            }
            else {
                cout << this->daysInCourse[i];
            }
        }
        cout << "} ";

        cout << setw(28) << "Degree Program: ";

        if (this->degreeProgram == DegreeProgram::NETWORK) {
            cout << "NETWORK";
        }
        else if (this->degreeProgram == DegreeProgram::SOFTWARE) {
            cout << "SOFTWARE";
        }
        else if (this->degreeProgram == DegreeProgram::SECURITY) {
            cout << "SECURITY";
        }
        else {
            cout << "ERROR -- DEBUG NEEDED";
        }

        std::cout << endl;
    }


// MEMBER FUNCTIONS - END
//
// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 




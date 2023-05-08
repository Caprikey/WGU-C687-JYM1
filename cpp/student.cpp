// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
// 
// STUDENT CLASS - START
//
// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
//
// LIBRARY - START
// 

#include "..\header\student.h"
#include "..\header\degree.h"

#include <iomanip>
#include <iostream>

//
// LIBRARY - END
//
// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
//
// NAMESPACES - START
//

using namespace std;

//
// NAMESPACES - END
//
// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
//
// PUBLIC DATA MEMBERS - START
//


// PUBLIC DATA MEMBERS - END
//
// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
//
// CONSTRUCTORS - START
//

    //DEFAULT CONSTRUCTOR
    Student::Student() {};

    // Parameterized Constructor - Requirement D, Number 2, Part d
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
// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
// 
// DECONSTRUCTORS - START
//
    // Default Deconstructor
    Student::~Student() {
    
    };


// DECONSTRUCTORS - END
//
// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
//
// MUTATORS - START

    // Student Object Data Member Mutator - Student's StudentID - Set's The StudentID String Value
    void Student::setStudentID(string studentID) {
        this->studentID = studentID;
    }

    // Student Object Data Member Mutator - Student's First Name - Set's The Student's First Name String Value
    void Student::setStudentFirstName(string firstName) {
        this->firstName = firstName;
    }

    // Student Object Data Member Mutator - Student's Last Name - Set's The Student's Last Name String Value
    void Student::setStudentLastName(string lastName) {
        this->lastName = lastName;
    }

    // Student Object Data Member Mutator - Student's Email Address - Set's The Student's Email Address String Value
    void Student::setStudentEmailAddress(string emailAddress) {
        this->emailAddress = emailAddress;
    }

    // Student Object Data Member Mutator - Student's Age - Set's The Student's Age String Value
    void Student::setStudentAge(int age) {
        this->age = age;
    }

    // Student Object Data Member Mutator - daysInCourse Array - Manually Sets Each Index Value Of The daysInCourse Array By Passing Three Individual Ints To The Three Indexes 
    void Student::setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3) {
        this->daysInCourse[0] = daysInCourse1;
        this->daysInCourse[1] = daysInCourse2;
        this->daysInCourse[2] = daysInCourse3;
    }

    // Student Object Data Member Mutator - daysInCourse Array - Sets Each Index Value Of The daysInCourse Array By Matching An Input Array
    void Student::setDaysInCourse(int daysInCourse[]) {
        this->daysInCourse[0] = daysInCourse[0];
        this->daysInCourse[1] = daysInCourse[1];
        this->daysInCourse[2] = daysInCourse[2];
    }

    // Student Object Data Member Mutator - Enumerated DegreeProgram - Sets The Student's degreeProgram Enumerated Value
    void Student::setStudentDegreeProgram(DegreeProgram degreeProgram) {
        this->degreeProgram = degreeProgram;
    }


// MUTATORS - END
//
// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
//
// ACCESSORS - START

    // Student Object Data Member Accessor - Student's StudentID - Returns String
    string Student::getStudentID() {
        return studentID;
    }

    // Student Object Data Member Accessor - Student's First Name - Returns String
    string Student::getStudentFirstName() {
        return firstName;
    }

    // Student Object Data Member Accessor - Student's Last Name - Returns String
    string Student::getStudentLastName() {
        return lastName;
    }

    // Student Object Data Member Accessor - Student's Email Address - Returns String
    string Student::getStudentEmailAddress() {
        return emailAddress;
    }
    
    // Student Object Data Member Accessor - Student's Age - Returns Int
    int Student::getStudentAge() {
        return age;
    }

    // Student Object Data Member Accessor - daysInCourse Array - Returns Int Pointer
    int* Student::getStudentDaysInCourse() {
        return daysInCourse;
    }

    // Student Object Data Member Accessor - Enumerated DegreeProgram - Returns degreeProgram Enumerated Value
    DegreeProgram Student::getStudentDegreeProgram() {
        return degreeProgram;
    }

// ACCESSORS - END
//
// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
//
// MEMBER FUNCTIONS - START

    // Student print() Function -- Prints Student's Details In The Tabbulated Format. 
    void Student::print() {

        // Standard Output
        //cout << this->getStudentID() << "\t";

        // Stylized Output
        cout.width(8);
        cout << left << this->getStudentID() << "\t";

        // Standard Output
        // cout << "First Name: ";
        // cout << this->getStudentFirstName();
        
        // Stylized Output 
        cout << "First Name: ";
        
        cout.width(5);
        cout << left << this->getStudentFirstName();
        cout << "\t";

        // Standard Output
        // cout << "Last Name: ";
        // cout << this->getStudentLastName();
        
        // Stylized Output
        cout << "Last Name: ";

        cout.width(8);
        cout << left << this->getStudentLastName();

        cout << "\t";

        // Standard Output
        //cout << "Age: ";
        //cout << this->getStudentAge();

        // Stylized Output
        cout << "Age: ";
        cout.width(2);
        cout << left << this->getStudentAge();

        cout << "\t";

        // Standard Output
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

        // Standard Output
        // cout << "Degree Program: ";
        
        // Stylized Output
        cout << "Degree Program: ";
        cout.width(8);
        

        if (this->degreeProgram == DegreeProgram::NETWORK) {
            // Standard Output
            //cout << "NETWORK";

            // Stylized Output
            cout << left << "NETWORK";
        }
        else if (this->degreeProgram == DegreeProgram::SOFTWARE) {
            // Standard Output
            //cout << "SOFTWARE";

            // Stylized Output
            cout << left << "SOFTWARE";
        }
        else if (this->degreeProgram == DegreeProgram::SECURITY) {
            // Standard Output
            //cout << "SECURITY";

            // Stylized Output
            cout << left << "SECURITY";
        }
        else {
            cout << "ERROR -- DEBUG NEEDED";
        }

        std::cout << endl;
    }



// MEMBER FUNCTIONS - END
//
// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
//
// STUDENT CLASS - END
// 
// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 

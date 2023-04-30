#include "..\header\roster.h"
#include <iostream>
#include <iomanip> 

using namespace std;

// Roster Class

//
// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
//
// CONSTRUCTORS - START 

// Constructor With Debug Comments

Roster::Roster() {
    cout << "Constructor Successfully Started" << endl;
    cout << endl;

    classRosterArray = new Student*[numStudents];
    cout << "\t";
    cout << "classRosterArray variable was created successfully and " << numStudents << " Student Pointers were created" << endl;

    cout << endl;
    cout << "\t";
    cout << "Constructor Pointer NullPtr Assignment Loop Starting" << endl;
    for (int i = 0; i < numStudents; i++) {

        //classRosterArray[i] = new Student();
        classRosterArray[i] = nullptr;
        cout << "\t\t";
        cout << "classRosterArray[" << i << "] was successfully assigned as nullptr" << endl;
    }
    cout << "\t";
    cout << "Constructor Pointer NullPtr Assignment Loop Completed" << endl;
    cout << endl;

    cout << "\t";
    cout << "Constructor Pointer Assignment To New Object Loop Started" << endl;
    cout << endl;
    for (int i = 0; i < numStudents; i++) {
        
        classRosterArray[i] = new Student();
        cout << "\t\t";
        cout << "classRosterArray[" << i << "] was successfully assigned the address of the newly created Student Object" << endl;
        cout << "\t\t\t";
        cout << "Located at " << &classRosterArray[i] << endl;
    }
    cout << "\t";
    cout << "Constructor Pointer Assignment To New Object Loop Completed" << endl;
    cout << endl;
    cout << endl;

    cout << "Constructor Successfully Completed" << endl;

};

/*

// Constructor Without Debug Comments
 
Roster::Roster() {

    classRosterArray = new Student * [numStudents];

    for (int i = 0; i < numStudents; i++) {
        classRosterArray[i] = nullptr;
    }

    for (int i = 0; i < numStudents; i++) {
        classRosterArray[i] = new Student();
    }

};

*/

// CONSTRUCTORS - END
//
// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
//
// DECONSTRUCTORS - START 


// Deconstructor With Debug Comments

Roster::~Roster() {
    cout << "Deconstructor Successfully Started" << endl;
    cout << endl;

    cout << "\t";
    cout << "Array Of Pointer Object Deletion And Reference Assignment Loop Successfully Started" << endl;
    for (int i = 0; i < numStudents; i++) {
        if (classRosterArray[i] != nullptr) {
            delete classRosterArray[i];
            cout << "\t\t";
            cout << "Array Of Pointers Element Object Was Deleted" << endl;

            classRosterArray[i] = nullptr;
            cout << "\t\t";
            cout << "Array Of Pointers Element Was Set To NullPtr" << endl;
        }

    }

    cout << "\t";
    cout << "Array Of Pointer Object Deletion And Reference Assignment Loop Successfully Completed" << endl;

    cout << endl;


    delete[] classRosterArray;
    cout << "\t";
    cout << "Array Of Pointers Entity Was Deleted Successfully" << endl;

    cout << endl;

    cout << "Deconstructor Successfully Completed" << endl;
};


/*

// Deconstructor Without Debug Comments

Roster::~Roster() {

    for (int i = 0; i < numStudents; i++) {
        
        if (classRosterArray[i] != nullptr) {
            
            delete classRosterArray[i];

            classRosterArray[i] = nullptr;

        }

    }

    delete[] classRosterArray;

};
*/

// DECONSTRUCTORS - END
//
// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
// 
// MEMBER FUNCTIONS - START

// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 

// Add Function With All Required Parameters
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {



};

// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 

// Add Function With All But Enumerated Data Type Parameters
void Roster::add2(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3) {


};

// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 

void Roster::remove(string studentID) {



};

// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 


void Roster::printAll() {
            
    for (int i = 0; i < numStudents; i++) {
            
        if (classRosterArray[i] != nullptr) {
            
            classRosterArray[i]->print();
            
        }

    }
    
};

// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 


void Roster::printAverageDaysInCourse(string studentID) {
    int sum = 0;

    for (int i = 0; i < numStudents; i++) {

        if (classRosterArray[i] != nullptr) {

            if (classRosterArray[i]->getStudentID() == studentID) {

                cout << "FOUND" << endl;
                cout << i << endl;
                cout << classRosterArray[i]->getStudentDaysInCourse();
                cout << endl;
                cout << "days In Course: {";
                for (int j = 0; j < 3; j++) {
                    if (j != 2) {
                        cout << classRosterArray[i]->getStudentDaysInCourse()[j];

                        cout << ", ";
                    }
                    else {
                        cout << classRosterArray[i]->getStudentDaysInCourse()[j];
                    }
                    sum += classRosterArray[i]->getStudentDaysInCourse()[j];

                }

                cout << "}";
                cout << endl;
                cout << "Sum Of Array Items: " << sum << endl;
                cout << endl;
                double avg = (sum / 3.0);
                cout << "Average Days In Courses: " << fixed << setprecision(2) << avg << endl;
            }

        }

    }


};


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 

void Roster::printInvalidEmails() {



};

// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {

    for (int i = 0; i < numStudents; i++) {
    
        if (classRosterArray[i] != nullptr) {

            if (classRosterArray[i]->getStudentDegreeProgram() == degreeProgram) {
        
                classRosterArray[i]->print();
                continue;

            }
        
        }

    }

};

// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 

Student* Roster::getStudent(int i) {
    /*
    for (int i = 0; i < numStudents; i++) {
        if (this->classRosterArray[i]->getStudentID() == i) {
            return classRosterArray[i]
        }
    }
    return nullptr;
    */
    return classRosterArray[i];
}




// MEMBER FUNCTIONS - END
//
// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 

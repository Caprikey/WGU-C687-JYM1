#include "..\header\roster.h"
#include <iostream>
#include <iomanip> 

using namespace std;

// Roster Class

//
// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
//
// CONSTRUCTORS - START 

// TODO: DELTE FROM FINAL -- USED FOR TESTING
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
// TODO: Uncomment From Final
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

// TODO: DELTE FROM FINAL -- USED FOR TESTING
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
// TODO: Uncomment From Final
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

// TODO: Completed Add Function
    // IDEA: Have Add function verify the array size and the number of items. If the new add function call will cause an out of bounds error, perform creation of a new array with the increased size, move all existing objects to the new array, add the new object, delete the old array, rename the new array. 
    // NOTE: Inspiration for Adding to the end of the array https://www.tutorialspoint.com/cplusplus-program-to-append-an-element-into-an-array 


// Add Function With All Required Parameters
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {

    


};

// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 

// TODO: Completed Remove Function
// TODO: Condense If Statements Into A Single Logical Operator 'OR' STATEMENT

void Roster::remove(string studentID) {

    int deletedStudent = 0;

    for (int i = 0; i < numStudents; i++) {
    
        if (classRosterArray[i] != nullptr) {
        
            if (classRosterArray[i]->getStudentID() == studentID) {
            
                cout << "FOUND - Deletion Beginning" << endl;
                cout << "Setting Student Object Location Variable" << endl;
                deletedStudent = i;
                cout << deletedStudent << endl;

                cout << "Deleting Object" << endl;
                delete classRosterArray[i];
                cout << "Deletion Successful" << endl;

                classRosterArray[i] = nullptr;
            
            }
            else {
                
                cout << "A Student with that ID was not found. Please try again." << endl;
            
            }
        
        }
    
    }

    cout << endl;
    cout << "---- ---- ---- ---- " << endl;
    cout << endl;


    printAll();

    cout << endl;
    cout << "---- ---- ---- ---- " << endl;
    cout << endl;

    // This loop moves the newly deleted student to the end of the array index. 
    // Ensuring that the open spots are at the end of the array. 


    for (int j = deletedStudent; j < numStudents-1; j++) {
        classRosterArray[j] = classRosterArray[j + 1];
        classRosterArray[j + 1] = nullptr;
    
    
    }



};

// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 

// Print All Function

void Roster::printAll() {
            
    for (int i = 0; i < numStudents; i++) {
            
        if (classRosterArray[i] != nullptr) {
            
            classRosterArray[i]->print();
            
        }
        else {
            cout << "classRosterArray[" << i << "] is empty and set to a nullptr" << endl;
        }

    }
    
};

// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 

// Print Average Days In Course Function

void Roster::printAverageDaysInCourse(string studentID) {
    int sum = 0;

    for (int i = 0; i < numStudents; i++) {

        if (classRosterArray[i] != nullptr) {

            if (classRosterArray[i]->getStudentID() == studentID) {

                // TODO: FIX Array Capture Code 

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

                // TODO: Is it possible to get the size of the array? Current issue is sizeof(classRosterArray[i]->getStudentDaysInCourse()) pulls a pointer not the array itself.

                cout << "Sum Of Array Items: " << sum << endl;
                cout << endl;
                
                // TODO: Need A Way to Count and Store Array Size to make the average computation dynamic. Dynamic computation also need to be converted to double to ensure double data type. 
                
                // Average variable is created and set to double data type. Sum for average is computed in the above for loop. Average is currently calculated statically with 3.0 to ensure integer/double division occurs to keep double data type. 
                double avg = (sum / 3.0);

                // Average Value Is Formated With "Fixed" function to set fixed floating-point notation
                // Average value Is formated With "setprecision" function to format the floating-point notation to a specific value

                cout << "Average Days In Courses: " << fixed << setprecision(2) << avg << endl;

                
            }

        }

    }


};


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 

//TODO: Print Invalid Emails Function
    // NOTE: A valid email per school project requirements: should include an at sign ('@') and period ('.') and should not include a space (' '). [Part E, Number 3, Section e]
        // NOTE: Valid Email Address Information https://en.wikipedia.org/wiki/Email_address
        // Only one @ symbol
            // Local Part (local_part@domain.com)
                // Allowed: Upper Case (A-Z) and Lower Case (a-z) characters (latin only)
                // Allowed: Number digits (0-9)
                // Allowed: Printable Characters !#$%&'*+-/=?^_`{|} 
                // Allowed With Exception: Periods, Period cannot be the first or last characters and cannot appear consecutively (..)
            // Domain Part
                // Allowed: Upper Case (A-Z) and Lower Case (a-z) characters (Latin only)
                // Allowed With Exception: Number digits (0-9) allowed as long as not all of the characters in the domain name are not numeric.
                // Allowed With Exception: Hyphen, as long as it is not the first or last character.
                
            // There is more information on the above web address. 
    // 
        // IDEA: Get Length/Size of email Address. Loop through each character, check for spaces first. 

void Roster::printInvalidEmails() {

    for (int i = 0; i < numStudents; i++) {
    
        if (classRosterArray[i] != nullptr) {

            // Get Email Address and Assign It To A Temporary String Variable
            string _emailAddress = classRosterArray[i]->getStudentEmailAddress();
            string _studentID = classRosterArray[i]->getStudentID();
            int _emailAddressLength = _emailAddress.length();

            cout << "---- ---- ---- ---- " << endl;
            cout << _emailAddress << endl;
            cout << _studentID << endl;
            cout << _emailAddressLength << endl;
            cout << "---- ---- ---- ---- " << endl;

            // Loop to check for spaces, uses .length() string standard library function. 
            // Length was choosen because it returns the number of characters, while size() returns the size in memory 
                // (However, they are basically the same because a single character (1 char) is a single byte in size (1 byte) [1 char = 1 byte].)
            for (int j = 0; j < _emailAddressLength; j++) {

                // If Statement Checks If Current Character is a Space -- If A space is detected, and error message is printed. 

                // TODO: Should I look into try and catch error message handling. 

                if (isspace(_emailAddress.at(j))) {
                    cout << "INVALID EMAIL ADDRESSES:" << endl;
                    cout << "Student ID:" << "\t\t" << "Reason:" << endl;
                    cout << "\t" << "    ";
                    cout << _studentID;
                    cout << "\t\t\t";
                    cout << "Email Address Contains A Space." << endl << endl;;
                    break;
                }
                
                // Checks If First Or Last Character Are Periods -- If First and/or Last characters are a period, an error message is printed. 
                if ((ispunct(_emailAddress.at(0))) || (ispunct(_emailAddress.at(_emailAddressLength-1)))) {
                    cout << "INVALID EMAIL ADDRESSES:" << endl;
                    cout << "Student ID:" << "\t\t" << "Reason:" << endl;
                    cout << "\t" << "    ";
                    cout << _studentID;
                    cout << "\t\t\t";
                    cout << "Email Address Contains Has A Period As Either The First Or Last Character." << endl << endl;;
                    break;
                }

            }

        }
    
    }

};

// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 

// Print By Degree Program Function 

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

// TODO: DELETE FROM FINAL
// Custom Function to Get Student Object by Array Index Value -- Used During Testing -- Can Be Deleted

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

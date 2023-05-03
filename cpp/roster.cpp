#include "..\header\roster.h"
#include <iostream>
#include <iomanip> 
#include <array>
#include <string>
#include <sstream>

using namespace std;

// Roster Class

/*
const string studentData[5] = {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY","A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK","A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE","A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY","A5,Danty,Cook,DCoo230@wgu.edu,34,77,42,60,SOFTWARE"};
*/

//
// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
//
// CONSTRUCTORS - START 

// TODO: DELTE FROM FINAL -- USED FOR TESTING
// Constructor With Debug Comments

Roster::Roster() {
    cout << "Constructor Successfully Started" << endl;
    cout << endl;

    // TODO: Not Sure If I Should Keep This Here or Remove It and Find A Better Way To Calculate The Size
    // IDEA: Parse The Data At The Same Time I'm Performing The Size/Element Count. Possibly Peform The Parseing After The Size Count. 

    /*
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Danty,Cook,DCoo230@wgu.edu,34,77,42,60,SOFTWARE"
    };
    */


    cout << "Int numStudents variable is currently set to: " << numStudents << endl;
    cout << "Int inputSize variable is currently set to: " << inputSize << endl;

    cout << endl;

    cout << "Calculating Size of Student Data Input Array - Start" << endl;

    // This was used with the above commented out studentData Array.
    //inputSize = *(&studentData + 1) - studentData;
    // string len = *(studentData + 1);

    
    // NOT SURE IF THIS WILL WORK
    //inputSize = studentData->size();

    // NOTE: May have to make a for loop to calculate the array size as a possible work around but that would be frowned above.
    // FOR LOOP

    cout << "Calculating Size of Student Data Input Array - End" << endl;

    cout << endl;
    cout << "studentData Input String Array has a total of " << inputSize << " elements." << endl;

    cout << endl;
    cout << "Setting Int numStudents variable equal to the inputSize result" << endl;

    //numStudents = inputSize;
    
    cout << "Int numStudents variable was updated with the inputSize result, " << numStudents << endl;
    cout << endl;
    cout << endl;

    classRosterArray = new Student*[initializationPointerArraySize];
    cout << "\t";
    cout << "classRosterArray variable was created successfully and " << initializationPointerArraySize << " Student Pointers were created" << endl;

    cout << endl;
    cout << "\t";
    cout << "Constructor Pointer NullPtr Assignment Loop Starting" << endl;
    for (int i = 0; i < initializationPointerArraySize; i++) {

        // Assigns classRosterArray Elements To Nullptr To Ensure All Pointer Elements Are Initialized. 
        classRosterArray[i] = nullptr;
        cout << "\t\t";
        cout << "classRosterArray[" << i << "] was successfully assigned as nullptr" << endl;
    }
    cout << "\t";
    cout << "Constructor Pointer NullPtr Assignment Loop Completed" << endl;
    cout << endl;
    
    // TODO: Added Back numStudents Assignment with the InitializationPointerArraySize set to 5
    numStudents = initializationPointerArraySize;
    
    cout << "\t";
    cout << "Constructor Pointer Assignment To New Object Loop Started" << endl;
    cout << endl;

    //TODO: Need To Remove the Object Creation And Move It To Add Function. 

    /*
    for (int i = 0; i < numStudents; i++) {

        classRosterArray[i] = new Student();
        cout << "\t\t";
        cout << "classRosterArray[" << i << "] was successfully assigned the address of the newly created Student Object" << endl;
        cout << "\t\t\t";
        cout << "Located at " << &classRosterArray[i] << endl;
    }
    */
    cout << "\t";
    cout << "Constructor Pointer Assignment To New Object Loop Completed" << endl;
    cout << endl;
    cout << endl;

    
    

    cout << endl;
    cout << "Constructor Successfully Completed" << endl;

};

/*
// TODO: Uncomment From Final
// Constructor Without Debug Comments
 
Roster::Roster() {
    
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Danty,Cook,DCoo230@wgu.edu,34,77,42,60,SOFTWARE"
    };

    inputSize = *(&studentData + 1) - studentData;

    numStudents = inputSize;

    classRosterArray = new Student * [numStudents];

    for (int i = 0; i < numStudents; i++) {
        classRosterArray[i] = nullptr;
    }

    for (int i = 0; i < numStudents; i++) {
        classRosterArray[i] = new Student();
    }

};

*/
/*
Roster::Roster(int classSize) {
    cout << "Constructor Successfully Started" << endl;
    cout << endl;

    // numStudents Variable Is Set By Arguement From Paramaterized Constructor
    numStudents = classSize;

    cout << "Int numStudents variable was updated with the inputSize result, " << numStudents << endl;
    cout << endl;
    cout << endl;

    classRosterArray = new Student * [numStudents];
    cout << "\t";
    cout << "classRosterArray variable was created successfully and " << numStudents << " Student Pointers were created" << endl;

    cout << endl;
    cout << "\t";
    cout << "Constructor Pointer NullPtr Assignment Loop Starting" << endl;
    for (int i = 0; i < numStudents; i++) {

        // Assigns classRosterArray Elements To Nullptr To Ensure All Pointer Elements Are Initialized. 
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

        // For Loop To Create A New Student Object And Assigns It To A classRosterArray Element
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

    cout << endl;
    cout << "Constructor Successfully Completed" << endl;

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
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {

    // IDEA: Perform a loop to check all index positions first for null ptr. If a nullptr is found that is not at the end, perform sort of array. Then update currentStudentIndex and then add new student?
    // 
    // for (int i = 0; i < numStudents; i++) {
    
        if (classRosterArray[currentStudentIndex] == nullptr) {
            cout << endl;
            cout << "Empty Array Location Found" << endl;
            cout << "Creating daysInCourse[] Int Array and populating It With Parameters: daysInCourse1, daysInCourse2, daysInCourse3" << endl;

                int daysInCourse[3] = {};
                
                daysInCourse[0] = daysInCourse1;
                daysInCourse[1] = daysInCourse2;
                daysInCourse[2] = daysInCourse3;

                cout << "Population Of daysInCourse Int Array Completed" << endl;
                cout << "Int Array daysInCourse[] = {";
                
                for (int j = 0; j < 3; j++) {
                    if (j < 2) {
                        cout << daysInCourse[j];
                        cout << ", ";
                    }
                    else {
                        cout << daysInCourse[j];
                        cout << "}" << endl << endl;
                    }
                }

                DegreeProgram _degreeProgram = DegreeProgram::NETWORK;
                _degreeProgram = degreeProgram;


                classRosterArray[currentStudentIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, _degreeProgram);
                currentStudentIndex++;
                cout << "---- ---- ---- ---- ";
                cout << endl << endl;
        }
    
    // }
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
            
    cout << "S.ID:" << "\t";
    cout << "First Name: " << "\t\t";
    cout << "Last Name: " << "\t\t";
    cout << "Age: " << "\t";
    cout << "Days In Course []:" << "\t";
    cout << "Degree Program: ";
    cout << endl;

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
    int sumOfDays = 0;
    int numOfCourses = 0;
    double courseDayAvg = 0.0;

    for (int i = 0; i < numStudents; i++) {

        if (classRosterArray[i] != nullptr) {

            if (classRosterArray[i]->getStudentID() == studentID) {

                // TODO: FIX Array Capture Code -- Need to find a way to set the j loop max dynamically, this way num of courses will update as the array changes

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
                    
                    sumOfDays += classRosterArray[i]->getStudentDaysInCourse()[j];
                    numOfCourses += 1;
                }

                cout << "}";
                cout << endl;

                // TODO: Is it possible to get the size of the array? Current issue is sizeof(classRosterArray[i]->getStudentDaysInCourse()) pulls a pointer not the array itself.

                cout << "Sum Of Array Items: " << sumOfDays << endl;
                cout << endl;

                cout << "Total Courses Taken: " << numOfCourses << endl;
                cout << endl;

                cout << "Performing Static_Cast Type Conversion From Int To Double On numOfCourses Variable." << endl;
                cout << "Performing Division Of Sum of Days By the Static_casted numOfCourse Variable to generate the average days in courses" << endl;

                // Total Number Of Days, sumOfDays Is calculated in the loop, Total Number Of Courses is also calculated In The Loop; Number Of Courses is then static_casted into double format for division.  
                courseDayAvg = (sumOfDays / static_cast<double>(numOfCourses));

                // Average Value Is Formated With "Fixed" function to set fixed floating-point notation
                // Average value Is formated With "setprecision" function to format the floating-point notation to a specific value

                cout << "Average Days In Courses: " << fixed << setprecision(2) << courseDayAvg << endl;

                
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

    bool invalidAddressFound = false;

    for (int i = 0; i < numStudents; i++) {
    
        if (classRosterArray[i] != nullptr) {

            // Get Email Address and Assign It To A Temporary String Variable
            string _emailAddress = classRosterArray[i]->getStudentEmailAddress();
            string _studentID = classRosterArray[i]->getStudentID();
            // Changing from int to size_t to remove compiler warning regarding possible data loss due to type conversion. 
            size_t _emailAddressLength = _emailAddress.length();

            cout << "---- ---- ---- ---- " << endl;
            cout << _emailAddress << endl;
            cout << _studentID << endl;
            cout << _emailAddressLength << endl;
            cout << "---- ---- ---- ---- " << endl;

            // START OF EMAIL CHECK ---- ---- ---- ---- ---- ---- ---- ----  


            // Checks Email Address To Verify That An At (@) Symbol Is Present AND That Only One (1) Is Present. 

            size_t startingIndex = 0;
            size_t workingIndex = 0;
            size_t countAtSymbols = 0;

            if (_emailAddress.find("@") != string::npos) {

                while (_emailAddress.find("@", startingIndex) != string::npos) {

                    workingIndex = _emailAddress.find("@", startingIndex);
                    countAtSymbols++;
                    if (countAtSymbols > 1) {
                        invalidAddressFound = true;
                        cout << "INVALID EMAIL ADDRESSES:" << endl;
                        cout << "Student ID:" << "\t\t" << "Reason:" << endl;
                        cout << "\t" << "    ";
                        cout << _studentID;
                        cout << "\t\t\t";
                        cout << "Email Address Contains More Than One At (@) Symbol." << endl << endl;;
                        break;
                    }
                    startingIndex = (workingIndex + 1);

                }
            }
            else {
                cout << "INVALID EMAIL ADDRESSES:" << endl;
                cout << "Student ID:" << "\t\t" << "Reason:" << endl;
                cout << "\t" << "    ";
                cout << _studentID;
                cout << "\t\t\t";
                cout << "Email Address Does Not Contain A At (@) Symbol." << endl << endl;;
                break;
            
            }


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

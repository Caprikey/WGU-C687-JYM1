#include "..\header\roster.h"

#include <iostream>
#include <iomanip> 
#include <array>
#include <string>
#include <sstream>
#include <vector>


using namespace std;

// Roster Class


// Project Required:: Input Data:
    // Student Data Table Arrary Input For PRFA YMJ1

const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Danty,Cook,DCoo230@wgu.edu,34,77,42,60,SOFTWARE"
};

//
// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
//
// CONSTRUCTORS - START 

// TODO: DELTE FROM FINAL -- USED FOR TESTING
// Constructor With Debug Comments

Roster::Roster() {

    getInputSize();

    numStudents = inputDataSize;

    classRosterArray = new Student*[numStudents];

    for (int i = 0; i < numStudents; i++) {

        // Assigns classRosterArray Elements To Nullptr To Ensure All Pointer Elements Are Initialized. 
        classRosterArray[i] = nullptr;

    }

    parseInputData();

};

// CONSTRUCTORS - END
//
// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
//
// DECONSTRUCTORS - START 

// TODO: DELTE FROM FINAL -- USED FOR TESTING
// Deconstructor With Debug Comments

Roster::~Roster() {

    for (int i = 0; i < numStudents; i++) {

        if (classRosterArray[i] != nullptr) {

            delete classRosterArray[i];
            classRosterArray[i] = nullptr;

        }

    }

    delete[] classRosterArray;

};

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

    ++currentStudentIndex;

    if (classRosterArray[currentStudentIndex] == nullptr) {

        int daysInCourse[3] = {};
                
        daysInCourse[0] = daysInCourse1;
        daysInCourse[1] = daysInCourse2;
        daysInCourse[2] = daysInCourse3;

        degreeProgram = degreeProgram;

        classRosterArray[currentStudentIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);

    }
    
};

// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 


void Roster::remove(string studentID) {

    bool isFound = false;
    int deletedStudent = 0;

    for (int i = 0; i < numStudents; i++) {
    
        if (classRosterArray[i] != nullptr) {        
            
            if (classRosterArray[i]->getStudentID() == studentID) {

                isFound = true;
                deletedStudent = i;

                delete classRosterArray[i];

                classRosterArray[i] = nullptr;
                --currentStudentIndex;

                break;
            }
            else {
                // TODO: Fix Error Message And Loop Exit
                bool isFound = false;
                cout << "ERROR: ";
                cout << "A Student with that ID was not found. Please try again." << endl;
            }

        }

        if (isFound) {
            
            break;
            
        }


    }

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

    int NumOfCoursesArraySize = 3;
    int sumOfDays = 0;
    int numOfCourses = 0;
    double courseDayAvg = 0.0;
        
        for (int i = 0; i < numStudents; i++) {

        if (classRosterArray[i] != nullptr) {

            if (classRosterArray[i]->getStudentID() == studentID) {

                //
                //cout << "Student ID: " << classRosterArray[i]->getStudentID() << "\t\t";
                
                cout << "\t";
                cout << classRosterArray[i]->getStudentID();

                // TODO: FIX Array Capture Code -- Need to find a way to set the j loop max dynamically, this way num of courses will update as the array changes

                for (int j = 0; j < NumOfCoursesArraySize; j++) {
                    
                    sumOfDays += classRosterArray[i]->getStudentDaysInCourse()[j];
                    numOfCourses += 1;
                }

                // Total Number Of Days, sumOfDays Is calculated in the loop, Total Number Of Courses is also calculated In The Loop; Number Of Courses is then static_casted into double format for division.  
                courseDayAvg = (sumOfDays / static_cast<double>(numOfCourses));

                // Average Value Is Formated With "Fixed" function to set fixed floating-point notation
                // Average value Is formated With "setprecision" function to format the floating-point notation to a specific value

                //cout << "Average Days In Courses: " << fixed << setprecision(2) << courseDayAvg << endl;
                cout << "\t\t";
                cout << fixed << setprecision(2) << courseDayAvg << endl;
                
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

        // IDEA: Get Length/Size of email Address. Loop through each character, check for spaces first. 

void Roster::printInvalidEmails() {

    // Creates a Vector that accepts a pair of two string data types as a single element.  
    vector<pair<string, string>> invalidEmails;
    
    //DELETE: cout << "INVALID EMAIL ADDRESS" << endl;

    for (int i = 0; i < numStudents; i++) {
    
        if (classRosterArray[i] != nullptr) {

            // Boolean Variable To Use As A Variable Flag
            //bool invalidAddressFound = false;

            // Get Student ID and Assign It To A Tempory String Variable
            string _studentID = classRosterArray[i]->getStudentID();

            // Get Email Address and Assign It To A Temporary String Variable
            string _emailAddress = classRosterArray[i]->getStudentEmailAddress();

            // Get Length Of Student Emails Addresss and Assigning it to a temporary size_t variable to be used with loops below. 
                // Changing from int to size_t to remove compiler warning regarding possible data loss due to type conversion. 
            size_t _emailAddressLength = _emailAddress.length();

            // Debugging Print Out of Temp Variable Values For Current Student In Loop
            //DELETE: cout << "---- ---- ---- ---- " << endl;
            //DELETE: cout << _emailAddress << endl;
            //DELETE: cout << _studentID << endl;
            //DELETE: cout << _emailAddressLength << endl;
            //DELETE: cout << "---- ---- ---- ---- " << endl;

            // START OF EMAIL CHECK ---- ---- ---- ---- ---- ---- ---- ----  

            // Checks Email Address To Verify That An At (@) Symbol Is Present AND That Only One (1) Is Present. 

            // Tempoary Size_t variables used for computations below. Initialized To zero. 
            size_t startingIndex = 0;
            size_t workingIndex = 0;
            size_t countAtSymbols = 0;
            size_t singleAtSymbolIndex = 0;
            size_t countPeriods = 0;

            //Start of At Symbol

            if (_emailAddress.find("@") != string::npos) {

                while (_emailAddress.find("@", startingIndex) != string::npos) {

                    workingIndex = _emailAddress.find("@", startingIndex);
                    countAtSymbols++;
                    if (countAtSymbols > 1) {
                        //invalidAddressFound = true;

                        string invalidEmailError1 = "Email Address Contains More Than One At (@) Symbol";

                        invalidEmails.push_back(make_pair(_studentID, invalidEmailError1));

                        //DELETE: cout << "INVALID EMAIL ADDRESSES:" << endl;
                        //DELETE: cout << "Student ID:" << "\t\t" << "Reason:" << endl;
                        //DELETE: cout << "\t" << "    ";
                        //DELETE: cout << _studentID;
                        //DELETE: cout << "\t\t\t";
                        //DELETE: cout << "Email Address Contains More Than One At (@) Symbol." << endl << endl;;
                        //break;
                    } 
                    startingIndex = (workingIndex + 1);
                }

                if (countAtSymbols == 1) {
                
                    singleAtSymbolIndex = startingIndex-1;
                
                }


            } else {

                string invalidEmailError2 = "Email Address Does Not Contain A At (@) Symbol.";

                invalidEmails.push_back(make_pair(_studentID, invalidEmailError2));

                //DELETE: cout << "INVALID EMAIL ADDRESSES:" << endl;
                //DELETE: cout << "Student ID:" << "\t\t" << "Reason:" << endl;
                //DELETE: cout << "\t" << "    ";
                //DELETE: cout << _studentID;
                //DELETE: cout << "\t\t\t";
                //DELETE: cout << "Email Address Does Not Contain A At (@) Symbol." << endl << endl;;
                //break;
            
            }

            // End Of At Symbol 

            if (countAtSymbols == 1) {
                
                if (_emailAddress.at(singleAtSymbolIndex + 1) == '-') {

                    string invalidEmailError9 = "Email Address Contains A Hyphen (-) Symbol After The At (@) Symbol and As The First Character Of The Domain Address";

                    invalidEmails.push_back(make_pair(_studentID, invalidEmailError9));

                    //DELETE: cout << "INVALID EMAIL ADDRESSES:" << endl;
                    //DELETE: cout << "Student ID:" << "\t\t" << "Reason:" << endl;
                    //DELETE: cout << "\t" << "    ";
                    //DELETE: cout << _studentID;
                    //DELETE: cout << "\t\t\t";
                    //DELETE: cout << "Email Address Contains A Hyphen (-) Symbol After The At (@) Symbol and As The First Character Of The Domain Address" << endl << endl;;
                    //break;
                }
            }

            // Loop to check for spaces, uses .length() string standard library function. 
            // Length was choosen because it returns the number of characters, while size() returns the size in memory 
                // (However, they are basically the same because a single character (1 char) is a single byte in size (1 byte) [1 char = 1 byte].)
            for (int j = 0; j < _emailAddressLength; j++) {

                // If Statement Checks If Current Character is a Space -- If A space is detected, and error message is printed. 

                // TODO: Should I look into try and catch error message handling.          
                if (isspace(_emailAddress.at(j))) {

                    string invalidEmailError5 = "Email Address Contains A Space.";

                    invalidEmails.push_back(make_pair(_studentID, invalidEmailError5));

                    //DELETE: cout << "INVALID EMAIL ADDRESSES:" << endl;
                    //DELETE: cout << "Student ID:" << "\t\t" << "Reason:" << endl;
                    //DELETE: cout << "\t" << "    ";
                    //DELETE: cout << _studentID;
                    //DELETE: cout << "\t\t\t";
                    //DELETE: cout << "Email Address Contains A Space." << endl << endl;;
                    //break;
                }
            }
                
                // Checks If First Or Last Character Are An At Symbol -- If First and/or Last characters are a period, an error message is printed. 
                // Checks If First Or Last Character Are Periods -- If First and/or Last characters are a period, an error message is printed. 
            if ((ispunct(_emailAddress.at(0))) || (ispunct(_emailAddress.at(_emailAddressLength-1)))) {
                    
                if ((_emailAddress.at(0) == '@') || (_emailAddress.at(_emailAddressLength - 1) == '@')) {

                    string invalidEmailError6 = "Email Address Contains An At (@) Symbol At Either The First Or Last Character.";

                    invalidEmails.push_back(make_pair(_studentID, invalidEmailError6));

                    //DELETE: cout << "INVALID EMAIL ADDRESSES:" << endl;
                    //DELETE: cout << "Student ID:" << "\t\t" << "Reason:" << endl;
                    //DELETE: cout << "\t" << "    ";
                    //DELETE: cout << _studentID;
                    //DELETE: cout << "\t\t\t";
                    //DELETE: cout << "Email Address Contains An At (@) Symbol At Either The First Or Last Character." << endl << endl;;
                    //break;
                }
                else if ((_emailAddress.at(0) == '.') || (_emailAddress.at(_emailAddressLength - 1) == '.')) {

                    string invalidEmailError7 = "Email Address Contains An A Period (.) At Either The First Or Last Character.";

                    invalidEmails.push_back(make_pair(_studentID, invalidEmailError7));

                    //DELETE: cout << "INVALID EMAIL ADDRESSES:" << endl;
                    //DELETE: cout << "Student ID:" << "\t\t" << "Reason:" << endl;
                    //DELETE: cout << "\t" << "    ";
                    //DELETE: cout << _studentID;
                    //DELETE: cout << "\t\t\t";
                    //DELETE: cout << "Email Address Contains An A Period (.) At Either The First Or Last Character." << endl << endl;;
                    //break;
                }
                else if (_emailAddress.at(_emailAddressLength - 1) == '-') {

                    string invalidEmailError8 = "Email Address Contains A Hyphen (-) As The Last Character.";

                    invalidEmails.push_back(make_pair(_studentID, invalidEmailError8));

                    //DELETE: cout << "INVALID EMAIL ADDRESSES:" << endl;
                    //DELETE: cout << "Student ID:" << "\t\t" << "Reason:" << endl;
                    //DELETE: cout << "\t" << "    ";
                    //DELETE: cout << _studentID;
                    //DELETE: cout << "\t\t\t";
                    //DELETE: cout << "Email Address Contains A Hyphen (-) As The Last Character." << endl << endl;;
                    //break;
                }
                else {
                    cout << "No Errors" << endl;
                    continue;
                }

                    
            }

            if (_emailAddress.find('.') != string::npos) {

                while (_emailAddress.find(".", startingIndex) != string::npos) {

                    workingIndex = _emailAddress.find(".", startingIndex);
                    countAtSymbols++;

                    if (countAtSymbols > 1) {
                        //invalidAddressFound = true;

                        if (_emailAddress.at(workingIndex) = 0) {

                            if (_emailAddress.at(workingIndex + 1) == '.') {

                                string invalidEmailError3 = "Email Address Contains More Than One Period (.) Symbol In A Row.";

                                invalidEmails.push_back(make_pair(_studentID, invalidEmailError3));

                                //DELETE: cout << "INVALID EMAIL ADDRESSES:" << endl;
                                //DELETE: cout << "Student ID:" << "\t\t" << "Reason:" << endl;
                                //DELETE: cout << "\t" << "    ";
                                //DELETE: cout << _studentID;
                                //DELETE: cout << "\t\t\t";
                                //DELETE: cout << "Email Address Contains More Than One Period (.) Symbol In A Row." << endl << endl;;
                                //break;
                            }

                        }
                        else if (_emailAddress.at(workingIndex) == _emailAddressLength) {

                            if (_emailAddress.at(workingIndex + -1) == '.') {

                                string invalidEmailError3 = "Email Address Contains More Than One Period (.) Symbol In A Row.";

                                invalidEmails.push_back(make_pair(_studentID, invalidEmailError3));

                                //DELETE: cout << "INVALID EMAIL ADDRESSES:" << endl;
                                //DELETE: cout << "Student ID:" << "\t\t" << "Reason:" << endl;
                                //DELETE: cout << "\t" << "    ";
                                //DELETE: cout << _studentID;
                                //DELETE: cout << "\t\t\t";
                                //DELETE: cout << "Email Address Contains More Than One Period (.) Symbol In A Row." << endl << endl;;
                                // break;
                            }


                        }
                        else if (!(_emailAddress.at(workingIndex) == 0) && (!(_emailAddress.at(workingIndex) == _emailAddressLength))) {

                            if ((_emailAddress.at(workingIndex - 1) == '.') || (_emailAddress.at(workingIndex + 1) == '.')) {

                                string invalidEmailError3 = "Email Address Contains More Than One Period (.) Symbol In A Row.";

                                invalidEmails.push_back(make_pair(_studentID, invalidEmailError3));

                                //DELETE: cout << "INVALID EMAIL ADDRESSES:" << endl;
                                //DELETE: cout << "Student ID:" << "\t\t" << "Reason:" << endl;
                                //DELETE: cout << "\t" << "    ";
                                //DELETE: cout << _studentID;
                                //DELETE: cout << "\t\t\t";
                                //DELETE: cout << "Email Address Contains More Than One Period (.) Symbol In A Row." << endl << endl;;
                                //break;
                            }

                        }
                        //(!(_emailAddress.at(workingIndex) >= _emailAddressLength)) ||
                    //((_emailAddress.at(workingIndex - 1) == '.') ||

                    }

                    startingIndex = (workingIndex + 1);

                }
            }
            else {

                string invalidEmailError4 = "Email Address Does Not Contain A Period (.) Symbol.";

                invalidEmails.push_back(make_pair(_studentID, invalidEmailError4));

                //DELETE: cout << "INVALID EMAIL ADDRESSES:" << endl;
                //DELETE: cout << "Student ID:" << "\t\t" << "Reason:" << endl;
                //DELETE: cout << "\t" << "    ";
                //DELETE: cout << _studentID;
                //DELETE: cout << "\t\t\t";
                //DELETE: cout << "Email Address Does Not Contain A Period (.) Symbol." << endl << endl;;
                //break;

            }

        }
    
    }

    //DELETE: cout << "---- ---- ---- ---- ---- ---- ---- ---- " << endl;
    //DELETE: cout << endl;


    if (!invalidEmails.empty()) {
    
        cout << "Invalid Email Address Results:" << endl;

        for (auto const& invalidEmail : invalidEmails) {
        
            cout << "Student ID: " << invalidEmail.first << ", Reason: " << invalidEmail.second << endl;
        
        }
    
    }
    else {
    
        cout << "No Invalid Emails Were Found." << endl;
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


// Gets A Pointer To A Pointer of Student Objects. 


Student** Roster::getAllStudents() {

    return classRosterArray;

}

/*

Use Like This:
    Student** studentptr = classRoster.getAllStudents();
    Student* firstStudent = studentptr[1];
    firstStudent->getStudentID();

*/

// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 

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

// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 


// Gets Current Non-NullPtr Pointers In classRosterArray
__int64 Roster::getCurrentStudentCount() {

    __int64 currentStudentCount = 0;

    if (numStudents == (currentStudentIndex - 1)) {
        
        currentStudentCount = numStudents;
    }
    else {

        for (int i = 0; i < numStudents; i++) {

            if (classRosterArray[i] != nullptr) {
                currentStudentCount++;
            }
        }

    }
   
    return currentStudentCount;

}

// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 

void Roster::printAverageDaysInCourseAll(const Roster& roster) {

    for (int i = 0; i < getCurrentStudentCount(); i++) {
    
        string currentStudent = classRosterArray[i]->getStudentID();

        printAverageDaysInCourse(currentStudent);

    }


}


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 

void Roster::parseInputData() {

    string parsedVariableData[9] = {};

    string parsingWorker;
    string parsedVariable;

    for (int i = 0; i < numStudents; i++) {

        parsingWorker = studentData[i];
        stringstream inputParseData(parsingWorker);
        int j = 0;

        while (getline(inputParseData, parsedVariable, ',')) {
            //cout << parsedVariable << endl;
            parsedVariableData[j++] = parsedVariable;

        }

        DegreeProgram degreeProgram;
        degreeProgram = NETWORK;

        if (parsedVariableData[8] == "NETWORK") {
            //std::cout << "Degree Program Is Network" << endl;
            degreeProgram = NETWORK;
        }
        else if (parsedVariableData[8] == "SOFTWARE") {
            //std::cout << "Degree Program Is Software" << endl;
            degreeProgram = SOFTWARE;
        }
        else if (parsedVariableData[8] == "SECURITY") {
            //std::cout << "Degree Program Is Security" << endl;
            degreeProgram = SECURITY;
        }

        add(parsedVariableData[0], parsedVariableData[1], parsedVariableData[2], parsedVariableData[3], (stoi(parsedVariableData[4])), (stoi(parsedVariableData[5])), (stoi(parsedVariableData[6])), (stoi(parsedVariableData[7])), degreeProgram);

    }
};

// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 


__int64 Roster::getInputSize() {

    inputDataSize = sizeof(studentData) / sizeof(studentData[0]);

    return inputDataSize;

};


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 



// MEMBER FUNCTIONS - END
//
// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 

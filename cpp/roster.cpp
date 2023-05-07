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
        "A5,Danty,Cook ,DCoo230@wgu.edu,34,77,42,60,SOFTWARE"
};

//
// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
//
// CONSTRUCTORS - START 

// TODO: DELTE FROM FINAL -- USED FOR TESTING
// Constructor With Debug Comments

Roster::Roster() {

    // Calls The getInputSize() Function To Calculate The Size Of The Input Data From The Array Of Strings, studentData. 
    getInputSize();
    
    // Sets The numStudents Variable Equal To The inputDataSize Varaible, Cwalculated In The Above Function. 
    numStudents = inputDataSize;

    // Creates An Array Of Pointers To Student Objects called classRosterArray; The Array's Size Is Set By numStudents variable. 
    classRosterArray = new Student*[numStudents];

    // For Loop To Iterate From i=0 to i < numStudents; Passing Index i To The classRosterArray[i].
    for (int i = 0; i < numStudents; i++) {

        // Assigns classRosterArray Elements To Nullptr To Ensure All Pointer Elements Are Initialized. 
        classRosterArray[i] = nullptr;

    }

    // Calls parseInputData() Function To Begin The Parsing Of The Input Data Located In the Array Of Strings, studentData. 
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

    // For Loop Iterates From i to numStudents Passing The Index i To The classRosterArray[i]
    for (int i = 0; i < numStudents; i++) {

        // If Statement Evaluates If Element At Index i Is Not A NullPtr
        if (classRosterArray[i] != nullptr) {

            // Deleteing Each Of The Objects Stored At Each Element Of the classRosterArray
            delete classRosterArray[i];

            // Setting Each Pointer Element To NullPtr
            classRosterArray[i] = nullptr;

        }

    }

    // Delete Deletes The classRosterArray, Array Of Pointers, After All Objects Have Been Deleted and Their Elements Have Been Set To NullPtr
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

    // Pre-Increments The currentStudentIndex By One (+1). 
    ++currentStudentIndex;

    // If Statment Validates If The classRosterArray Index At Current Index Number, Set By currentStudentIndex Variable, Is A NullPtr.
    if (classRosterArray[currentStudentIndex] == nullptr) {

        // Creates A daysInCourse Array With A Size Of Three (3) And Initializes It Null
        int daysInCourse[3] = {};
        
        // Assigns The daysInTheCourse1 Argument To The First Index (0) Position Of The daysInCourse[] Array
        daysInCourse[0] = daysInCourse1;
        
        // Assigns The daysInTheCourse2 Argument To The Second Index (1) Position Of The daysInCourse[] Array
        daysInCourse[1] = daysInCourse2;

        // Assigns The daysInTheCourse3 Argument To The Third Index (2) Position Of The daysInCourse[] Array
        daysInCourse[2] = daysInCourse3;

        // Assigns The Arguement degreeProgram To The degreeProgram Variable
        degreeProgram = degreeProgram;

        // Creates A New Student Object Using The Paramaterized Student Constructor And Assigns It To The Current Student Index Number
        classRosterArray[currentStudentIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);

    }
    
};

// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 


void Roster::remove(string studentID) {

    // Creates A Boolean Variable Called isFound And Sets It To False
    bool isFound = false;

    // Creates An Int Variable Called deletedStudent And Sets It To 0
    int deletedStudent = 0;

    // For Loop To Iterate From i=0 to i < numStudents; Passing Index i To The classRosterArray[i].
    for (int i = 0; i < numStudents; i++) {
    
        // If Statement Verifies If The classRosterArray Element Located At The Position Of i Is Not A NullPtr
        if (classRosterArray[i] != nullptr) {        
            
            // If Statement Verfies Uses The Student Object Accessor To Capture The Student ID Of The Current Index i Position Of The classRosterArray And Check If It Is Equal To The Student ID Argument. 
            if (classRosterArray[i]->getStudentID() == studentID) {

                // Sets isFound Boolean Variable To True
                isFound = true;

                //Sets deletedStudent Variable To The Index i To Be Used With For Loop Below
                deletedStudent = i;

                // Deletes The Student Object Located At Index i In The classRosterArray
                delete classRosterArray[i];

                // Sets The classRosterArray Element At Index i To NullPtr
                classRosterArray[i] = nullptr;

                // Pre-Decrements The currentStudentIndex By One (-1). 
                --currentStudentIndex;

                // Character Out Statement Advising Student Object/ID Has Been Successfully Deleted.
                cout << "Student " << studentID << " has been removed successfully.";

                // Breaks Out Of Loop
                break;
            }

        }

    }

    // If Statement Checks isFound Variable. If Not True -- Error Message Is Printed
    if (!isFound) {

        cout << "ERROR: ";
        cout << "A Student with that ID was not found. Please try again." << endl;

    }

    // If Statement Checks isFound Variable. If True -- Newly Assigned NullPtr (Removed Student) Is Swapped With The Next Element In The Array Until It Is The Last Element (I.e. NullPtrs Are Always Moved To The End Of The Index)
    if (isFound) {

        // For Loop Sets J To The deletedStudent Variable Calculated Above And Loops By Increment Up By 1 Until J is less Than The Vale Of numStudents - 1. 
        for (int j = deletedStudent; j < numStudents - 1; j++) {

            // Student At Position J Is Set To Student At Position Of j + 1
            classRosterArray[j] = classRosterArray[j + 1];
            
            // Student Now At Position J+1 Is Now Set To Null Ptr.
            classRosterArray[j + 1] = nullptr;

        }

    }

};

// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 

// Print All Function

void Roster::printAll() {


    //cout << "Current Enrolled Students: " << endl;
    
    cout.fill(' ');
    cout.width(75);
    cout << right << "Current Enrolled Students:" << endl;
    
    cout << endl;

    cout << "Student ID" << "\t";
    cout << "First Name" << "\t\t";
    cout << "Last Name" << "\t\t";
    cout << "Age" << "\t";
    //cout << "Days In Course []" << "\t";
    
    cout.width(27);
    cout << left << "Days In Course []";


    //cout << "Degree Program";

    cout.width(14);
    cout << left << "Degree Program";
    
    cout << endl;
    cout << "---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ";
    cout << endl;


    for (int i = 0; i < numStudents; i++) {
            
        if (classRosterArray[i] != nullptr) {
            
            classRosterArray[i]->print();

        }
        else {

            cout << endl;
            cout << endl;
            //cout << "Current Available Seats In Class" << endl;
            
            cout.fill(' ');
            cout.width(78);
            cout << right << "Current Available Seats In Class" << endl;

            cout << endl;

            cout << "---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ";
            cout << endl;
            cout << "Seat " << i + 1 << " is avaible." << endl;
            //cout << "classRosterArray[" << i << "] is empty and set to a nullptr" << endl;

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
        
        // For Loop To Iterate From i=0 to i < numStudents; Passing Index i To The classRosterArray[i].
        for (int i = 0; i < numStudents; i++) {

        // If Statement Verifies If The classRosterArray Element Located At The Position Of i Is Not A NullPtr
        if (classRosterArray[i] != nullptr) {

            // If Statment Uses The getStudentID Accessor From The Student Object Located At The classRosterArray Index Position Of i And Verifies If It Matches The studentID Arument Received. 
            if (classRosterArray[i]->getStudentID() == studentID) {

                //
                //cout << "Student ID: " << classRosterArray[i]->getStudentID() << "\t\t";
                
                cout << "\t";
                cout << classRosterArray[i]->getStudentID();

                // TODO: FIX Array Capture Code -- Need to find a way to set the j loop max dynamically, this way num of courses will update as the array changes

                // For Loop To Iterate From j=0 to j < NumOfCourseArraySize; Passing Index J To The Index Position Of The Student Object daysInCourse[] Array Accessor For The Current Index Of i Position classRosterArray. 
                for (int j = 0; j < NumOfCoursesArraySize; j++) {

                    // Sum Of Days Variable Is Updated By Adding The Current Running Total With daysInCourse Array Index At Position j From The Student Object Accessor for The Current classRosterArray At Index Of i
                    sumOfDays += classRosterArray[i]->getStudentDaysInCourse()[j];

                    // Number Of Courses Variable Is Iterated By 1
                    numOfCourses += 1;
                }

                // Total Number Of Days, sumOfDays Is calculated in the loop, Total Number Of Courses is also calculated In The Loop; Number Of Courses is then static_casted into double format for division.  
                courseDayAvg = (sumOfDays / static_cast<double>(numOfCourses));

                // Average Value Is Formated With "Fixed" function to set fixed floating-point notation
                // Average value Is formated With "setprecision" function to format the floating-point notation to a specific value
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

    // For Loop To Iterate From i=0 to i < numStudents; Passing Index i To The classRosterArray[i].
    for (int i = 0; i < numStudents; i++) {
    
        // If Statement Verifies If The classRosterArray Element Located At The Position Of i Is Not A NullPtr
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

            if (debugging) {
                // Debugging Print Out of Temp Variable Values For Current Student In Loop
                cout << "---- ---- ---- ---- " << endl;
                cout << _emailAddress << endl;
                cout << _studentID << endl;
                cout << _emailAddressLength << endl;
                cout << "---- ---- ---- ---- " << endl;

            }

            // START OF EMAIL CHECK ---- ---- ---- ---- ---- ---- ---- ----  

            // Checks Email Address To Verify That An At (@) Symbol Is Present AND That Only One (1) Is Present. 

            // Tempoary Size_t Variables: startingIndex, workingIndex, countAtSymbol, singleAtSymboleIndex, countPeriods, Are Created And Initialized To Zero (0) To Be Used With Computations Below
            size_t startingIndex = 0;
            size_t workingIndex = 0;
            size_t countAtSymbols = 0;
            size_t singleAtSymbolIndex = 0;
            size_t countPeriods = 0;

            //Start of At Symbol

            //
            if (_emailAddress.find("@") != string::npos) {

                //
                while (_emailAddress.find("@", startingIndex) != string::npos) {

                    //
                    workingIndex = _emailAddress.find("@", startingIndex);
                    
                    //
                    countAtSymbols++;

                    // 
                    if (countAtSymbols > 1) {
                        //invalidAddressFound = true;

                        string invalidEmailError1 = "Email Address Contains More Than One At (@) Symbol";

                        invalidEmails.push_back(make_pair(_studentID, invalidEmailError1));

                        if (debugging) {

                            cout << "INVALID EMAIL ADDRESSES:" << endl;
                            cout << "Student ID:" << "\t\t" << "Reason:" << endl;
                            cout << "\t" << "    ";
                            cout << _studentID;
                            cout << "\t\t\t";
                            cout << "Email Address Contains More Than One At (@) Symbol." << endl << endl;

                        }

                        //break;
                    } 

                    // Sets startingIndex Value Equal To The Value Of workingIndex Plus One (1)
                    startingIndex = (workingIndex + 1);

                }

                // If Statement Checks If countAtSymbols Is Equal to One (1)
                if (countAtSymbols == 1) {
                    
                    // If True, Sets singleAtSymbolIndex Value To The Value Of StartingIndex - 1
                    singleAtSymbolIndex = startingIndex-1;
                
                }

            } 
            // If Not True -- Pushes Email Error Message To Vector.
            else {

                string invalidEmailError2 = "Email Address Does Not Contain An At (@) Symbol.";

                invalidEmails.push_back(make_pair(_studentID, invalidEmailError2));

                if (debugging) {
                    
                    cout << "INVALID EMAIL ADDRESSES:" << endl;
                    cout << "Student ID:" << "\t\t" << "Reason:" << endl;
                    cout << "\t" << "    ";
                    cout << _studentID;
                    cout << "\t\t\t";
                    cout << "Email Address Does Not Contain A At (@) Symbol." << endl << endl;
                     
                }

                //break;
            
            }

            // End Of At Symbol 

            // If Statement Checks If The countAtSymbols variable is equal to One (1)
            if (countAtSymbols == 1) {
                
                // If Statement Checks If The Character At singleAtSymbolIndex + 1 In The Email String Is A Hyphen (If There Is Only One At (@) Symbol, Is The Next Character A Hypen (i.e. @-domain.com ))
                if (_emailAddress.at(singleAtSymbolIndex + 1) == '-') {

                    string invalidEmailError9 = "Email Address Contains A Hyphen (-) Symbol After The At (@) Symbol and As The First Character Of The Domain Address";

                    invalidEmails.push_back(make_pair(_studentID, invalidEmailError9));

                    if (debugging) {

                        cout << "INVALID EMAIL ADDRESSES:" << endl;
                        cout << "Student ID:" << "\t\t" << "Reason:" << endl;
                        cout << "\t" << "    ";
                        cout << _studentID;
                        cout << "\t\t\t";
                        cout << "Email Address Contains A Hyphen (-) Symbol After The At (@) Symbol and As The First Character Of The Domain Address" << endl << endl;
                         
                    }

                    //break;

                }

            }

            // Loop to check for spaces, uses .length() string standard library function. 
            // Length was choosen because it returns the number of characters, while size() returns the size in memory 
                // (However, they are basically the same because a single character (1 char) is a single byte in size (1 byte) [1 char = 1 byte].)
            for (int j = 0; j < _emailAddressLength; j++) {

                // If Statement Checks If Current Character is a Space -- If A space is detected, and error message is printed.         
                if (isspace(_emailAddress.at(j))) {

                    string invalidEmailError5 = "Email Address Contains A Space.";

                    invalidEmails.push_back(make_pair(_studentID, invalidEmailError5));

                    if (debugging) {

                        cout << "INVALID EMAIL ADDRESSES:" << endl;
                        cout << "Student ID:" << "\t\t" << "Reason:" << endl;
                        cout << "\t" << "    ";
                        cout << _studentID;
                        cout << "\t\t\t";
                        cout << "Email Address Contains A Space." << endl << endl;

                    }
                    
                    //break;
                
                }
            
            }
                
                // Checks If First Or Last Character Are An At Symbol -- If First and/or Last characters are a period, an error message is printed. 
                // Checks If First Or Last Character Are Periods -- If First and/or Last characters are a period, an error message is printed. 
            if ((ispunct(_emailAddress.at(0))) || (ispunct(_emailAddress.at(_emailAddressLength-1)))) {
                
                // If Statement Checks If The Character At Position 0 Or Position Email Total Size Minus 1 Are An At (@) Symbol
                if ((_emailAddress.at(0) == '@') || (_emailAddress.at(_emailAddressLength - 1) == '@')) {

                    string invalidEmailError6 = "Email Address Contains An At (@) Symbol At Either The First Or Last Character.";

                    invalidEmails.push_back(make_pair(_studentID, invalidEmailError6));

                    if (debugging) {

                        cout << "INVALID EMAIL ADDRESSES:" << endl;
                        cout << "Student ID:" << "\t\t" << "Reason:" << endl;
                        cout << "\t" << "    ";
                        cout << _studentID;
                        cout << "\t\t\t";
                        cout << "Email Address Contains An At (@) Symbol At Either The First Or Last Character." << endl << endl;

                    }

                    //break;
                }

                // If Statement Checks If The Character At Position 0 Or Position Email Total Size Minus 1 Are A Period (.) Symbol
                else if ((_emailAddress.at(0) == '.') || (_emailAddress.at(_emailAddressLength - 1) == '.')) {

                    string invalidEmailError7 = "Email Address Contains An A Period (.) At Either The First Or Last Character.";

                    invalidEmails.push_back(make_pair(_studentID, invalidEmailError7));

                    if (debugging) {

                        cout << "INVALID EMAIL ADDRESSES:" << endl;
                        cout << "Student ID:" << "\t\t" << "Reason:" << endl;
                        cout << "\t" << "    ";
                        cout << _studentID;
                        cout << "\t\t\t";
                        cout << "Email Address Contains An A Period (.) At Either The First Or Last Character." << endl << endl;

                    }

                    //break;

                }

                // If Statement Checks If The Last Charager Of The Email (Email Total Minus 1) Is A Hyphen (-) Symbol
                else if (_emailAddress.at(_emailAddressLength - 1) == '-') {

                    string invalidEmailError8 = "Email Address Contains A Hyphen (-) As The Last Character.";

                    invalidEmails.push_back(make_pair(_studentID, invalidEmailError8));

                    if (debugging) {

                        cout << "INVALID EMAIL ADDRESSES:" << endl;
                        cout << "Student ID:" << "\t\t" << "Reason:" << endl;
                        cout << "\t" << "    ";
                        cout << _studentID;
                        cout << "\t\t\t";
                        cout << "Email Address Contains A Hyphen (-) As The Last Character." << endl << endl;

                    }

                    //break;

                }
                else {

                    if (debugging) {

                        cout << "No Errors" << endl;

                    }

                    continue;

                }
                    
            }

            // If Statement Checks String Does Not Contain A Period (.) Symbol (No Position)
            if (_emailAddress.find('.') != string::npos) {

                // While Loop Performs The Find Function On The Email Address String Starting At The startingIndex Position And Continues As Long As The Find Function Does Not Return No Position.
                while (_emailAddress.find(".", startingIndex) != string::npos) {

                    // Sets workingIndex variable To The Location Of The Matched Character Using The String Find Function Starting At The startingIndex Position. 
                    workingIndex = _emailAddress.find(".", startingIndex);
                    
                    // Post-Increments countPeriods Variable By One
                    countPeriods++;

                    // If Statement CHecks If countPeriods Variable Is Greater Than One
                    if (countPeriods > 1) {
                        //invalidAddressFound = true;

                        // If Statement Checks If The Current Position Of The workingIndex Character In The Email Address String Is Equal To The First Character In The Email Address (I.e. The Email Address String First Chracter)
                        if (_emailAddress.at(workingIndex) = 0) {
                            
                            // If Statment Checks If Character At workingIndex + 1 Position Is A Period; Checks If The Character After The Current Period Is Also A Period (..)
                            if (_emailAddress.at(workingIndex + 1) == '.') {

                                string invalidEmailError3 = "Email Address Contains More Than One Period (.) Symbol In A Row.";

                                invalidEmails.push_back(make_pair(_studentID, invalidEmailError3));

                                if (debugging){

                                    cout << "INVALID EMAIL ADDRESSES:" << endl;
                                    cout << "Student ID:" << "\t\t" << "Reason:" << endl;
                                    cout << "\t" << "    ";
                                    cout << _studentID;
                                    cout << "\t\t\t";
                                    cout << "Email Address Contains More Than One Period (.) Symbol In A Row." << endl << endl;

                                }

                                //break;

                            }

                        }

                        // If Statement Checks If The Current Position Of The workingIndex Character In The Email Address String Is Equal To The Last Character In The Email Address (I.e. The Email Address String's Size)
                        else if (_emailAddress.at(workingIndex) == _emailAddressLength) {

                            // If Statment Checks If Character At workingIndex - 1 Position Is A Period; Checks If The Character Before The Current Period Is Also A Period (..)
                            if (_emailAddress.at(workingIndex + -1) == '.') {

                                string invalidEmailError3 = "Email Address Contains More Than One Period (.) Symbol In A Row.";

                                invalidEmails.push_back(make_pair(_studentID, invalidEmailError3));

                                if (debugging) {

                                    cout << "INVALID EMAIL ADDRESSES:" << endl;
                                    cout << "Student ID:" << "\t\t" << "Reason:" << endl;
                                    cout << "\t" << "    ";
                                    cout << _studentID;
                                    cout << "\t\t\t";
                                    cout << "Email Address Contains More Than One Period (.) Symbol In A Row." << endl << endl;
                                    
                                }

                                // break;

                            }


                        }
                        // If Statement Checks If Character At The Position Of workingIndex Is NOT Equal To The First Character AND The Last CHaracter In The Email Address String
                        else if (!(_emailAddress.at(workingIndex) == 0) && (!(_emailAddress.at(workingIndex) == _emailAddressLength))) {


                            // If Statement Checks If The Character At Position workingIndex - 1 OR workingIndex + 1 Are A Period 
                            if ((_emailAddress.at(workingIndex - 1) == '.') || (_emailAddress.at(workingIndex + 1) == '.')) {

                                string invalidEmailError3 = "Email Address Contains More Than One Period (.) Symbol In A Row.";

                                invalidEmails.push_back(make_pair(_studentID, invalidEmailError3));

                                if (debugging) {
                                    
                                    cout << "INVALID EMAIL ADDRESSES:" << endl;
                                    cout << "Student ID:" << "\t\t" << "Reason:" << endl;
                                    cout << "\t" << "    ";
                                    cout << _studentID;
                                    cout << "\t\t\t";
                                    cout << "Email Address Contains More Than One Period (.) Symbol In A Row." << endl << endl;

                                }

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

                if (debugging){
                
                    cout << "INVALID EMAIL ADDRESSES:" << endl;
                    cout << "Student ID:" << "\t\t" << "Reason:" << endl;
                    cout << "\t" << "    ";
                    cout << _studentID;
                    cout << "\t\t\t";
                    cout << "Email Address Does Not Contain A Period (.) Symbol." << endl << endl;

                }

                //break;

            }

        }
    
    }

    if (debugging) {

        cout << "---- ---- ---- ---- ---- ---- ---- ---- " << endl;
        cout << endl;

    }


    if (!invalidEmails.empty()) {
    

        //cout << "Invalid Email Address Results:" << endl;

        cout.width(77);
        cout << right << "Invalid Email Address Results" << endl;

        cout << endl;
        cout.width(19);
        cout << left << "Student ID";
        cout << "| Reason: ";
        cout << endl;
        cout << "---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ";
        cout << endl;
        

        for (auto const& invalidEmail : invalidEmails) {
        
            cout << "Student ID: " << invalidEmail.first << "     | Reason: " << invalidEmail.second << endl;
        
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

    cout.width(75);
    cout << right << "Search By Degree Program:" << endl;
    
    cout.width(66);
    
    if (degreeProgram == NETWORK) {
        cout << right << "NETWORK";
    }
    else if (degreeProgram == SOFTWARE) {
        cout << right << "SOFTWARE";
    }
    else if (degreeProgram == SECURITY) {
        cout << right << "SECURITY";
    }
    
    cout << endl;
    cout << endl;

    cout << "Student ID" << "\t";
    cout << "First Name" << "\t\t";
    cout << "Last Name" << "\t\t";
    cout << "Age" << "\t";
    //cout << "Days In Course []" << "\t";

    cout.width(27);
    cout << left << "Days In Course []";


    //cout << "Degree Program";

    cout.width(14);
    cout << left << "Degree Program";
    
    cout << endl;
    cout << "---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ";
    cout << endl;

    // For Loop To Iterate From i=0 to i < numStudents; Passing Index i To The classRosterArray[i].
    for (int i = 0; i < numStudents; i++) {

        // If Statement Verifies If The classRosterArray Element Located At The Position Of i Is Not A NullPtr
        if (classRosterArray[i] != nullptr) {

            // If Statment Uses The getStudentDegreeProgram() Accessor From The Student Object Located At The classRosterArray Index Position Of i And Verifies If It Matches The degreeProgram Arument Received. 
            if (classRosterArray[i]->getStudentDegreeProgram() == degreeProgram) {
        
                // If True -- The Print Function For The Student Object Located At The classRosterArray Element Located At The Position Of i
                classRosterArray[i]->print();

                // Continue To Next Loop Interation Is Called.
                continue;

            }
            // If Not True
            else {
                
                // Error Message Is Printed. 
                cout << "No Students Were Found" << endl;
                
            }
        
        }

    }

};

// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 

// TODO: DELETE FROM FINAL


// Gets A Pointer To A Pointer of Student Objects. 

/*
Student** Roster::getAllStudents() {

    return classRosterArray;

}
*/
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


// Function Gets Current Non-NullPtr Pointers In classRosterArray
__int64 Roster::getCurrentStudentCount() {

    // Creates A __INT64 Variable Called currentStudentCount and Assigns It With A Value Of 0
    __int64 currentStudentCount = 0;

    // If Statment Validates Of the numStudents Variable Value Is Equal To The Value Of The currentStudentIndex Variable Minus 1
    if (numStudents == (currentStudentIndex - 1)) {
        
        // If True -- currentStudentCount Is Set To numStudents
        currentStudentCount = numStudents;
    }
    // If Not True
    else {

        // For Loop To Iterate From i=0 to i < numStudents; Passing Index i To The classRosterArray[i].
        for (int i = 0; i < numStudents; i++) {

            // If Statement Verifies If The classRosterArray Element Located At The Position Of i Is Not A NullPtr
            if (classRosterArray[i] != nullptr) {

                // Post-Increments currentStudentCount By One 
                currentStudentCount++;

            }
        }

    }
   
    // Returns currentStudentCount value
    return currentStudentCount;

}

// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 

void Roster::printAverageDaysInCourseAll(const Roster& roster) {

    // For Loop To Iterate From i=0 to i < getCurrentStudent Count Function; Passing Index i To The classRosterArray[i].
    for (int i = 0; i < getCurrentStudentCount(); i++) {
    
        // Creates A String Variable Called currentStudent; Using The getStudentID Accessor Of The Student Object Of The Current classRosterArray Index At i, Assigns currentStudent The Student ID.
        string currentStudent = classRosterArray[i]->getStudentID();

        // Calls The printAverageDaysInCourse Function With The String Variable currentStudent As The Argument. 
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

    // For Loop 
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

    // Sets The __INT64 Variable To The Size Of The Number Of Elements In The studentData Input Data. Does This By Dividing The Size of The studentData Array By The First Element Size Of The studentData Array 
    inputDataSize = sizeof(studentData) / sizeof(studentData[0]);

    // Returns The Calculcated inputDatatSize
    return inputDataSize;

};


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 



// MEMBER FUNCTIONS - END
//
// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 

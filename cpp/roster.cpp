// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
// 
// ROSTER CLASS - START
//
// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
//
// LIBRARY - START
// 

#include <iostream>
#include <iomanip> 
#include <array>
#include <string>
#include <sstream>
#include <vector>

#include "..\header\roster.h"

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
// PUBLIC DATA MEMBERS - END
//
// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
//
// CONSTRUCTORS - START 


// Roster Constructor
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
// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
//
// DECONSTRUCTORS - START 

// Roster Deconstructor
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

    // Delete Function Performs A Deletion On The classRosterArray, Array Of Pointers, After All Objects Have Been Deleted and Their Elements Have Been Set To NullPtr
    delete[] classRosterArray;

};

// DECONSTRUCTORS - END
//
// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
// 
// MEMBER FUNCTIONS - START
//
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 


// Roster Add() Function Adds A New Student Object To the classRoster Array Using the Paramaterized Student Constructor Matches To Its Input Arguments.

    // IDEA: Improve The Add function's Methods to verify the array size and the number of items. 
        // If the new add function call will cause an out of bounds error, perform creation of a new array with the increased size, move all existing objects to the new array, add the new object, delete the old array, rename the new array. 
    // NOTE: Inspiration for Adding to the end of the array https://www.tutorialspoint.com/cplusplus-program-to-append-an-element-into-an-array 


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

// Roster Remove() Function. Takes A studentID String Argument To Remove The Matching Student Object From The classRosterArray and Shifts The New NullPtr To The End
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

// Roster printAll() Function -- Performs A Loop To Print All Students Using the Print Function From The Student Class. 

void Roster::printAll() {

    // Standard Output
    //cout << "Current Enrolled Students: " << endl;
    
    //Stylized Output
    cout.fill(' ');
    cout.width(75);
    cout << right << "Current Enrolled Students:" << endl;
    
    cout << endl;

    cout << "Student ID" << "\t";
    cout << "First Name" << "\t\t";
    cout << "Last Name" << "\t\t";
    cout << "Age" << "\t";
    
    // Standard Output
    //cout << "Days In Course []" << "\t";
    
    //Stylized Output
    cout.width(27);
    cout << left << "Days In Course []";

    // Standard Output
    //cout << "Degree Program";

    //Stylized Output
    cout.width(14);
    cout << left << "Degree Program";
    
    cout << endl;
    cout << "---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ";
    cout << endl;

    // For Loop To Iterate From i=0 to i < numStudents; Passing Index i To The classRosterArray[i].
    for (int i = 0; i < numStudents; i++) {
        
        // If Statement Verifies If The classRosterArray Element Located At The Position Of i Is Not A NullPtr
        if (classRosterArray[i] != nullptr) {
            
            // Performs The Student Object Print Function For The Student Object Located At Index i Of The classRosterArray
            classRosterArray[i]->print();

        }
        else {

            cout << endl;
            cout << endl;
            // Standard Output
            //cout << "Current Available Seats In Class" << endl;
            
            // Stylized Output
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

// Roster pAverageDaysInCourse Function. Prints Using The studentID String Argument. This Takes One Input And Provides Only One Output. 

void Roster::printAverageDaysInCourse(string studentID) {

    // Sets Temporary Variables And Initializes THem
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

                // Ouput
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

// Roster Function Checks If emailAddress String 


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

    // IDEA: I Would Like To Refactor/Optomize This Section More. 
        // NOTE: I Know I Could Do More Faster And "Easier" With Regex, But Wanted To Do It This Awful Way To Utilized More Of What Was Taught. 

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

            // If Statment Checks If debugging Variable Is Set To True
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

            //If Statement Checks If The Find Function Search Of The Email Address String For An At (@) Symbol Returns No Position.
            if (_emailAddress.find("@") != string::npos) {

                //While Loop Continues As Long As The Find Function Search Of The Email Address String For An At (@) Symbol Does Not Return No Position.
                while (_emailAddress.find("@", startingIndex) != string::npos) {

                    //The Location Of This Iterations At (@) Symbol Found Using The Find Function On The Email Address String Starting At the startingIndex Is Set To The workingIndex Variable
                    workingIndex = _emailAddress.find("@", startingIndex);
                    
                    // countAtSymbols Variable Is Incremented By One (1)
                    countAtSymbols++;

                    // If Statement Checks if countAtSymbols variable has a value greater than One (1)
                    if (countAtSymbols > 1) {
 
                        // Email Error Message 1 String -- Email Address Has More Than One At (@) Symbol
                        string invalidEmailError1 = "Email Address Contains More Than One At (@) Symbol";

                        // Student ID and Error Message Are Paired As A Single String Element Using Make_Pair Function And Inserted Into The invalidEmails Vector Using The Push_Back Function
                        invalidEmails.push_back(make_pair(_studentID, invalidEmailError1));

                        if (debugging) {

                            // Debugging Output Statements
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

                // Email Error Message 2 String -- Email Address Does Not Contain An At (@) Symbol.
                string invalidEmailError2 = "Email Address Does Not Contain An At (@) Symbol.";

                // Student ID and Error Message Are Paired As A Single String Element Using Make_Pair Function And Inserted Into The invalidEmails Vector Using The Push_Back Function
                invalidEmails.push_back(make_pair(_studentID, invalidEmailError2));

                // If Statement Checks If Debugging Variable Is Set To True
                if (debugging) {
                    
                    // Debugging Output Statements
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

                    // Email Error Message 9 String -- Email Address Contains A Hyphen (-) Symbol After The At (@) Symbol and As The First Character Of The Domain Address
                    string invalidEmailError9 = "Email Address Contains A Hyphen (-) Symbol After The At (@) Symbol and As The First Character Of The Domain Address";

                    // Student ID and Error Message Are Paired As A Single String Element Using Make_Pair Function And Inserted Into The invalidEmails Vector Using The Push_Back Function
                    invalidEmails.push_back(make_pair(_studentID, invalidEmailError9));

                    // If Statement Checks If Debugging Variable Is Set To True
                    if (debugging) {

                        // Debugging Output Statements
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

                    // Email Error Message 5 String -- Email Address Contains A Space.
                    string invalidEmailError5 = "Email Address Contains A Space.";

                    // Student ID and Error Message Are Paired As A Single String Element Using Make_Pair Function And Inserted Into The invalidEmails Vector Using The Push_Back Function
                    invalidEmails.push_back(make_pair(_studentID, invalidEmailError5));

                    // If Statement Checks If Debugging Variable Is Set To True
                    if (debugging) {

                        // Debugging Output Statements
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

                    // Email Error Message 6 String -- Email Address Contains An At (@) Symbol At Either The First Or Last Character.
                    string invalidEmailError6 = "Email Address Contains An At (@) Symbol At Either The First Or Last Character.";

                    // Student ID and Error Message Are Paired As A Single String Element Using Make_Pair Function And Inserted Into The invalidEmails Vector Using The Push_Back Function
                    invalidEmails.push_back(make_pair(_studentID, invalidEmailError6));

                    // If Statement Checks If Debugging Variable Is Set To True
                    if (debugging) {

                        // Debugging Output Statements
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

                    // Email Error Message 7 String -- 
                    // Email Error Message 7 String -- 
                    string invalidEmailError7 = "Email Address Contains An A Period (.) At Either The First Or Last Character.";

                    // Student ID and Error Message Are Paired As A Single String Element Using Make_Pair Function And Inserted Into The invalidEmails Vector Using The Push_Back Function
                    invalidEmails.push_back(make_pair(_studentID, invalidEmailError7));

                    // If Statement Checks If Debugging Variable Is Set To True
                    if (debugging) {

                        // Debugging Output Statements
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

                    // Email Error Message 8 String -- Email Address Contains A Hyphen (-) As The Last Character
                    string invalidEmailError8 = "Email Address Contains A Hyphen (-) As The Last Character.";

                    // Student ID and Error Message Are Paired As A Single String Element Using Make_Pair Function And Inserted Into The invalidEmails Vector Using The Push_Back Function
                    invalidEmails.push_back(make_pair(_studentID, invalidEmailError8));

                    // If Statement Checks If Debugging Variable Is Set To True
                    if (debugging) {

                        // Debugging Output Statements
                        cout << "INVALID EMAIL ADDRESSES:" << endl;
                        cout << "Student ID:" << "\t\t" << "Reason:" << endl;
                        cout << "\t" << "    ";
                        cout << _studentID;
                        cout << "\t\t\t";
                        cout << "Email Address Contains A Hyphen (-) As The Last Character." << endl << endl;

                    }

                    //break;

                }
                // If Not True, Print No Errors
                else {
                    
                    // If STatement Checks If Debugging Variable Is Set To True
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

                                // Email Error Message 3 String -- Email Address Contains More Than One Period (.) Symbol In A Row
                                string invalidEmailError3 = "Email Address Contains More Than One Period (.) Symbol In A Row.";

                                // Student ID and Error Message Are Paired As A Single String Element Using Make_Pair Function And Inserted Into The invalidEmails Vector Using The Push_Back Function
                                invalidEmails.push_back(make_pair(_studentID, invalidEmailError3));

                                // If Statement Checks If Debugging Variable Is Set To True
                                if (debugging){

                                    // Debugging Output Statements
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

                                // Email Error Message 3 String -- Email Address Contains More Than One Period (.) Symbol In A Row.
                                string invalidEmailError3 = "Email Address Contains More Than One Period (.) Symbol In A Row.";

                                // Student ID and Error Message Are Paired As A Single String Element Using Make_Pair Function And Inserted Into The invalidEmails Vector Using The Push_Back Function
                                invalidEmails.push_back(make_pair(_studentID, invalidEmailError3));

                                // If Statement Checks If Debugging Variable Is Set To True
                                if (debugging) {

                                    // Debugging Output Statements
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

                                // Email Error Message 3 String -- Email Address Contains More Than One Period (.) Symbol In A Row.
                                string invalidEmailError3 = "Email Address Contains More Than One Period (.) Symbol In A Row.";

                                // Student ID and Error Message Are Paired As A Single String Element Using Make_Pair Function And Inserted Into The invalidEmails Vector Using The Push_Back Function
                                invalidEmails.push_back(make_pair(_studentID, invalidEmailError3));

                                // If Statement Checks If Debugging Variable Is Set To True
                                if (debugging) {

                                    // Debugging Output Statements
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

                    // startingIndex Value Is Set To The Value of workingIndex + 1
                    startingIndex = (workingIndex + 1);

                }
            }
            else {

                // Email Error Message 4 String -- Email Address Does Not Contain A Period (.) Symbol.
                string invalidEmailError4 = "Email Address Does Not Contain A Period (.) Symbol.";

                // Student ID and Error Message Are Paired As A Single String Element Using Make_Pair Function And Inserted Into The invalidEmails Vector Using The Push_Back Function
                invalidEmails.push_back(make_pair(_studentID, invalidEmailError4));

                // If Statement Checks If Debugging Variable Is Set To True
                if (debugging){
                
                    // Debugging Output Statements
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

    // If Statement Checks If Debugging Variable Is Set To True
    if (debugging) {

        cout << "---- ---- ---- ---- ---- ---- ---- ---- " << endl;
        cout << endl;

    }

    // If Statment Checks If Vector Is Empty
    if (!invalidEmails.empty()) {
    
        // Standard Output
        //cout << "Invalid Email Address Results:" << endl;

        // Stylized Output
        cout.width(77);
        cout << right << "Invalid Email Address Results" << endl;

        // Standard Ouput
        // cout << "Student ID:" ;
        // cout << "\t\t" << "Reason:";
        // cout << endl;

        // Stylized Ouput
        cout << endl;
        cout.width(19);
        cout << left << "Student ID";
        cout << "| Reason: ";
        cout << endl;
        cout << "---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ";
        cout << endl;
        
        // For Loop That Uses The Pair Data Type To Iterate Over Each Element In The Vector
        for (auto const& invalidEmail : invalidEmails) {
        
            // Output Prints Out The Pair.first Element, the studentID and then the Pair.second element, the Error Reason
            cout << "Student ID: " << invalidEmail.first << "     | Reason: " << invalidEmail.second << endl;
        
        }
    
    }
    // If Not True -- Print No Invalid Addresses Found
    else {
    
        cout << "No Invalid Emails Were Found." << endl;
    }

};

// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 

// Print By Degree Program Function 

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {

    // Creates An Boolean Variable Called isFoundDegree and Sets It To False
    bool isFoundDegree = false;

    // Standard Output
    //cout << "Search By Degree Program:" << endl;

    // Stylized Output
    cout.width(75);
    cout << right << "Search By Degree Program:" << endl;
    
    cout.width(66);
    
    // If-Else Statement Matches The String Variable For The parsedVariableData At Index 8 (The 9th Item) To One Of The Three Enumerated Data Type Values. 
    if (degreeProgram == NETWORK) {
        
        // Standard Output
        //cout << "NETWORK";

        // Stylized Output
        cout << right << "NETWORK";
    }
    else if (degreeProgram == SOFTWARE) {

        // Standard Output
        //cout << "SOFTWARE";

        // Stylized Output
        cout << right << "SOFTWARE";
    }
    else if (degreeProgram == SECURITY) {

        // Standard Output
        //cout << "SECURITY";

        // Stylized Output
        cout << right << "SECURITY";
    }
    
    cout << endl;
    cout << endl;

    cout << "Student ID" << "\t";
    cout << "First Name" << "\t\t";
    cout << "Last Name" << "\t\t";
    cout << "Age" << "\t";
    
    // Standard Ouput
    //cout << "Days In Course []" << "\t";

    //Stylized Output
    cout.width(27);
    cout << left << "Days In Course []";

    // Standard Output
    //cout << "Degree Program";

    // Stylized Output
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
                
                // Sets isFoundDegree Variable To True For Use In No-Student Found If Statement.
                isFoundDegree = true;

                // If True -- The Print Function For The Student Object Located At The classRosterArray Element Located At The Position Of i
                classRosterArray[i]->print();

                // Continue To Next Loop Interation Is Called.
                continue;

            }
        
        }

    }

    // If Statement Checks If isFoundDegree Variable Is Set To False
    if (!isFoundDegree) {

        // Error Message Is Printed - Segment 1. 
        cout << "ERROR: No Students In The ";
        
        // IF-Else Statements Match The degreeProgram Argument Value From Earlier To Generate An Appropriate Error (No Students Found) Message - Segment 2
        if (degreeProgram == NETWORK) {
            cout << right << "NETWORK";
        }
        else if (degreeProgram == SOFTWARE) {
            cout << right << "SOFTWARE";
        }
        else if (degreeProgram == SECURITY) {
            cout << right << "SECURITY";
        }

        // Output Message Is Printed - Segment 3
        cout << " Degree Program Were Found." << endl;
    
    }

};

// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 

// 
// Roster getAllStudents() Function Returns The Student Pointer Array As classRosterArray
    
    // Usage:
        // Roster Class:
            // Function Returns A Pointer To Pointer Of A Student Object Set To The classRosterArray
        
        // Calling: 
            // Create A New Pointer-To-Pointer To Student Object
                // Set This To The Class Function (i.e. classRoster.getAllStudents() )
            // Create A New Pointer-To-Student Object
                // Set This To The Previously Created Pointer-To-Pointer To Student Object
            // Call The Newly Created "Pointer-To-Student-Object" To Perform Member Functions. 
                    
                // NOTE: NOT USED; KEEP TO PREVENT FROM FORGETTING ANOTHER METHOD
                // IDEA: Modify Some Of The Other Functions In This Class To Use This Method.

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
    // NOTE: Keeping To Save The Reference Material 

Student* Roster::getStudent(int i) {
    /*
    for (int i = 0; i < numStudents; i++) {
        if (this->classRosterArray[i]->getStudentID() == i) {
            return classRosterArray[i]
        }
    }
    return nullptr;
    */

    // Retusn classRosterArray At Index Of i As A Pointer To A Student Object. 
    return classRosterArray[i];
}

// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 


// Roster getCurrentStudentCount() Function Gets Current Non-NullPtr Pointers In classRosterArray And Returns An __int64 Value. 
__int64 Roster::getCurrentStudentCount() {

    // Creates A __INT64 Variable Called currentStudentCount and Assigns It With A Value Of 0
    __int64 currentStudentCount = 0;

    // If Statment Validates Of the numStudents Variable Value Is Equal To The Value Of The currentStudentIndex Variable Minus 1
    if (numStudents == (currentStudentIndex - 1)) {
        
        // If True -- currentStudentCount Is Set To numStudents
        currentStudentCount = numStudents;
    }
    // If Not True -- Loop Is Perform To Calculcate The currentStudentCount value. 
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

// Roster printAverageDaysInCourseAll() Function Takes A Roster Object To Perform A Loop On The classRosterArray Elements Calling The Roster printAverageDaysInCourse Function. 
// This Function Performs The Loop Inside the Roster Class Instead Of Performing The Loop Inside The Main() Function. 
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

// Roster parseInputData() Function Performs The studentData Array Element String Parsing And Then Calls The Add Function.
void Roster::parseInputData() {

    // Creates A String Array Called parsedVariableData Of 9 Elements. 
    string parsedVariableData[9] = {};

    // Creates A String Variable Called parsingWorker
    string parsingWorker;

    // Creates A String Variable Called parsedVariable
    string parsedVariable;

    // For Loop To Iterate From i=0 to i < numStudents; Passing Index i To The studentData[i] Array Of Strings. 
    for (int i = 0; i < numStudents; i++) {

        // Sets parsingWorker To The String Element At Index Of i From The studentData Input Data String Array
        parsingWorker = studentData[i];
        
        // Creates A String Stream Object Named inputParseData and Passes The parsingWorking String Variable For Input
        stringstream inputParseData(parsingWorker);
        
        // Creates An Int Variable And Sets It To 0 
        int j = 0;

        // While Loop Cycles Until Getline Function Returns False; 
        // Getline Function Takes The String Stream Object, inputParseData; 
        // Using A Comma Delimiter, Splits The String At Each Comma Assigning The Split Section's Value To parsedVariable Variable
        while (getline(inputParseData, parsedVariable, ',')) {
            
            // Checks If Debugging Variable Set To True.
            if (debugging) {
            
                cout << parsedVariable << endl;
            
            }

            // Sets The Current Split Segment To The parsedVariableData Array At The Index Of j Then Post-Increments The Value By One (1)
            parsedVariableData[j++] = parsedVariable;

        }

        // Calls An Enumerated Data Type, DegreeProgram, And Creates A Variable For It, degreeProgram 
        DegreeProgram degreeProgram;

        // Initializes The degreeProgram Variable To Network
        degreeProgram = NETWORK;

        // If-Else Statement Matches The String Variable For The parsedVariableData At Index 8 (The 9th Item) To One Of The Three Enumerated Data Type Values. 
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

        // Calls The Roster Add Function, Passing The Appropriate parsedVariableData Element To The Function. Elements 4, 5, 6, 7 Are Converted From String To Int Using the STOI() function; Element 8 Is Pulled From The degreeProgram Variable Set From The Above If-Else Statement. 
        add(parsedVariableData[0], parsedVariableData[1], parsedVariableData[2], parsedVariableData[3], (stoi(parsedVariableData[4])), (stoi(parsedVariableData[5])), (stoi(parsedVariableData[6])), (stoi(parsedVariableData[7])), degreeProgram);

    }
};

// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 

// Roster getInputSize() Function Calculates The Input Size Of The studentData Array. And Returns An __int64 Value
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
// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
//
// ROSTER CLASS - END
// 
// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
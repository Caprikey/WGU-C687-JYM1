#include <iostream>
#include <string>

#include <iomanip>
#include <cstring>

#include <sstream>

#include "header\stdafx.h"

#include "header\degree.h"
#include "header\student.h"
#include "header\roster.h"



// HEADER AND DEFINITION For Resizing A Console Window -- START

// NOTE Reference Source for following header and define information, as well as the following code in main() for resizing the console window from the following web site: https://cplusplus.com/forum/beginner/1481/
//the following line is necessary for the
//  GetConsoleWindow() function to work!
//it basically says that you are running this
//  program on Windows 2000 or higher
#define _WIN32_WINNT 0x0500

//it is important that the above line be typed
//  BEFORE <windows.h> is included
#include <windows.h>

// HEADER AND DEFINITION For Resizing A Console Window -- END



using namespace std;

// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 


// WGU STUDENT INFORMATION - START

//TODO: ADD WGU STUDENT REQUIRED INFO 

// WGU STUDENT INFORMATION - END


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

// TODO: DETERMINE How I am going to call this data. Loop in main calling the add function for Roster, or have the import and calls occur during instance creation?

// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 


int main() {

    // CONSOLE WINDOW RESIZE AND MOVING CODE - START
    
    // NOTE Reference Source for the above and the following code for resizing the console window from the following web site: https://cplusplus.com/forum/beginner/1481/
    
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r); //stores the console's current dimensions

    // MoveWindow(window_handle, x, y, width, height, redraw_window);
    // MoveWindow(console, r.left, r.top, 1300, 800, TRUE);
    MoveWindow(console, 350, 130, 1200, 800, TRUE);

    // Prints A-Z, 100 Times -- Original Code To From Reference Used To Populate Some Data Into The Console Window
    //for (int j = 0; j < 100; ++j)
    // Changed the original Code to 6 instead of 100 for use attempting to size my console window to the preferred width. 
    /*
    for (int j = 0; j < 6; ++j)
    {
        for (int i = 0x41; i < 0x5B; ++i)
            cout << (char)i;
    }
    cout << endl;
    */

    // Sleep and Second MoveWindow Commands below were remove to keep the cnosole from shifting to back to the original position and size after 1 second. 
    // Original Size and Positiong of the Console window is obtained in the third line of this code block, GetWindowRect(console, &r); 
    //Sleep(1000);
    //MoveWindow(console, r.left, r.top, r.right - r.left, r.bottom - r.top, TRUE);

    // CONSOLE WINDOW RESIZE AND MOVING CODE - START
    // 
    //TODO: FULL CLEANUP NEEDED 


    Roster classRoster;

    // ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ====

    string inputData;
    string parsedVariableData[9] = {};

    string parsingWorker;
    string parsedVariable;

    int inputDataSize = sizeof(studentData) / (sizeof(studentData[0]));
    cout << inputDataSize << endl;

    cout << endl;

    for (int i = 0; i < inputDataSize; i++) {

        parsingWorker = studentData[i];
        stringstream inputData(parsingWorker);
        int j = 0;

        while (getline(inputData, parsedVariable, ',')) {
            cout << parsedVariable << endl;
            parsedVariableData[j++] = parsedVariable;

        }

        DegreeProgram degreeProgram;
        degreeProgram = DegreeProgram::NETWORK;

        if (parsedVariableData[8] == "NETWORK") {
            std::cout << "Degree Program Is Network" << endl;
            degreeProgram = DegreeProgram::NETWORK;
        }
        else if (parsedVariableData[8] == "SOFTWARE") {
            std::cout << "Degree Program Is Software" << endl;
            degreeProgram = DegreeProgram::SOFTWARE;
        }
        else if (parsedVariableData[8] == "SECURITY") {
            std::cout << "Degree Program Is Security" << endl;
            degreeProgram = DegreeProgram::SECURITY;
        }

        classRoster.add(parsedVariableData[0], parsedVariableData[1], parsedVariableData[2], parsedVariableData[3], (stoi(parsedVariableData[4])), (stoi(parsedVariableData[5])), (stoi(parsedVariableData[6])), (stoi(parsedVariableData[7])), degreeProgram);

    }


    // ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ====

    cout << "Print All Function Test - Start" << endl;
    classRoster.printAll();
    cout << "Print All Function Test - End" << endl;
    cout << endl;
    // ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ====

    
    Student* studentDPTest1 = classRoster.getStudent(1);

    if (studentDPTest1 != nullptr) {
        cout << "Changing Degree Program To SECRUITY" << endl;
        cout << "Student DP Test 1's Student Object Address: " << &studentDPTest1 << endl;
        studentDPTest1->setStudentDegreeProgram(DegreeProgram::SECURITY);
        // Updating Student CPP to Use This, Fixed This Method
    }
    else {
        cout << "Student DP Test 1 Not Found" << endl;
    }
    cout << endl;
    cout << "Priting Updated Student Details" << endl;

    cout << endl;
    cout << "Manual Priting - Start" << endl;
    cout << studentDPTest1->getStudentID() << endl;
    auto test = studentDPTest1->getStudentID();
    cout << &test << endl << endl;
    cout << "Student ID - Change Test 1" << endl;


    cout << endl;
    cout << studentDPTest1->getStudentID();
    cout << endl;

    cout << "Manual Printing - End" << endl;
    cout << endl;

    studentDPTest1->print();

    cout << endl;
    // ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ====
    cout << endl;

    Student* studentDPTest2 = classRoster.getStudent(4);

    if (studentDPTest2 != nullptr) {
        cout << "Changing Degree Program To NETWORK" << endl;
        cout << "Student DP Test 2's Student Object Address: " << &studentDPTest2 << endl;
        studentDPTest2->setStudentDegreeProgram(DegreeProgram::NETWORK);
        // Updating Student CPP to Use This, Fixed This Method
    }
    else {
        cout << "Student DP Test 2 Not Found" << endl;
    }
    cout << endl;
    cout << "Priting Updated Student Details" << endl;

    studentDPTest2->print();

    cout << endl;
    // ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ====
    cout << endl;

    cout << "Updated Student CPP Set Function to Use This Now" << endl;
    cout << "Testing changing student details now" << endl;

    Student* studentDPTest3 = classRoster.getStudent(3);
    studentDPTest3->setStudentID("Test3");
    // This method worked after updating to this

    studentDPTest3->print();

    cout << endl;
    // ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ====
    cout << endl;

    cout << "Performing Print All Function Test Again - Start" << endl;
    classRoster.printAll();
    cout << "Performing Print All Function Test Again - End" << endl;

    cout << endl;
    // ==== ==== ==== ==== ==== ==== ==== ====  ==== ==== ==== ==== ==== ==== ==== ====
    cout << endl;
    cout << "Print By DegreeProgram Function Testing -- START" << endl;
    cout << endl;
    // ==== ==== ==== ==== ==== ==== ==== ==== 
    cout << endl;
    cout << "\t";
    cout << "By DegreeProgram::NETWORK - Start" << endl;
    cout << "---- ---- ---- ---- " << endl;
    //classRoster.printByDegreeProgram(DegreeProgram::NETWORK);
    classRoster.printByDegreeProgram(NETWORK);
    cout << "---- ---- ---- ---- " << endl;
    cout << "\t";
    cout << "By DegreeProgram::NETWORK - End" << endl;
    cout << endl;
    // ==== ==== ==== ==== 
    cout << endl;
    cout << "\t";
    cout << "By DegreeProgram::SOFTWARE - Start" << endl;
    cout << "---- ---- ---- ---- " << endl;
    //classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << "---- ---- ---- ---- " << endl;
    cout << "\t";
    cout << "By DegreeProgram::SOFTWARE - End" << endl;
    cout << endl;
    // ==== ==== ==== ==== 
    cout << endl;
    cout << "\t";
    cout << "By DegreeProgram::SECURITY - Start" << endl;
    cout << "---- ---- ---- ---- " << endl;
    //classRoster.printByDegreeProgram(DegreeProgram::SECURITY);
    classRoster.printByDegreeProgram(SECURITY);
    cout << "---- ---- ---- ---- " << endl;
    cout << "\t";
    cout << "By DegreeProgram::SECURITY - End" << endl;
    cout << endl;
    // ==== ==== ==== ==== ==== ==== ==== ====
    cout << endl;

    cout << "Print By DegreeProgram Function Testing -- END" << endl;
    cout << endl;
    // ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ====
    cout << endl;

    cout << endl;
    cout << "Print Average Days In Course Test - START" << endl;
    cout << endl;
    cout << "Priting Test3's Days In Course Array - ORIGINAL - START" << endl;
        cout << "daysInCourse: ";

        cout << "{";

        for (int i = 0; i < 3; i++) {
            if (i != 2) {
                cout << studentDPTest3->getStudentDaysInCourse()[i] << ", ";
            }
            else {
                cout << studentDPTest3->getStudentDaysInCourse()[i];
            }
        }
        cout << "} ";

        cout << endl;
        cout << "Priting Test3's Days In Course Array - ORIGINAL - END" << endl;

    studentDPTest3->setDaysInCourse(45,25,10);
    cout << endl;
    cout << "Priting Test3's Days In Course Array - MODIFIED - START" << endl;
    cout << "daysInCourse: ";

    cout << "{";

    for (int i = 0; i < 3; i++) {
        if (i != 2) {
            cout << studentDPTest3->getStudentDaysInCourse()[i] << ", ";
        }
        else {
            cout << studentDPTest3->getStudentDaysInCourse()[i];
        }
    }
    cout << "} ";

    cout << endl;
    cout << "Priting Test3's Days In Course Array - MODIFIED - END" << endl;
        cout << endl;

   classRoster.printAverageDaysInCourse("Test3");
    
    cout << endl;
    cout << "Print Average Days In Course Test - END" << endl;



    cout << endl;
    // ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ====
    cout << endl;


    Student* studentDPTest4 = classRoster.getStudent(2);
    studentDPTest4->setStudentID("B2");
    studentDPTest4->setStudentAge(29);
    studentDPTest4->setStudentFirstName("Buddy");
    studentDPTest4->setStudentLastName("Buccaneer");
    // This method worked after updating to this

    studentDPTest4->print();

    cout << endl;
    // ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ====
    cout << endl;

    classRoster.remove("B2");

    classRoster.printAll();
    
    cout << endl;
    // ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ====
    cout << endl;

    Student* studentDPTest5 = classRoster.getStudent(0);
    studentDPTest5->setStudentID("B3");
    studentDPTest5->setStudentAge(45);
    studentDPTest5->setStudentFirstName("Barba");
    studentDPTest5->setStudentLastName("Bacon");
    studentDPTest5->setStudentEmailAddress("Barba Bacon@@yahoo.com");

    studentDPTest3->setStudentEmailAddress("@testemaileremail.com");
    studentDPTest2->setStudentEmailAddress(".testemail@email.com");
    studentDPTest1->setStudentEmailAddress("testingmail@electronicmail.com.");


    cout << studentDPTest1->getStudentEmailAddress() << endl;
    cout << studentDPTest2->getStudentEmailAddress() << endl;
    cout << studentDPTest3->getStudentEmailAddress() << endl;


    cout << endl;
    // ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ====
    cout << endl;

    //TODO: Create Parsing function



    cout << endl;
    // ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ====
    cout << endl;

    classRoster.printAll();

    cout << endl;
    // ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ====
    cout << endl;
    cout << "Add function main () call " << endl;

    classRoster.add("D1","Danty","Cook","DantyDCookgmail..com",34,45,40,30,SOFTWARE);

    cout << endl;
    // ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ====
    cout << endl;


    classRoster.printAll();

    cout << endl;
    // ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ====
    cout << endl;


    classRoster.printInvalidEmails();

    cout << endl;
    // ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ====
    cout << endl;



    classRoster.printAll();

    cout << endl;
    // ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ====
    cout << endl;


    return 0;
}
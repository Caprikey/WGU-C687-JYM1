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

    // ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ====

    //
    Roster classRoster;


    cout << endl;
    // ---- ---- ---- ---- 
    cout << endl;
    
    //
    classRoster.printAll();
    
    cout << endl;
    // ---- ---- ---- ---- 
    cout << endl;
    
    //
    classRoster.printInvalidEmails();


    cout << endl;
    // ---- ---- ---- ---- 
    cout << endl;
    
    // 
    cout << "Students' Average Days In Course: " << endl;
    cout << "Student ID \t Average Days In Course" << endl;
    //
    for (int i = 0; i < classRoster.getCurrentStudentCount(); i++) {

        classRoster.printAverageDaysInCourse(classRoster.getStudent(i)->getStudentID());

    }


    cout << endl;
    // ---- ---- ---- ---- 
    cout << endl;
    
    // 
    cout << "Students' Average Days In Course: " << endl;
    cout << "Student ID \t Average Days In Course" << endl;
    //
    classRoster.printAverageDaysInCourseAll(classRoster);

    cout << endl;
    // ---- ---- ---- ---- 
    cout << endl;


    //
    classRoster.printByDegreeProgram(SOFTWARE);


    cout << endl;
    // ---- ---- ---- ---- 
    cout << endl;

    
    //
    classRoster.remove("A3");
    
    
    cout << endl;
    // ---- ---- ---- ---- 
    cout << endl;


    //
    classRoster.printAll();


    
    cout << endl;
    // ---- ---- ---- ---- 
    cout << endl;

    //
    classRoster.remove("A3");
    
    
    cout << endl;
    // ---- ---- ---- ---- 
    cout << endl;
    
    
    return 0;
}
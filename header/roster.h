// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
// 
// ROSTER HEADER - START
//
// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
//
// LIBRARY - START
// 

#pragma once
#include "degree.h"
#include "student.h"

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
// Roster Header

class Roster {


    //
    // ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
    //
    // PRIVATE SECTION - START 
    // 

    private:

        // Variable Creation: Array Of Pointers
        Student **classRosterArray;

        // Variable Creation: Number Of Students Value
            // NOTE: Changing from int to __int64 to remove compiler warning regarding possible data loss due to type conversion.
        __int64 numStudents = 0;

        // Variable Creation: Current Student Index For Loops.
            // NOTE: Changing from int to __int64 to remove compiler warning regarding possible data loss due to type conversion.
        __int64 currentStudentIndex = -1;

        // Variable Creation: Size Of The Input
            // NOTE: Changing from int to __int64 to remove compiler warning regarding possible data loss due to type conversion.
        __int64 inputSize = 0;

        // Variable Creation: Size of the Input Data
        // Set By getInputSize() function
            // NOTE: Changing from int to __int64 to remove compiler warning regarding possible data loss due to type conversion.
        __int64 inputDataSize;
        

        // Roster Class Debugging Flag
        bool debugging = false;

    //
    // PRIVATE SECTION - END
    //
    // ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
    //
    // PUBLIC SECTION - START
    // 

    public:

        //
        // ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
        //
        // 
        // PUBLIC VARIABLES - Start
        //
        // ---- ---- ---- ---- ---- ---- ---- ---- 
        //


        //
        // PUBLIC VARIABLES - END
        //
        // ---- ---- ---- ---- ---- ---- ---- ---- 
        //
        // ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
        //
        // FUNCTION DECLARATIONS
        //
        // CONSTRUCTORS - START
        //

            Roster();


        //
        // CONSTRUCTORS - END
        //
        // ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
        //
        // DECONSTRUCTORS - START
        //

            ~Roster();

        //
        // DECONSTRUCTORS - END
        //
        // ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
        //
        // MEMBER FUNCTIONS - START

        // Add Function With All Required Parameters
        void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);

        void remove(string studentID);

        void printAll();

        void printAverageDaysInCourse(string studentID);

        void printAverageDaysInCourseAll(const Roster& roster);

        void printInvalidEmails();

        void printByDegreeProgram(DegreeProgram degreeProgram);

        // Not Used -- But Keeping For Reference
        Student* getStudent(int i);

        void parseInputData();

        __int64 getInputSize();

        // Disabled -- But Keeping For Reference
        //Student** getAllStudents();

        __int64 getCurrentStudentCount();

        //
        // MEMBER FUNCTIONS - END
        //
        // ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
        //
        // PUBLIC SECTION - END
        // 
        // ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
        //

};

//
// ROSTER HEADER - END
//
// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 

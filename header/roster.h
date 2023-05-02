#pragma once
#include "degree.h"
#include "student.h"


using namespace std;

// Roster Header

class Roster {

    private:

        Student **classRosterArray;

        // TODO: Find out if there is a way to dynamically set this variable. 
            // IDEA: May have to do a static initial variable. Then count the array items in the input. Assign that count total to the int numStudents. Then perform a new array creation and delete the initial one or see if there is a way to count the input before the class call then pass the details. 
        
        // Changing from int to __int64 to remove compiler warning regarding possible data loss due to type conversion. 

        __int64 numStudents = 0;

        // Changing from int to __int64 to remove compiler warning regarding possible data loss due to type conversion. 
        __int64 inputSize = 0;

        

        
    public:
        
        // FUNCTION DECLARATIONS
        //
        // ==== ==== ==== ==== ==== ==== ==== ==== 
        // 
        // CONSTRUCTORS - START

        Roster();


        // CONSTRUCTORS - END
        // 
        // ==== ==== ==== ==== ==== ==== ==== ==== 
        //
        // DECONSTRUCTORS - START
        
        ~Roster();

        // DECONSTRUCTORS - END
        // 
        // ==== ==== ==== ==== ==== ==== ==== ==== 
        // 
        // MEMBER FUNCTIONS - START

        // Add Function With All Required Parameters
        void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
        
        void remove(string studentID);

        void printAll();

        void printAverageDaysInCourse(string studentID);

        void printInvalidEmails();

        void printByDegreeProgram(DegreeProgram degreeProgram);

        // TODO: DELETE FROM FINAL -- CREATED FOR TESTING
        Student* getStudent(int i);


        // MEMBER FUNCTIONS - END
        // ==== ==== ==== ==== ==== ==== ==== ==== 


};

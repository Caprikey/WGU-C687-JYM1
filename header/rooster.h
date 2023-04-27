#pragma once
#include "degree.h"

#include <iostream>
#include <string>

using namespace std;

// Rooster Header

class Rooster {

    private:
        // ==== ==== ==== ==== ==== ==== ==== ==== 
        // VARIABLES - START

        Student* classRoosterArray[5];
        int numStudents = 0;


        // VARIABLES - END
        // ==== ==== ==== ==== ==== ==== ==== ==== 


    public:

        // FUNCTION DECLARATIONS
        //
        // ==== ==== ==== ==== ==== ==== ==== ==== 
        // 
        // CONSTRUCTORS - START

        Rooster();


        // CONSTRUCTORS - END
        // 
        // ==== ==== ==== ==== ==== ==== ==== ==== 
        // 
        // MEMBER FUNCTIONS - START


        //void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
        void add2(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3);

        void remove(string studentID);

        void printAll();

        void printAverageDaysInCourse(string studentID);

        void printInvalidEmails();

        //void printByDegreeProgram(DegreeProgram degreeProgram);


        // MEMBER FUNCTIONS - END
        // ==== ==== ==== ==== ==== ==== ==== ==== 
    };

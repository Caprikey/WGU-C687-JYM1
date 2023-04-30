#pragma once
#include "degree.h"
#include "student.h"


using namespace std;

// Roster Header

class Roster {

    private:

        Student **classRosterArray;
        int numStudents = 5;

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
        
        // Add Function With All But Enumerated Data Type Parameters
        void add2(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3);

        void remove(string studentID);

        void printAll();

        void printAverageDaysInCourse(string studentID);

        void printInvalidEmails();

        void printByDegreeProgram(DegreeProgram degreeProgram);

        Student* getStudent(int i);

        // MEMBER FUNCTIONS - END
        // ==== ==== ==== ==== ==== ==== ==== ==== 
};

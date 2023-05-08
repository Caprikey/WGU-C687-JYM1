// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
// 
// STUDENT HEADER - START
//
// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
//
// LIBRARY - START
// 

#pragma once
#include "degree.h"


#include <iostream>
#include <string>

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
// Student Header

class Student {

    //
    // ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
    //
    // PRIVATE SECTION - START 
    // 

	private:

        // 
        // ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
        // 
		// VARIALBES - START

			// Student ID
            string studentID = "";
		
			// Student First Name
			string firstName = "";
			
			// Student Last Name
			string lastName = "";

			// Student Email Address
			string emailAddress = "";

			// Student's Age
			int age = 0;

			// Days In Courses Array, 3 Values
			int daysInCourse[3] = { 0,0,0 };

            // Degree Program Enumerated Variable. 
            DegreeProgram degreeProgram = DegreeProgram::NETWORK;


        //
		// VARIABLES - END
        // 
        // ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
        // 


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
        // MUTATORS - START
        //

        void setStudentID(string studentID);

        void setStudentFirstName(string firstName);

        void setStudentLastName(string lastName);

        void setStudentEmailAddress(string emailAddress);

        void setStudentAge(int age);

        void setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3);

        void setDaysInCourse(int daysInCourse[]);

        void setStudentDegreeProgram(DegreeProgram degreeProgram);


		// MUTATORS - END
        // 
        // ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
        //
		// ACCESSORS - START
        // 

        string getStudentID();

        string getStudentFirstName();

        string getStudentLastName();

        string getStudentEmailAddress();

        int getStudentAge();

        int* getStudentDaysInCourse();

        DegreeProgram getStudentDegreeProgram();

		// ACCESSORS - END
        // 
        // ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
        //
		// MEMBER FUNCTIONS - START

        void print();

		// MEMBER FUNCTIONS - END
        // 
        // ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
        //
        // CONSTRUCTORS - START

        // Default Constructor
        Student();

        // Paramaterized Constructor(s)
        // Constructor - Takes All Parameters -- Requirement D, Number 2, Part d
        Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram);


        // CONSTRUCTORS - END
        // 
        // ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
        //
        // DECONSTRUCTORS - START

        // Default Constructor
        ~Student();

        // DECONSTRUCTORS - END
        // 
        // ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
        //
        // PUBLIC SECTION - END
        // 
        // ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
        //

};

//
// STUDENT HEADER - END
//
// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 
// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== 


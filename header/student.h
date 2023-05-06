#pragma once
#include "degree.h"


#include <iostream>
#include <string>

using namespace std;


class Student {

	private:

        // ==== ==== ==== ==== ==== ==== ==== ==== 
		// Variables

            // TODO: RESET ALL VARIALBES
            
			// Student ID
            //string studentID = "";
            string studentID = "C1";
		
			// Student First Name
			//string firstName = "";
			string firstName = "Charles";
			
			// Student Last Name
			//string lastName = "";
			string lastName = "CunningHam";

			// Student Email Address
			//string emailAddress = "";
			string emailAddress = "CunningCharlie@Change Test.edu";

			// Student's Age
			//int age = 0;
			int age = 31;

			// Days In Courses Array, 3 Values
			//int daysInCourse[3] = { 0,0,0 };
			int daysInCourse[3] = { 40,39,26 };

            // Degree Program Enumerated Variable. 
            DegreeProgram degreeProgram = DegreeProgram::NETWORK;
		
		
            // TODO: DELETE THIS
			// Probably need to delete and do it in real time instead. 
			// Input Data Array 
			// string arrayInputData;

        //
		// VARIABLES - END
        // ==== ==== ==== ==== ==== ==== ==== ==== 


	public:

        //
        // ==== ==== ==== ==== ==== ==== ==== ==== 
        // 
		// MUTATORS - START

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
        // ==== ==== ==== ==== ==== ==== ==== ==== 
        // 
		// ACCESSORS - START

        string getStudentID();

        string getStudentFirstName();

        string getStudentLastName();

        string getStudentEmailAddress();

        int getStudentAge();

        int* getStudentDaysInCourse();

        DegreeProgram getStudentDegreeProgram();

		// ACCESSORS - END
        // 
        // ==== ==== ==== ==== ==== ==== ==== ==== 
        // 
		// MEMBER FUNCTIONS - START

        void print();

		// MEMBER FUNCTIONS - END
        // 
        // ==== ==== ==== ==== ==== ==== ==== ==== 
        // 
        // CONSTRUCTORS - START

        // Default Constructor
        Student();

        // Paramaterized Constructor(s)
        // Constructor - Takes All Parameters -- Requirement D, Number 2, Part d
        Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram);


        // CONSTRUCTORS - END
        // 
        // ==== ==== ==== ==== ==== ==== ==== ==== 
        // 
        // ==== ==== ==== ==== ==== ==== ==== ==== 
        // 
        // DECONSTRUCTORS - START

        // Default Constructor
        ~Student();

        // DECONSTRUCTORS - END
        // 
        // ==== ==== ==== ==== ==== ==== ==== ==== 
};

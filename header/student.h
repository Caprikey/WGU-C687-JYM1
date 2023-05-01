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
            string studentID = "B1";
		
			// Student First Name
			//string firstName = "";
			string firstName = "Bravo";
			
			// Student Last Name
			//string lastName = "";
			string lastName = "Besterson";

			// Student Email Address
			//string emailAddress = "";
			string emailAddress = "BravoBesterson@Bestie Testers.co";

			// Student's Age
			//int age = 0;
			int age = 34;

			// Days In Courses Array, 3 Values
			//int daysInCourse[3] = { 0,0,0 };
			int daysInCourse[3] = { 10,8,31 };

            // TODO: DELETE THIS -- Will Be capturing and entering during calls/runtime
			// Need To Delete These Variables, and input the information directly in to the array
				
				// Days In Course 1
				int daysInCourse1 = 0;
			
				// Days In Course 1
				int daysInCourse2 = 0;
			
				// Days In Course 1
				int daysInCourse3 = 0;


		// Degree Program Enumerated Variable. 
                DegreeProgram degreeProgram = DegreeProgram::SOFTWARE;
		
		
            // TODO: DELETE THIS
			// Probably need to delete and do it in real time instead. 
			// Input Data Array 
			string arrayInputData;


		// VARIABLES - END
        // ==== ==== ==== ==== ==== ==== ==== ==== 


	public:
        // ==== ==== ==== ==== ==== ==== ==== ==== 
		// MUTATORS - START

        void setStudentID(string studentID);

        void setStudentFirstName(string firstName);

        void setStudentLastName(string lastName);

        void setStudentEmailAddress(string emailAddress);

        void setStudentAge(int age);

        void setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3);

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
        // ==== ==== ==== ==== ==== ==== ==== ==== 
        // 
        // CONSTRUCTORS - START

        // Default Constructor
        Student();

        // TODO: Need To Create A constructor that will add all details on call
        // Constructor - 2d
        Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);


        // CONSTRUCTORS - END
        // 
        // ==== ==== ==== ==== ==== ==== ==== ==== 
};

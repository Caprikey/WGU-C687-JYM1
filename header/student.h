#pragma once
#include "degree.h"


#include <iostream>
#include <string>

using namespace std;


class Student {

	private:

        // ==== ==== ==== ==== ==== ==== ==== ==== 
		// Variables

			// Student ID
            //string studentID = "";
            string studentID = "Testing";
		
			// Student First Name
			//string firstName = "";
			string firstName = "Tester";
			
			// Student Last Name
			//string lastName = "";
			string lastName = "Testerson";

			// Student Email Address
			//string emailAddress = "";
			string emailAddress = "Test@TestieTesters.co";

			// Student's Age
			//int age = 0;
			int age = 34;

			// Days In Courses Array, 3 Values
			//int daysInCourse[3] = { 0,0,0 };
			int daysInCourse[3] = { 10,8,31 };


			// Need To Delete These Variables, and input the information directly in to the array
				
				// Days In Course 1
				int daysInCourse1 = 0;
			
				// Days In Course 1
				int daysInCourse2 = 0;
			
				// Days In Course 1
				int daysInCourse3 = 0;


			// Need To Delete This Variable and calculated it in realtime

				// Average Day In Course
				double AverageDaysInCourse = 0.00;

		// Degree Program Enumerated Variable. 
                DegreeProgram degreeProgram = DegreeProgram::SOFTWARE;
		
		

			// Probably need to delete and do it in real time instead. 
			// Input Data Array 
			string arrayInputData;


		// VARIABLES - END
        // ==== ==== ==== ==== ==== ==== ==== ==== 


	public:
        // ==== ==== ==== ==== ==== ==== ==== ==== 
		// MUTATORS - START

        void setStudentID(string);

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

        // CONSTRUCTORS - END
        // 
        // ==== ==== ==== ==== ==== ==== ==== ==== 
};

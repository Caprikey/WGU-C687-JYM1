#pragma once


class Student {

	private:

		// Variables

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
		DegreeProgram degreeProgram = DegreeProgram::SECURITY;
		
		

			// Probably need to delete and do it in real time instead. 
			// Input Data Array 
			string arrayInputData;


		// VARIABLES - END



	public:

		// CONSTRUCTORS - START

		Student();


		// CONSTRUCTORS - END

		// MUTATORS - START






		// MUTATORS - END

		// ACCESSORS - START




		// ACCESSORS - END


		// MEMBER FUNCTIONS - START


		// MEMBER FUNCTIONS - END

};

#include "..\header\rooster.h"
#include "..\header\student.h"

using namespace std;

// Rooster Class


/*
public void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
    // Sets the instance variables from Part D1 and updates the rooster
*/

/*
void Rooster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {

};
*/

void Rooster::add2(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3) {


};

/*
public void remove(string studentID)
    // Removes a student from the rooster by Student Id.
    // If studentID does not exist, print an error message indicating the student was not found.
*/
void Rooster::remove(string studentID) {



};



/*
public void printAll()
//
//	* Prints a Tabs-Seperated List of the Student Data in the following format :
//	* A1 [Tab] First Name: John [Tab] Last Name: Smith [Tab] Age: 20 [Tab] daysInCourse {35, 40, 55} [Tab]? Degree Program: Security
//	* Needs to loop throught all students in the classRosterArray and calls the print() function for each student
//	*
//
*/

void Rooster::printAll() {

};


/*
print void printAverageDaysInCourse(string studentID)
    // Prints a Student's average number of days in the three courses.
*/

void Rooster::printAverageDaysInCourse(string studentID) {

};

/*
public void printInvalidEmails()
    // Verifies student email addresses and displays all invalid email addresses to the user.
    // Email addresses are valid if they contain an at ('@') symbol and a period ('.') and do not contain any spaces (' ').
*/

void Rooster::printInvalidEmails() {

};

/*
public void printByDegreeProgram(DegreeProgram degreeProgram)
    // Prints out all student information for the degree program specified by the degree program enumerated type.
*/

/*
void Rooster::printByDegreeProgram(DegreeProgram degreeProgram) {

};
*/

Rooster::Rooster() {

    classRoosterArray = new Student * [numStudents];

    for (int i = 0; i < numStudents; i++) {
        classRoosterArray[i] = nullptr;
    }

    for (int i = 0; i < numStudents; ++i) {
        classRoosterArray[i] = new Student();
    }







}

    /*
    int i, jyx;
    string parseInputData;
    string parseInputData = studentData[i];
    */
    /*
    int* getDaysInCourseArray(Student daysInCourseArray) {
        return daysInCourseArray.getDaysInCourse();
    }
    */



//Rooster::Rooster() {

        /*
        parseInputData = studentData[i];
        stringstream inputStream(parseInputData);;
        jyx = 0;

        while (getline(inputStream, parseInputData, ',')) {
            //std::getline (parseTest2, parseTest2Temp, ",");

            variableParseArray2[jyx++] = parseInputData;

            // cout << parseTestObjTemp << endl;
        }

        */



    //}

    /*
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {

        this->setStudentID(studentID);
        this->setStudentFirstName(firstName);
        this->setStudentLastName(lastName);
        this->setStudentEmailAddress(emailAddress);
        this->setStudentAge(age);

        this->setStudentDaysInCourse1(daysInCourse1);
        this->setStudentDaysInCourse2(daysInCourse2);
        this->setStudentDaysInCourse3(daysInCourse3);

        this->addDaysToArray();
        this->getAverageDaysInCourse();

    */



    /*
    if (variableParseArray2[8] == "NETWORK") {
        this->setStudentDegreeProgram(DegreeProgram::NETWORK);
    }
    else if (variableParseArray2[8] == "SECRUITY") {
        this->setStudentDegreeProgram(DegreeProgram::SECURITY);
    }
    else {
        this->setStudentDegreeProgram(DegreeProgram::SOFTWARE);
    }

    */

    /*
    }
    */

    /*
    void add2(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3) {

        this->setStudentID(studentID);
        this->setStudentFirstName(firstName);
        this->setStudentLastName(lastName);
        this->setStudentEmailAddress(emailAddress);
        this->setStudentAge(age);

        this->setStudentDaysInCourse1(daysInCourse1);
        this->setStudentDaysInCourse2(daysInCourse2);
        this->setStudentDaysInCourse3(daysInCourse3);

        this->addDaysToArray();
        this->getAverageDaysInCourse();
    */
    /*
    if (variableParseArray2[8] == "NETWORK") {
        this->setStudentDegreeProgram(DegreeProgram::NETWORK);
    }
    else if (variableParseArray2[8] == "SECRUITY") {
        this->setStudentDegreeProgram(DegreeProgram::SECURITY);
    }
    else {
        this->setStudentDegreeProgram(DegreeProgram::SOFTWARE);
    }

    */

    /*
        cout << endl;
        cout << studentID << endl;
        cout << firstName << endl;
        cout << lastName << endl;
        cout << emailAddress << endl;
        cout << age << endl;
        cout << daysInCourse1 << endl;
        cout << daysInCourse2 << endl;
        cout << daysInCourse3 << endl;
        cout << getAverageDaysInCourse();
        cout << endl;


    }
    */

    /*
    void add3(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {

        this->setStudentID(studentID);
        this->setStudentFirstName(firstName);
        this->setStudentLastName(lastName);
        this->setStudentEmailAddress(emailAddress);
        this->setStudentAge(age);

        this->setStudentDaysInCourse1(daysInCourse1);
        this->setStudentDaysInCourse2(daysInCourse2);
        this->setStudentDaysInCourse3(daysInCourse3);

        this->addDaysToArray();
        this->getAverageDaysInCourse();
        this->setStudentDegreeProgram(degreeProgram);
    */
    /*
    if (variableParseArray2[8] == "NETWORK") {
        this->setStudentDegreeProgram(DegreeProgram::NETWORK);
    }
    else if (variableParseArray2[8] == "SECRUITY") {
        this->setStudentDegreeProgram(DegreeProgram::SECURITY);
    }
    else {
        this->setStudentDegreeProgram(DegreeProgram::SOFTWARE);
    }

    */
    /*
        cout << endl;
        cout << studentID << endl;
        cout << firstName << endl;
        cout << lastName << endl;
        cout << emailAddress << endl;
        cout << age << endl;
        cout << daysInCourse1 << endl;
        cout << daysInCourse2 << endl;
        cout << daysInCourse3 << endl;
        cout << getAverageDaysInCourse() << endl;

        if (degreeProgram == DegreeProgram::NETWORK) {
            cout << "NETWORK";
        }
        else if (degreeProgram == DegreeProgram::SOFTWARE) {
            cout << "SOFTWARE";
        }
        else if (degreeProgram == DegreeProgram::SECURITY) {
            cout << "SECURITY";
        }
        else {
            cout << "ERROR";
        }

        cout << endl;
    }

    */
    /*
    void remove(string studentId) {



        bool isFound = false;
        int i = 0;

        for (int i = 0; i < 5; i++) {

            if (this[i].getStudentID() == studentId) {

                isFound = true;
                cout << "Student Object Was Located In Array Position: " << i << endl << endl;
                break;
            }

            cout << "Student Object Was NOT In Array Position: " << i << endl << endl;

        }
    */
    /*
    }
    */


    /*
    void printAllStudents() {

        for (int i = 0; i < 5; i++) {

            this[i].print();
    */
    /*
    std::cout << "---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----" << endl;
    std::cout << "---- ---- --Student Details-- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----" << endl;
    std::cout << "---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----" << endl << endl;

    std::cout << this[i].getStudentID() << "\t";
    std::cout << "First Name: " << this[i].getStudentFirstName() << "\t";
    std::cout << "Last Name: " << this[i].getStudentLastName() << "\t";
    std::cout << "Age: " << this[i].getStudentAge() << "\t";

    std::cout << "daysInCourse: {";
    for (int i = 0; i < 3; i++) {
        if (i != 2) {
            std::cout << this[i].getDaysInCourseArray(this[i])[i] << ", ";
        }
        else {
            std::cout << this[i].getDaysInCourseArray(this[i])[i];
        }
    }
    std::cout << "} ";

    std::cout << "Degree Program: ";

    if (this[i].getStudentDegreeProgram() == DegreeProgram::NETWORK) {
        cout << "NETWORK";
    }
    else if (this[i].getStudentDegreeProgram() == DegreeProgram::SOFTWARE) {
        cout << "SOFTWARE";
    }
    else if (this[i].getStudentDegreeProgram() == DegreeProgram::SECURITY) {
        cout << "SECURITY";
    }
    else {
        cout << "ERROR";
    }


    std::cout << endl;
    std::cout << "---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----" << endl;
    std::cout << "---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----" << endl;
    std::cout << "---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----" << endl << endl;
    */


    /*
    }
    */

    /*
            }
    */
    /*
                void printAverageDaysInCourse(string studentID) {

                }

                void printInvalidEmails() {



                }

                void printByDegreeProgram(DegreeProgram degreeProgram) {


                }
                */

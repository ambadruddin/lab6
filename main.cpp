#include <iostream>
#include <string>
#include <mutex>
#include "Student.h"
#include "Enroll.h"
#include "Catalog.h"


using namespace std;

//CAESAR database
Catalog CAESAR;
mutex mtx;

void populate_db(); // function declaration
void run_two_tests(); // function declaration

int main() {
    populate_db();
    CAESAR.print_catalog();

    //run_two_tests();
    //CAESAR.print_catalog();
}

void populate_db() // function definition
{
    //Construct Students
    Student s_1("Miguel", 22, "EECS");
    Student s_2("Tina", 20, "Math");
    Student s_3("Mike", 18, "Chemical Engineering");
    Student s_4("Amaan", 18, "Industrial Engineering");
    Student s_5("Evan", 19, "Industrial Engineering");

    //Add Students
    CAESAR.add_student(s_1);
    CAESAR.add_student(s_2);
    CAESAR.add_student(s_3);
    CAESAR.add_student(s_4);
    CAESAR.add_student(s_5);

    //Construct Courses
    Course algorithms(333, "EECS", "Algo");
    Course programming(230, "EECS", "Program");
    Course algebra(101, "Math", "Easy");
    Course optimization(313, "IE", "Deterministic Models");

    //Add Courses
    CAESAR.add_course(algorithms);
    CAESAR.add_course(programming);
    CAESAR.add_course(algebra);
    CAESAR.add_course(optimization);

    //Construct Enrollments
    Enroll e(s_1,algorithms, 3.9);
    Enroll e2(s_1,programming, 2.1);
    Enroll e3(s_1,algebra, 3);
    Enroll e4(s_2,algorithms, 3.5);
    Enroll e5(s_3,algorithms, 3.0);
    Enroll e6(s_4,optimization, 1.0);
    Enroll e7(s_5,optimization, 4.0);

    //Add Enrollments
    CAESAR.add_enrollment(e);
    CAESAR.add_enrollment(e2);
    CAESAR.add_enrollment(e3);
    CAESAR.add_enrollment(e4);
    CAESAR.add_enrollment(e5);
    CAESAR.add_enrollment(e6);
    CAESAR.add_enrollment(e7);
}

void run_two_tests()
{
    //Will work once implementation of compute_gpa() completed
    Student s = CAESAR.retrieve_student(0);
    double gpa = s.compute_gpa();
    cout << s.name << " has gpa of " << gpa << endl;

    //Attempt to add a course that's not in CAESAR to an enrollment -- will fail once invariant check implemented
    //Course econometrics(110, "ECON");
    //CAESAR.add_course(econometrics);
    //Enroll e(s,econometrics, 3.0);
    //CAESAR.add_enrollment(e);
}
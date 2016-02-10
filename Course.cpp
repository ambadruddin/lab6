
#include "Course.h"

//constructors
Course::Course(){};
Course::Course(int c, string d, string n):cid(c), dept(d), name(n){}; //modify constructor and add default value, or add new constructor

//overloaded '<<' operator
ostream & operator<<(ostream & o, Course & c)
{
    o << "department: " << c.dept << "; number: "<< c.cid << "; name: " << c.name;

    return o;
}

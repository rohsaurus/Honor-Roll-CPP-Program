#include "student.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

student::student()
{
    
}


bool student::disiplineIssue()
{
    // Max the random integer can go
   int max = 100;
   srand(time(0));
   int random = rand()%max;

    // bool variable for returning
    bool True_or_False = false;
   if (random <= 5)
   {
       True_or_False = true;
   }
   return True_or_False;    
}

ostream& operator<< (ostream& output, const student& aStudent) {
    
    output << aStudent.studentName << " ";
    if (aStudent.hasDisciplineIssue) {
        output << "has ";
    }
    else {
        output << "doesn't have ";
    }
    output << "a discipline issue";
    return output;
}

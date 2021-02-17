#pragma once
#include <iostream>
#include <string>


class student
{

    // stores user full name
    std::string full_name;

    // name size is variable that contains the length of the full name
    int name_size;

    // stores amount of courses user is taking in a string to check if user inputted integer or not
    std::string courses;

    // converted string to integer
    int courses_int;

    // Max grade constant

    int MAX_GRADE = 120;
    
public:
void collectingUserData();
void honor_roll_eligibility_checker();
student();
private:
void userName();
 void courses_enrolled_in();



};

﻿#pragma once
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

    // course name array

    std::string classes[8];

    // grades array
    int grades [8];

    // mean of all courses

    // Made double to preseve number for rounding
    double mean_pre_rounded;
    int mean;


    // discipline issue?
    std::string discipline_issue;
    
public:
void collectingUserData();
void honor_roll_eligibility_checker();
student();
private:
void userName();
void courses_enrolled_in();
void course_names();
void course_grades();
void mean_grade();
void discipline_issue_method();



};

#pragma once
#include <iostream>
class student
{
public:
    student();
    std::string settingStudentName;
    bool disiplineIssue();

    // provided again so you learn this valuable override method for printing class data.
    friend std::ostream& operator << (std::ostream&, const student &);

private:
    std::string studentName;
    bool hasDisciplineIssue;
};

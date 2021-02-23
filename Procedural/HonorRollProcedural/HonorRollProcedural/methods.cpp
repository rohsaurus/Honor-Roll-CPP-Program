#include "methods.h"


#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;

// Method that will take user input and store each into an array
void honor_roll_eligibility_checker(int number,string name)
{
    int MAX_GRADE = 120;
    // Variables and while loops to store classes in an array
    string classes[8];
    string course_name_input;
    int j = 0;
    // Clearing cin but need it done only once
    cin.ignore();
    // Run until user enters amount that corresponds with number of courses
    while (true) 
    {
        if (j >= number)
        {
            break;
        }
        j++;
        // error checking to make sure user inputs course name less than 20
        do 
        {
            cout << "Enter a course name. It must be greater than 0 characters and less than 20 characters.\n";
            
            getline(cin,course_name_input);
            if (course_name_input.length() > 20 || course_name_input.length() == 0)
            {
                cout << "You entered a course that either has 0 characters or more than 20. Please try again\n";
            }
            else
            {
                cout << "The course name fits the criteria.\n";
                classes[j - 1] = course_name_input;
            }
        } while (course_name_input.length() > 20 || course_name_input.length() <=0);
    }

    // Grades for each class

    int grades[8];

    for (int o = 0; o < number; o++)
    {
        // checking if negative or non integer or above max
        int count = 0;
        do
        {
            // test condition to check for int status works for strings and doubles
            cout << "Enter your grade for class " << classes[o] << ". It must be greater than 0 and no more than " << MAX_GRADE << ". Also it must not be a negative number and must be an integer.\n If you are seeing this again, then you have failed one of these conditions.\n\n";
            string tempary = "";
            getline(cin,tempary);
            int triggered = 0;

            // Iteratres to every character checking if it is a digit or not
            // this deduces whether user inputted integer or something else
            for (int p = 0; p < tempary.length(); p++) 
            {
                if (isdigit(tempary[p]) == false) 
                {
                    count=1;
                    triggered = 1;
                }
                else
                    count=0;
     
            } if(count==0)
            {
                //cout << "Number inputted is an Integer\n";
                grades[o] = std::stoi(tempary);
                if (grades[o] >= 1 && grades[o] <= 8)
                {
                  cout << "";
                }
            }
  
            else
                cout << " ";
            if (triggered == 1)
            {
                cout << "You can not enter a string or a double.\n";
                count = 1;
            }
            // Checking if number is negative or above max grade
            if (grades[o] < 0)
            {
                cout << "You can't have a negative grade.\n Please enter a positive integer\n";
                count = 1;
            }
            if (grades[o] > MAX_GRADE)
            {
                cout << "You can not have a grade greater than " << MAX_GRADE << ". Please fix your input\n";
                count = 1;
            }
        } while (count == 1);
    }

    // Figuring out the overall Grade Average
    double added_up = 0;
    for (int w = 0; w < number; w++)
    {
        double transfer = grades[w];
        added_up = added_up + transfer;
    }
    double mean_pre_rounded;
    mean_pre_rounded = added_up/number;
    int mean = round(mean_pre_rounded);

    // 5% chance for disicpline issue
    int max;
    max = 100; //set the upper bound to generate the random number
    srand(time(0));
    int chance = rand()%max;
    string discipline_issue = " ";
    if (chance <= 5)
    {
        discipline_issue = "yes";
    }
    else
    {
        discipline_issue = "no";
    }
    cout << discipline_issue << endl;
    // Checking for honor roll eligbiity
    bool honor_roll_eligbility = false;
    if (mean >= 90 && number >= 5 && discipline_issue == "no")
    {
        honor_roll_eligbility = true;
    }
    else
    {
        honor_roll_eligbility = false;
    }
    
    cout << endl << endl;
    cout << name << endl;
    printf("%-20s%-5s\n", "Class", "Grade");
    for (int i = 0; i < number; i++) {
        string first = classes[i];
        int second = grades[i];
        string second_as_string;
        second_as_string = second;
        printf("%-20s%-5d \n", first.c_str(), second);
    }
    cout << endl;
    cout << endl << "Average: " << mean << endl;

    cout << "Disciplinary Infraction: " << discipline_issue << endl;

    // Printing if elgiable for honor roll or not\

    if (honor_roll_eligbility == true)
    {
        cout << "Congratulations "<< name << "! You have made the honor roll.\n";
    }
    else
    {
        cout << "I'm sorry " << name << " but you didn't qualify for honor roll\n";
    }
}

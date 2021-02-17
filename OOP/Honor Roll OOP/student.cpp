#include "student.h"
#include <cstdlib>
#include <ctime>
using namespace std;

// Constructor Method
student::student()
{
    
}
// Public methods

void student::honor_roll_eligibility_checker()
{
    // Variables and while loops to store classes in an array
    string classes[8];
    string course_name_input;
    int j = 0;
    // Clearing cin but need it done only once
    cin.ignore();
    // Run until user enters amount that corresponds with number of courses
    while (true) 
    {
        if (j >= courses_int)
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

    for (int o = 0; o < courses_int; o++)
    {
        // checking if negative or non integer or above max
        int count = 0;
        do
        {
            // test condition to check for int status works for strings and doubles
            cout << "Enter your grade for class " << classes[o] << ". It must be greater than 0 and no more than " << MAX_GRADE << ". Also it must not be a negative number and must be an integer.\n If you are seeing this again, then you have failed one of these conditions.\n\n";
            string tempary = "";
            cin >> tempary;
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
                cout << "You can't have a negative grade.\n Please enter a positive integer";
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
    int added_up = 0;
    for (int w = 0; w < courses_int; w++)
    {
        int transfer = grades[w];
        added_up = added_up + transfer;
    }
    int mean = added_up/courses_int;


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
    if (mean >= 90 && courses_int >= 5 && discipline_issue == "no")
    {
        honor_roll_eligbility = true;
    }
    else
    {
        honor_roll_eligbility = false;
    }
    
    cout << endl << endl;
    cout << full_name << endl;
    printf("%-20s%-5s\n", "Class", "Grade");
    for (int i = 0; i < courses_int; i++) {
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
        cout << "Congratulations "<< full_name << "! You have made the honor roll.\n";
    }
    else
    {
        cout << "I'm sorry " << full_name << " but you didn't qualify for honor roll\n";
    }
}
void student::collectingUserData()
{
    // Method to collect user name
    student::userName();
    
    // Method to see how many courses user is enrolled in as well as checkign to make sure they fit parametrs
    student::courses_enrolled_in();
    
}


// Private Methods
void student::userName()
{
    cout << "Enter your full name\n";
    getline(cin, full_name);
    // if character length is 0,then it will ask user to enter their name
    name_size = full_name.length();
    if (name_size == 0)
    {
        while (name_size == 0)
        {
            cout << "You entered nothing. Please enter your name\n";
            getline (cin, full_name);
            name_size = full_name.length();
        }
    }

    // If character length is 1, will ask user for confirmation


    string choice;
  
    if (name_size == 1)
    {
        cout << "Are you sure that you entered your name correct? It has a length of one chracter\n" << full_name << endl;
        cout << "Enter yes if you are sure and no if you want to correct it\n";
        // Extra Thing (allows user to correct input if they have 1 character)
        getline(cin, choice);
        if (choice == "no")
        {
            cout << "Enter your full name\n";
            getline (cin,full_name);
        }
        else
        {
            cout << "Your name will be used in the program\n";
        }
    }
}

void student::courses_enrolled_in()
{
    int i = 0;
    int count = 0;
    while (true)
    {
        // test condition to check for int status works for strings and doubles
        cout << "How many courses do you want to take?\n If this is not the first time you are seeing this prompt,\n that means you entered a faulty input. Enter a number \n between 1 and 8.";
        cin >> courses;

        // Iteratres to every character checking if it is a digit or not
        // this deduces whether user inputted integer or something else
        for (i = 0; i < courses.length(); i++) 
        {
            if (isdigit(courses[i]) == false) 
            {
                count=1;
                break;
            }
            else
                count=0;
     
        } if(count==0)
        {
           // cout << "Number inputted is an Integer\n";
            courses_int = std::stoi(courses);
            if (courses_int >= 1 && courses_int <= 8)
            {
                break;
            }
        }
  
        else
            cout << " ";
    }
}

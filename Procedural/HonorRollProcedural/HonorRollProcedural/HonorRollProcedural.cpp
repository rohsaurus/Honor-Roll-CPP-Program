/**
 * Rohan Parikh
 * Honor Roll Procedural
 * 5 February 2021 - 8 Febuary 2021
 * Extra Thing: Allows user to correct input if they have only one character for name
*/
#include <string>
#include "methods.h"
using namespace std;

// Global variables for this file only
int temp;

int main(int argc, char* argv[])
{   
    string full_name;

    cout << "Enter your full name\n";
    getline(cin, full_name);
    // if chracter length is 0,then it will ask user to enter their name
    int name_length = full_name.length();
    if (name_length == 0)
    {
        cout << "You entered nothing. Please enter your name\n";
        getline (cin, full_name);
    }

    // If character length is 1, will ask user for confirmation

    // Variable for full name length

    string choice;
  
  
        if (name_length == 1)
        {
            cout << "Are you sure that you entered your name correct? It has a length of one chracter\n" << full_name << endl;
            cout << "Enter yes if you are sure and no if you want to correct it\n";
            // Extra Thing (allows user to correct input if they have 1 character)
            getline(cin, choice);
            if (choice == "yes")
            {
               cout << "Enter your full name\n";
                getline (cin,full_name);
            }
            else
            {
                cout << "Your name will be used in the program\n";
            }
         }

    // Taking amount of courses user is enrolled in
    string courses = "";
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
            cout << "";
            temp = std::stoi(courses);
            if (temp >= 1 && temp <= 8)
            {
                break;
            }
        }
  
        else
            cout << "";
    }
    // Method that checks to see if student is eligbile for honor roll
    honor_roll_eligibility_checker(temp,full_name);

    return 0;
}

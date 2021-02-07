// HonorRoll1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Desribed using a METHOD so I need a fake class


#include <iostream>
#include <string>
#include "student.h"
using namespace std;

int main()
{
	double numRuns = 0;
	double issue = 0;
	double noIssue = 0;
	string runAgain = "y";
	
	student someStudent = student("Mary");
	do{
		++numRuns;
		if (someStudent.disiplineIssue()) {
			++issue;
		}
		else {
			++noIssue;
		}
		cout << "Run again ('n' to quit)? You have run " << numRuns << " times\n";
		getline(cin,runAgain);
	} while (runAgain != "n");
	cout << "Number of runs: " << numRuns << endl; 
	cout << "True Count: " << issue << endl;
	cout << "False Count: " << noIssue << endl;
	cout << "% of time a discipline issue was generated: " << (issue / numRuns) * 100 << endl;
	cout << someStudent; 
}

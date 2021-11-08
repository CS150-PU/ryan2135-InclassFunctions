//**********************************************************************
// File:       main.cpp
// Author:     CS, Pacific University
// Date:       11/8/21
// Class:      CS 150-01
// Assignment: In class Arrays and Functions
// Purpose:    Gain more experience with functions, arrays, and passing
//						 arrays to functions 
// Hours:
//**********************************************************************

#include <iostream>
#include <fstream>

using namespace std;

/***********************************************************************
Function:     main

Description:  Performs some calculations on points as described in the
							program's purpose.

Parameters:   None

Returned:     Exit Status
***********************************************************************/
int main () {
	const int MAX_SCORES = 100;

	ifstream inFile;
	double examScores[MAX_SCORES];
	int numScores = 0;

	inFile.open ("examScores.txt");
	if (inFile.fail ()) {
		cout << "Error opening file" << endl << endl;
		exit (EXIT_FAILURE);
	}
	// call function to read all exam scores

	// call function to print each exam score

	// call function to print the average of all exam scores

	inFile.close ();

	return EXIT_SUCCESS;
}
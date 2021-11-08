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

// Have class write prototypes, definitions, and main after opening file

#include <iostream>
#include <fstream>

using namespace std;

const int MAX_SCORES = 10;

void readExamScores (double examScores[], int &numScores, 
										 ifstream &inFile);
void printExamScores (const double examScores[], int numScores);
double averageExamScores (const double examScores[], int numScores);

/***********************************************************************
Function:     main

Description:  Performs some calculations on points as described in the
							program's purpose.

Parameters:   None

Returned:     Exit Status
***********************************************************************/
int main () {
	ifstream inFile;
	double examScores[MAX_SCORES];
	int numScores = 0;

	inFile.open ("examScores.txt");
	if (inFile.fail ()) {
		cout << "Error opening file" << endl << endl;
		exit (EXIT_FAILURE);
	}
	// call function to read all exam scores
	readExamScores (examScores, numScores, inFile);

	// call function to print each exam score
	printExamScores (examScores, numScores);

	// call function to print the average of all exam scores
	cout << "Average of all scores is: "
		<< averageExamScores (examScores, numScores);

	inFile.close ();

	return EXIT_SUCCESS;
}

void readExamScores (double examScores[], int &numScores, 
										 ifstream &inFile) {
	const double SENTINEL = -99.0;
	double examScore;

	numScores = 0;

	inFile >> examScore;
	while (examScore != SENTINEL && numScores < MAX_SCORES) {
		examScores[numScores] = examScore;
		numScores++;
		inFile >> examScore;
	}

	if (MAX_SCORES == numScores && examScore != SENTINEL) {
		cout << "Error: Too many scores in the data file" << endl;
		exit (EXIT_FAILURE);
	}
}

void printExamScores (const double examScores[], int numScores) {
	for (int index = 0; index < numScores; index++) {
		cout << examScores[index] << endl;
	}
}

double averageExamScores (const double examScores[], int numScores) {
	double total = 0.0, average = 0.0;

	for (int index = 0; index < numScores; index++) {
		total += examScores[index];
	}

	if (numScores > 0) {
		average = total / numScores;
	}

	return average;
}
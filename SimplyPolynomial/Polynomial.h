#pragma once

class Polynomial
{
private:
	int validateInput(int min, int max);
	bool checkArray(int arr[], int size);

public:
	 struct term
	{
		int coefficient;
		int exponent;
	};

	void getInputs(term* t, int numberofTerms);
	void printTheExpresion(term* t, int n);
	int calculateDifference(int arr[],int &depth,int sizeOfArr);
	int findFactorial(int fact);
	int FindCoefficient(int arr[], int& depth, int sizeOfArr);
	void FindTheTerm(term* t,int arr[],int &depth, int sizeofArr,int i);
};




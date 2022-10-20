#pragma once

class Polynomial
{
private:
	int validateInput(int min, int max);
	bool checkArray(int arr[], int size);
	int calculateDifference(int arr[], int& depth, int sizeOfArr);
	int findFactorial(int fact);
	int FindCoefficient(int arr[], int& depth, int sizeOfArr);

public:
	 struct term
	{
		int coefficient;
		int exponent;
	};

	void getInputs(term* t, int numberofTerms);
	void printTheExpresion(term* t, int n);
	void FindTheExpression(term* t,int arr[],int &depth, int sizeofArr,int i);
};




#pragma once
#include <vector>
using namespace std;
class Polynomial
{
private:
	int validateInput(int min, int max);
	bool checkVector(vector<int> arr);
	int calculateDifference(vector<int> arr, int& depth);
	int findFactorial(int fact);
	int FindCoefficient(vector<int> arr, int& depth);

public:
	 struct term
	{
		int coefficient;
		int exponent;
	};

	void getInputs(term* t, int numberofTerms);
	void showTheOutputSet(int startNumber, int EndNumber, int numberOfTerms,term* t);
	void printTheExpresion(term* t, int n);
	void FindTheExpression(term* t,vector<int> arr,int &depth,int i);
};




#include "Polynomial.h"
#include <iostream>
#include <math.h>

using namespace std;

//int A[]{ 0, 14, 96, 300, 680, 1290, 2184, 3416, 5040, 7110, 9680, 12804, 16536, 20930, 26040, 31920,38624, 46206, 54720, 64220, 74760 };
int result[21];
//int depth = 1;

void Polynomial::getInputs(term* t,int numberofTerms)
{
	for (int i = 0; i < numberofTerms; i++)
	{
		cout << "Enter the exponent (0 to 4): " << "\n";
		t[i].exponent = validateInput(0, 4);
		
		if (t[i].exponent == 0)
		{
			cout << "Enter the Coefficient (-1000 to 1000): " << "\n";
			t[i].coefficient = validateInput(-1000, 1000);
		}
		else
		{
			cout << "Enter the Coefficient (-9 to 9): " << "\n";
			t[i].coefficient = validateInput(-9, 9);
		}
	}
}

int Polynomial::validateInput( int min, int max)
{
	int x;
	cin >> x;
	while (x < min || x > max)
	{
		cout << "Enter again :";
		cin >> x;
	}
	return x;
}

bool Polynomial::checkArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] != arr[0])
		{
			return false;
		}
	}
	return true;
}

void Polynomial::printTheExpresion(term* t, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (i != 0 && t[i].coefficient >= 0)
		{
			cout << "+";
		}
		cout << t[i].coefficient;

		if (t[i].exponent > 0)
		{
			cout << "x";
			cout << "^";
			cout << t[i].exponent;
		}
	}
}

int Polynomial::calculateDifference(int arr[],int &depth,int sizeOfArr)
{
	
	for (int i = 0; i <= sizeOfArr; i++)
	{
		result[i] = arr[i + 1] - arr[i];
	}
	sizeOfArr--;
	for (int i = 0; i < sizeOfArr; i++)
	{
		if (result[i] != result[i+1] && depth <= 4)
		{
			depth++;
			calculateDifference(result, depth, sizeOfArr);
		}
			
		else
			return result[0];
			
	}
	return 0;
}

int Polynomial::findFactorial(int num)
{
	int fact = 1;

	for (int i = 1; i <= num; i++)
	{
		fact = fact * i;
	}

	return fact;
	
}

int Polynomial::FindCoefficient(int arr[], int& depth, int sizeOfArr)
{
	//int sizeofArr = sizeof(arr) / sizeof(arr[0]);
	
	//cout << sizeofArr << "\n";
	int difference = calculateDifference(arr, depth, sizeOfArr);

	return difference / findFactorial(depth);
}

void Polynomial::FindTheTerm(term* t,int A[],int &depth,int sizeofArr,int termNo)
{
	//int sizeofArr = sizeof(A) / sizeof(A[0]);
	//int tempArr[21];

	while (!checkArray(A, sizeofArr))
	{
		t[termNo].coefficient = FindCoefficient(A, depth, sizeofArr);
		t[termNo].exponent = depth;
		depth = 1;

		for (int j = 0; j < sizeofArr; j++)
		{
			int term = t[termNo].coefficient * pow(j, t[termNo].exponent);
			A[j] = A[j] - term;
		}

		if (checkArray(A, sizeofArr))
		{
			return;
		}

		termNo++;
		FindTheTerm(t, A, depth, sizeofArr, termNo);
	}	
	
}

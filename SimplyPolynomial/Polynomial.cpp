#include "Polynomial.h"
#include <iostream>
#include <math.h>

using namespace std;

int result[21];

void Polynomial::getInputs(term* t,int numberofTerms)
{
	for (int i = 0; i < numberofTerms; i++)
	{
		cout << "Enter the exponent (0 to 4): " << "\n";
		t[i].exponent = validateInput(0, 4);
		
		if (t[i].exponent == 0)
		{
			cout << "Enter the Constant (-1000 to 1000): " << "\n";
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
	return calculateDifference(arr, depth, sizeOfArr) / findFactorial(depth);
}

void Polynomial::FindTheExpression(term* t,int A[],int &depth,int sizeofArr,int termNo)
{
		t[termNo].coefficient = FindCoefficient(A, depth, sizeofArr);
		t[termNo].exponent = depth;
		
		for (int j = 0; j < sizeofArr; j++)
		{
			A[j] = A[j] - t[termNo].coefficient * pow(j, t[termNo].exponent);
		}
		termNo++;
		if (checkArray(A, sizeofArr))
		{
			t[termNo].coefficient = A[0];
			return;
		}
		depth = 1;
		FindTheExpression(t, A, depth, sizeofArr, termNo);
}

#include "Polynomial.h"
#include <iostream>
#include <math.h>

using namespace std;

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

bool Polynomial::checkVector(vector<int> vec)
{
	for (int i = 0; i < vec.size() - 1; i++)
	{
		if (vec.at(i + 1) != vec.at(i))
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

int Polynomial::calculateDifference(vector<int> vec,int &depth)
{
	vector<int> tempVec;
	int difference = 0;
	for (int i = 0; i < vec.size() - 1; i++)
	{
		tempVec.push_back(vec.at(i+1) - vec.at(i));
	}
	difference = tempVec[0];
	if (!checkVector(tempVec) && depth <= 4)
	{
		depth++;
		difference = calculateDifference(tempVec, depth);
	}
	
	return difference;
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

int Polynomial::FindCoefficient(vector<int> vec, int& depth)
{
	return calculateDifference(vec, depth) / findFactorial(depth);
}

void Polynomial::FindTheExpression(term* t,vector<int> vec,int &depth,int termNo)
{
		t[termNo].coefficient = FindCoefficient(vec, depth);
		t[termNo].exponent = depth;
		
		for (int j = 0; j < vec.size(); j++)
		{
			vec[j] = vec.at(j) - t[termNo].coefficient * pow(j, t[termNo].exponent);
		}
		termNo++;
		if (checkVector(vec))
		{
			t[termNo].coefficient = vec.at(0);
			return;
		}
		depth = 1;
		FindTheExpression(t, vec, depth, termNo);
}

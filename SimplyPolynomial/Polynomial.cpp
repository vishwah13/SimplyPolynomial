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

void Polynomial::printTheExpresion(term* t, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (i != 0 && t[i].coefficient > 0)
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

#include <iostream>
#include <math.h>

using namespace std;

typedef struct term
{
	int coefficient;
	int exponent;
};

void printTheExpresion(term *t, int n);

int main()
{
	int numberOfTerms,startNumber,Endnumber;

	cout << "Enter the number of terms: ";
	cin >> numberOfTerms;

	term *terms = new term[numberOfTerms];

	for (int i = 0; i < numberOfTerms; i++)
	{
		cout << "Enter the Coefficient: " << "\n";
		cin >> terms[i].coefficient;
		cout << "Enter the exponent: " << "\n";
		cin >> terms[i].exponent;
	}

	cout << "\n";

	printTheExpresion(terms, numberOfTerms);
	cout << "\n Enter the Start number: ";
	cin >> startNumber;
	cout << "Enter the Finish number: ";
	cin >> Endnumber;

	for (int i = startNumber; i <= Endnumber; i++)
	{
		int sum = 0;

		for (int j = 0; j < numberOfTerms; j++)
		{
			int exp = pow(i, terms[j].exponent);
			sum += terms[j].coefficient * exp;
		}
		cout << sum;
		if(i != Endnumber)
			cout << ",";
	}

	return 0;
}

void printTheExpresion(term *t, int n)
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
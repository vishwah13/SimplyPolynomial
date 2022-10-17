#include <iostream>

using namespace std;

typedef struct term
{
	int coefficient;
	int exponent;
};

void printTheExpresion(term *t, int n);

int main()
{
	int numberOfTerms = 0;

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
	printTheExpresion(terms, numberOfTerms);

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
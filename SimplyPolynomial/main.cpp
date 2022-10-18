#include "Polynomial.h"
#include "FileManager.h"
#include <iostream>

using namespace std;

int main()
{
	Polynomial ploynomial;
	FileManager file;

	int numberOfTerms, startNumber, EndNumber;

	cout << "Enter the number of terms: ";
	cin >> numberOfTerms;
	Polynomial::term* terms = new Polynomial::term[numberOfTerms];

	ploynomial.getInputs(terms, numberOfTerms);
	ploynomial.printTheExpresion(terms, numberOfTerms);

	cout << "\n Enter the Start number: ";
	cin >> startNumber;
	cout << "Enter the Finish number: ";
	cin >> EndNumber;
	file.writeTheOutputSet(startNumber, EndNumber, numberOfTerms, terms);
	file.readTheOutputSet();
	return 0;
}
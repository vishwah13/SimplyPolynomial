#include "Polynomial.h"
#include "FileManager.h"
#include <iostream>

using namespace std;

int A[]{ 0, 14, 96, 300, 680, 1290, 2184, 3416, 5040, 7110, 9680, 12804, 16536, 20930, 26040, 31920,38624, 46206, 54720, 64220, 74760 };
int depth = 1;

int main()
{
	Polynomial polynomial;
	FileManager file;

	/*int numberOfTerms, startNumber, EndNumber;

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
	file.readTheOutputSet();*/

	int sizeofArr = sizeof(A) / sizeof(A[0]);
	
	Polynomial::term* newTerms = new Polynomial::term[4]();
	polynomial.FindTheTerm(newTerms,A, depth, sizeofArr,0);
	polynomial.printTheExpresion(newTerms,4);

	return 0;
}
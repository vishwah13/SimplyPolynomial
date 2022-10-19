#include "Polynomial.h"
#include "FileManager.h"
#include <iostream>

using namespace std;

int A[]{ 0, 3, 24, 81, 192, 375, 648, 1029, 1536, 2187, 3000, 3993, 5184, 6591, 8232, 10125, 12288, 14739, 17496, 20577, 24000 };
int depth = 1;

int main()
{
	Polynomial polynomial;
	FileManager file;

	/*int numberOfTerms, startNumber, EndNumber;

	cout << "Enter the number of terms: ";
	cin >> numberOfTerms;
	Polynomial::term* terms = new Polynomial::term[numberOfTerms];

	polynomial.getInputs(terms, numberOfTerms);
	polynomial.printTheExpresion(terms, numberOfTerms);

	cout << "\n Enter the Start number: ";
	cin >> startNumber;
	cout << "Enter the Finish number: ";
	cin >> EndNumber;
	file.writeTheOutputSet(startNumber, EndNumber, numberOfTerms, terms);*/
	//file.readTheOutputSet();

	int sizeofArr = sizeof(A) / sizeof(A[0]);
	
	Polynomial::term* newTerms = new Polynomial::term[4]();
	polynomial.FindTheTerm(newTerms,A, depth, sizeofArr,0);
	polynomial.printTheExpresion(newTerms,4);

	return 0;
}
#include "Polynomial.h"
#include "FileManager.h"
#include <iostream>

using namespace std;

int A[]{ 7, 13, 17, 13, -5, -43, -107, -203, -337, -515, -743, -1027, -1373, -1787, -2275, -2843, -3497,
-4243, -5087, -6035, -7093};
int depth = 1;

int main()
{
	Polynomial polynomial;
	FileManager file;

	int numberOfTerms, startNumber, EndNumber;

	cout << "Enter the number of terms: ";
	cin >> numberOfTerms;
	Polynomial::term* terms = new Polynomial::term[numberOfTerms];

	polynomial.getInputs(terms, numberOfTerms);
	polynomial.printTheExpresion(terms, numberOfTerms);

	cout << "\n Enter the Start number: ";
	cin >> startNumber;
	cout << "Enter the Finish number: ";
	cin >> EndNumber;
	file.writeTheOutputSet(startNumber, EndNumber, numberOfTerms, terms);
	file.readTheOutputSet();

	int sizeofArr = sizeof(A) / sizeof(A[0]);
	
	Polynomial::term* newTerms = new Polynomial::term[5]();
	polynomial.FindTheExpression(newTerms,A, depth, sizeofArr,0);
	polynomial.printTheExpresion(newTerms,4);

	return 0;
}
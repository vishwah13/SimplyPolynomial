#include "Polynomial.h"
#include "FileManager.h"
#include <iostream>

using namespace std;

vector<int> A{ 114, 110, 100, 78, 38, -26, -120, -250, -422, -642, -916, -1250, -1650, -2122, -2672, -3306,
-4030, -4850, -5772, -6802, -7946 };
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
	file.writeTheOutputSet(startNumber, EndNumber, numberOfTerms, terms);
	file.readTheOutputSet();
	file.printResult();*/

	int sizeofArr = A.size();
	
	Polynomial::term* newTerms = new Polynomial::term[5]();
	polynomial.FindTheExpression(newTerms,A, depth,0);
	polynomial.printTheExpresion(newTerms,4);

	return 0;
}
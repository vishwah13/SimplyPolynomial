#include "Polynomial.h"
#include "FileManager.h"
#include <iostream>

using namespace std;

int Depth = 1;
int TermNo = 0;

void getExpression(FileManager file, Polynomial polynomial);
void useOutputSet(FileManager file, Polynomial polynomial);

int main()
{
	Polynomial polynomial;
	FileManager file;

	cout << "Provide your own expression (1)"<< "\n";
	cout << "Do you want to us output set ? (2)"<< "\n";
	int x;
	cout << "What is your choice:";
	cin >> x;

	switch (x)
	{
	case 1:
		getExpression(file,polynomial);
		break;
	case 2:
		useOutputSet(file,polynomial);
		break;
	default:
		break;
	}

	return 0;
}

void getExpression(FileManager file, Polynomial polynomial)
{
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
	cout << "\n";
	cout << "The outputs are:" << "\n";
	polynomial.startNo = startNumber;
	polynomial.showTheOutputSet(startNumber, EndNumber, numberOfTerms, terms);

	cout << "Do you want to save it ? (y/n):";
	char ans;
	cin >> ans;
	if (ans == 'y') 
	{
		file.writeTheOutputSetToFile(startNumber, EndNumber, numberOfTerms, terms);

		cout << "Do you want to see the ouput set (y/n):";
		char x;
		cin >> x;

		if(x == 'y')
			useOutputSet(file, polynomial);
	}
}

void useOutputSet(FileManager file, Polynomial polynomial)
{
	vector<int> vec = file.readTheOutputSetFromFile();
	Polynomial::term* newTerms = new Polynomial::term[5]();
	polynomial.FindTheExpression(newTerms, vec, Depth, TermNo);
	cout << "\n\n";
	cout << "The Expression is :";
	polynomial.printTheExpresion(newTerms, 4);
	cout << "\n";
	file.writeTheExpressionToFile(newTerms, 4);
}

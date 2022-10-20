#include "FileManager.h"
#include <iostream>
#include <vector>

using namespace std;

ifstream myfile("output.txt");

void FileManager::ClearFile(ofstream &file,string fileName)
{
	file.open(fileName);
	file << "";
	file.close();
}

void FileManager::writeTheOutputSet(int startNumber, int EndNumber, int numberOfTerms, Polynomial::term* t)
{
	ofstream outputFile;
	try
	{
		ClearFile(outputFile, "output.txt");
		outputFile.open("output.txt", ios::app);

		for (int i = startNumber; i <= EndNumber; i++)
		{
			int sum = 0;

			for (int j = 0; j < numberOfTerms; j++)
			{
				int exp = pow(i, t[j].exponent);
				sum += t[j].coefficient * exp;
			}
			outputFile << sum;

			if (i != EndNumber)
				outputFile << ",";
		}
	}
	catch(ofstream::failure& e)
	{
		cerr << "Error Opening and Writing the file";
	}
	outputFile.close();
}

vector<int> FileManager::readTheOutputSet()
{
	vector<int> vec;
	try
	{
		if (myfile.is_open())
		{
			while (!myfile.eof() && ((char)myfile.peek()) != '\n')
			{
				char t;
				int n;
				myfile >> n >> t;
				vec.push_back(n);
				t = '\n';
			}
			myfile.close();
		}
		return vec;
	}
	catch (ifstream::failure e)
	{
		cout << "Unable to open file and read";
	}
}

void FileManager::printResult(vector<int> vec)
{
	for (auto it = begin(vec); it != end(vec); it++) {
		cout << *it << ",";
	}
}

void FileManager::writeTheExpressionToFile(Polynomial::term* t, int numberOfTerm)
{
	ofstream expressionFile;
	try
	{
		ClearFile(expressionFile, "ExpressionFile.txt");
		expressionFile.open("ExpressionFile.txt");

		for (int i = 0; i < numberOfTerm; i++)
		{
			if (t[i].coefficient == 0 && t[i].exponent == 0) return;

			if (i != 0 && t[i].coefficient >= 0)
			{
				expressionFile << "+";
			}
			expressionFile << t[i].coefficient;

			if (t[i].exponent > 0)
			{
				expressionFile << "x";
				expressionFile << "^";
				expressionFile << t[i].exponent;
			}
		}
	}
	catch(ofstream::failure & e)
	{
		cerr << "Error Opening and Writing the file";
	}
	expressionFile.close();
}

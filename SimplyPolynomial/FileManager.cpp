#include <iostream>
#include <fstream>
#include "FileManager.h"
#include <string>

using namespace std;

ofstream outputFile;
ifstream ReadFile("output.txt");

void FileManager::writeTheOutputSet(int startNumber, int EndNumber, int numberOfTerms, Polynomial::term* t)
{
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
	outputFile.close();
}

void FileManager::readTheOutputSet()
{
	string text;

	ReadFile.open("output.txt", ios::in);

	if (ReadFile.is_open())
	{
		while (getline(ReadFile,text))
		{
			cout << text;
		}
		//ReadFile >> text;
		
	}
	else
	{
		cerr << "Failed to open the file";
	}
}

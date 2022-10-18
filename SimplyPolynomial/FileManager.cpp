#include <iostream>
#include <fstream>
#include "FileManager.h"
#include <string>

using namespace std;

ofstream outputFile;
ifstream myfile("output.txt");

void FileManager::writeTheOutputSet(int startNumber, int EndNumber, int numberOfTerms, Polynomial::term* t)
{
	try
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
	}
	catch(ofstream::failure& e)
	{
		cerr << "Error Opening and Reading the file";
	}
	outputFile.close();
}

void FileManager::readTheOutputSet()
{
	string line;

	try
	{
		if (myfile.is_open())
		{
			while (getline(myfile, line))
			{
				cout << line << '\n';
			}
			myfile.close();
		}
	}
	catch (ifstream::failure e)
	{
		cout << "Unable to open file and read";
	}
}

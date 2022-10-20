#include "FileManager.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ofstream outputFile;
ifstream myfile("output.txt");
vector<int> vec;

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
	}
	catch (ifstream::failure e)
	{
		cout << "Unable to open file and read";
	}
}

void FileManager::printResult()
{
	for (const int& i : vec) {
		cout << i << ",";
	}
}

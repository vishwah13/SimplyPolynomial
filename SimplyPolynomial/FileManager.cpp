#include "FileManager.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream myfile("output.txt");

void FileManager::ClearFile(ofstream &file,string fileName)
{
	file.open(fileName);
	file << "";
	file.close();
}

void FileManager::getVector(const string& s, vector<int>& v)
{
	int n = 0;
	stringstream ss(s);
	while (ss >> n)
	{
		v.push_back(n);
	}
}

void FileManager::writeTheOutputSetToFile(int startNumber, int EndNumber, int numberOfTerms, Polynomial::term* t)
{
	ofstream outputFile;
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
				outputFile << ", ";
		}
		outputFile << "\n";
	}
	catch(ofstream::failure& e)
	{
		cerr << "Error Opening and Writing the file";
	}
	outputFile.close();
}

vector<int> FileManager::readTheOutputSetFromFile()
{
	vector<int> vec;
	vector<string> linesV;
	ifstream reader = ifstream("output.txt", ios::in);
	try
	{
		string line;
		int index = 0;
		cout << "The output sets are: " << "\n";
		while (getline(reader, line, '\n'))
		{
			cout << index << ": " << line << "\n ";
			index++;
			cout << "\n";
			line.erase(remove(line.begin(), line.end(), ','), line.end());
			linesV.push_back(line);
		}
		reader.close();
	}
	catch (ifstream::failure e)
	{
		cout << "Unable to open file and read";
	}

	cout << "\nWhich output set do you want to use to find the expression: ";
	int index; cin >> index;
	string currentLine = linesV[index];
	getVector(currentLine, vec);

	return vec;
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
		expressionFile.open("ExpressionFile.txt", ios::app);

		for (int i = 0; i < numberOfTerm; i++)
		{
			if (t[i].coefficient == 0 && t[i].exponent == 0)
			{
				expressionFile << "\n";
				return;
			}

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

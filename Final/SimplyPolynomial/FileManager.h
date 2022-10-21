#pragma once
#include "Polynomial.h"
#include <vector>
#include <fstream>

class FileManager
{
private:
	void ClearFile(ofstream &file, string fileName);
	void getVector(const string& s, vector<int>& v);
	
public:

	void writeTheOutputSetToFile(int startNumber, int EndNumber, int numberOfTerms, std::vector<Polynomial::term>& t);
	vector<int> readTheOutputSetFromFile();
	void printResult(vector<int> vec);
	void writeTheExpressionToFile(std::vector<Polynomial::term>& t,int numberOfTerm);
};
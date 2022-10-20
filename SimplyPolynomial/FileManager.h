#pragma once
#include "Polynomial.h"
#include <vector>
#include <fstream>

class FileManager
{
private:
	void ClearFile(ofstream &file, string fileName);
	
public:

	void writeTheOutputSet(int startNumber, int EndNumber, int numberOfTerms, Polynomial::term* t);
	vector<int> readTheOutputSet();
	void printResult(vector<int> vec);
	void writeTheExpressionToFile(Polynomial::term* t,int numberOfTerm);
};
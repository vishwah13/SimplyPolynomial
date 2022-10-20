#pragma once
#include "Polynomial.h"
#include <vector>

class FileManager
{
private:
	void ClearFile();
	
	
public:

	void writeTheOutputSet(int startNumber, int EndNumber, int numberOfTerms, Polynomial::term* t);
	vector<int> readTheOutputSet();
	void printResult(vector<int> vec);
};
#pragma once
#include "Polynomial.h"

class FileManager
{
private:
	
public:

	void writeTheOutputSet(int startNumber, int EndNumber, int numberOfTerms, Polynomial::term* t);
	void readTheOutputSet();
};
#pragma once

class Polynomial
{
public:
	 struct term
	{
		int coefficient;
		int exponent;
	};

	void getInputs(term* t, int numberofTerms);
	int validateInput(int min, int max);
	void printTheExpresion(term* t, int n);
};




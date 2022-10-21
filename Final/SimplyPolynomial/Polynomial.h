#pragma once
#include <vector>
using namespace std;
class Polynomial
{
private:
	int validateInput(int min, int max);
	int calculateDifference(vector<int> arr, int& depth);
	int findFactorial(int fact);
	int FindCoefficient(vector<int> arr, int& depth);

public:
	 struct term
	{
		int coefficient;
		int exponent;

		term() : coefficient{ 0 }, exponent{ 0 } {}
		term(const term&) = default;
		term(term&&) = default;
		term& operator=(const term&) = default;
		term& operator=(term&&) = default;
	};

	 int startNo = 0;

	void getInputs(std::vector<term>& t, int numberofTerms);
	void showTheOutputSet(int startNumber, int EndNumber, int numberOfTerms, std::vector<Polynomial::term>& t);
	void printTheExpresion(std::vector<term>& t, int n);
	void FindTheExpression(std::vector<term>& t,vector<int> arr,int &depth,int i);
};




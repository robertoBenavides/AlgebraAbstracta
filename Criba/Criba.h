#pragma once
#include <vector>
#include <iostream>
using namespace std;
class Criba
{

private:
	int numero=1;
	vector<int> primos;
	void setPrimos(int);
	bool isPrimo(int);
	int mod(int, int);
public:
	Criba(int);
	vector<int> getPrimos();
	void print();
};


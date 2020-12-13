#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <time.h>
#include <iomanip>
#include <stdlib.h>
#include "Sort.h"
using namespace std;

class Interface
{
private:
	string filename;
	ifstream infile;
	ofstream outfile;
	Sort mySort;
	double** nums;
	int count;
	bool used;
public:
	Interface();
	Interface(string);
	~Interface();
	void readFile();
	void promptUser();
	void generateNumbers();
	void sortNumbers();
};


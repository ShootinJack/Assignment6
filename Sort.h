#pragma once
#include <iostream>
using namespace std;
class Sort
{
public:
	Sort();
	~Sort();
	void mergeSort(double**,int l, int r);
	void merge(double**, int l, int m, int r);
	void selectionSort(double**, int);
	void insertionSort(double**, int);
	void bubbleSort(double**, int);
	void quickSort(double**, int, int);
	int partition(double**, int, int);
	void swap(double*, double*);

};


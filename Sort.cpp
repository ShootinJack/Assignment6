#include "Sort.h"



Sort::Sort()
{
}


Sort::~Sort()
{
}

void Sort::mergeSort(double** arr, int l, int r) // This is the recursive mersort call. It splits the array in half at each turn and then does the swaping. It then puts it back together
{
		if (l >= r) {
			return;
		}
		int m = (l + r - 1) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
}

void Sort::merge(double** arr, int l, int m, int r) // This is the function that puts the array back together after sorting
{
	int type = 0;
	int n1 = m - l + 1;
	int n2 = r - m;
	double *L = new double[n1], *R = new double[n2];

	for (int i = 0; i < n1; ++i)
		L[i] = arr[type][l + i];
	for (int j = 0; j < n2; ++j)
		R[j] = arr[type][m + 1 + j];

	int i = 0;
	int j = 0;
	int k = l;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[type][k++] = L[i++];
		}
		else {
			arr[type][k++] = R[j++];
		}
	}

	while (i < n1) {
		arr[type][k++] = L[i++];
	}

	while (j < n2) {
		arr[type][k++] = R[j++];
	}
	delete L;
	delete R;
}

void Sort::quickSort(double** arr, int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high); // this is where the pivot is created

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

int Sort::partition(double** arr, int low, int high)
{
	int type = 1;
	double pivot = arr[type][high]; // pivot  
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) // iterates through the particioned area and makes swaps when needed
	{ 
		if (arr[type][j] < pivot)
		{ 
			i++;
			swap(&arr[type][i], &arr[type][j]);
		}
	}
	swap(&arr[type][i + 1], &arr[type][high]);
	return (i + 1);
}

void Sort::selectionSort(double** arr, int n)
{
	int type = 2;
	int i, j, min_idx;

	for (i = 0; i < n - 1; i++)		// selection sort finds the minimum element from the unsorted array and puts it in the front. Then goes through again until it is sorted.
	{ 
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr[type][j] < arr[type][min_idx]) {
				min_idx = j;
			}
		if (min_idx != i) {
			swap(&arr[type][min_idx], &arr[type][i]);
		}
	}
}

void Sort::insertionSort(double** arr, int n) // insert sort, splits the array into unsorted and unsorted. Takes one element and puts it where it belongs. The continues until every element is sorted.
{
	int type = 3;
	int i, j;
	double key;
	for (i = 1; i < n; i++)
	{
		key = arr[type][i];
		j = i - 1;
		while (j >= 0 && arr[type][j] > key)
		{
			arr[type][j + 1] = arr[type][j];
			j = j - 1;
		}
		arr[type][j + 1] = key;
	}
}

void Sort::bubbleSort(double** arr, int n) //  bubble sort goes through the array and swaps anytime anything is out of order. It goes through the array many times to make the simple swap.
{
	int type = 4;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[type][j] > arr[type][j + 1]) {
				swap(&arr[type][j], &arr[type][j + 1]);
			}
		}
	}				
}

void Sort::swap(double* a, double* b) // this function swaps the elements provided.
{
	double t = *a;
	*a = *b;
	*b = t;
}




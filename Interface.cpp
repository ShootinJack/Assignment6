#include "Interface.h"



Interface::Interface() // default constructor
{
	srand(time(NULL));
	used = false;
}

Interface::Interface(string in) // overloaded constructor, this onstructor takes in the filename and checks if it is valid. 
								// If not the user is prompted to enter another. If it is valid it proceeds to read it.
{
	srand(time(NULL));
	used = false;
	filename = in;
	infile.open(filename);
	if (infile.is_open()) {
		infile.close();
		readFile();
	}
	else {
		infile.close();
		cout << "Invalid File\n";
		promptUser();
	}
}


Interface::~Interface() // destructor deletes the dynamic array if one was created and used.
{
	if (used) {
		for (int i = 0; i < 5; ++i) {
			delete[] nums[i];
		}
		delete[] nums;
	}
}

void Interface::promptUser() // This function gets a file name from the user. It will generate random numbers if prompted to. It will also quit if prompted. Anything else it will reprompt
{
	cout << "Enter file name\nEnter \"random\" for random 100,000 numbers\nEnter q to quit\n";
	cout << "Entry: ";
	cin >> filename;
	infile.open(filename);
	if (infile.is_open()) {
		infile.close();
		readFile();
	}
	else if (filename == "q") {
		infile.close();
		cout << "Goodbye\n";
	}
	else if (filename == "random") {
		generateNumbers();
		readFile();
	}
	else {
		cout << "Invalid Entry";
		infile.close();
		promptUser();
	}
}

void Interface::readFile() // this function reads the file. It makes a count of how many numbers are in the list.
{
	count = 0;
	double in;
	infile.open(filename);
	while (infile.good()) {
		infile >> in;
		count++;
	}
	infile.close();
	used = true;
	nums = new double*[5];		// a 2d array is created. That way 5 arrays can be created of the same set of numbers. 
	for (int i = 0; i < 5; ++i) {
		nums[i] = new double[count];
	}
	for (int i = 0; i < 5; ++i) {
		infile.open(filename);
		for (int j = 0; j < count; ++j) {
			infile >> nums[i][j];
		}
		infile.close();
	}
	sortNumbers();
}

void Interface::generateNumbers()  // this function generates 100,000 random doubles between 1-1000 and outputs them to a file. Then readfile is called.
{
	filename = "random.txt";
	outfile.open(filename);
	cout << "Generating Numbers";
	for (int i = 0; i < 100000; ++i) {
		outfile << setprecision(4) << ((double)rand() / (RAND_MAX)) * 1000 << endl;
		if (i == 25000 || i == 50000 || i == 75000) {
			cout << ".";
		}
	}
	cout << "\nNumbers Generated!\n";
	outfile.close();
}

void Interface::sortNumbers() // this function uses the sort option to sort all the arrays. It then prints how long each algorithm took.
{
	double secondsPassed, time;
	clock_t startTime = clock();
	mySort.mergeSort(nums, 0, count - 1);
	time = double(clock() - startTime)/double(1000);
	cout << "MergeSort: " << time << " seconds\n";

	startTime = clock();
	mySort.quickSort(nums, 0, count - 1);
	time = double(clock() - startTime) / double(1000);
	cout << "QuickSort: " << time << " seconds\n";

	startTime = clock();
	mySort.selectionSort(nums, count);
	time = double(clock() - startTime) / double(1000);
	cout << "SelectionSort: " << time << " seconds\n";

	startTime = clock();
	mySort.insertionSort(nums, count);
	time = double(clock() - startTime) / double(1000);
	cout << "InsertionSort: " << time << " seconds\n";

	startTime = clock();
	mySort.bubbleSort(nums, count);
	time = double(clock() - startTime) / double(1000);
	cout << "BubbleSort: " << time << " seconds\n";
}

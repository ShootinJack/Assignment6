#include <iostream>
#include "Interface.h"
using namespace std;

int main(int argc, char** argv) { 
	string filename;
	if (argv[1] != NULL) {
		filename = argv[1];
	}
	else
	{
		filename = "none.txt";
	}
	Interface UI(filename);
	system("pause");
	return 0;
}
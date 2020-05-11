// CPPTest.cpp : Defines the entry point for the application.
//

#include "CPPTest.h"

using namespace std;

int main()
{
	int64_t A[10];
	int64_t* p = A;
	*(p + 1) = 5;
	cout << A[1] << endl;
	return 0;
}

#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int IN, OUT, MAX = 0;


int main()
{
	cin >> OUT >> IN;

	while (IN != 0)
	{
		MAX = max(MAX, MAX - OUT + IN);
		cin  >> OUT >> IN;
	}
	

	cout << MAX;

	return 0;
}
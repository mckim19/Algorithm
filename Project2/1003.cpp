#include <iostream>
#include <cstring> 
using namespace std;

int T;
int* ArrN;
int Arr[2][41];

void fibonacci(int n)
{
	for (int i = 2; i <= n; i++)
	{
		Arr[0][i] = Arr[0][i - 1] + Arr[0][i - 2];
		Arr[1][i] = Arr[1][i - 1] + Arr[1][i - 2];
	}

}

int main(void)
{
	cin >> T;

	ArrN = new int[T];

	for (int i = 0; i < T; i++)
		cin >> ArrN[i];

	for (int i = 0; i < T; i++)
	{
		Arr[0][0] = 1;
		Arr[1][1] = 1;

		fibonacci(ArrN[i]);
		cout << Arr[0][ArrN[i]] << " " << Arr[1][ArrN[i]] << "\n";
	}

	delete[] ArrN;

	return 0;
}
#include <iostream> 

int N;
int* Arr;
using namespace std;

int main() {

	cin >> N;
	Arr = new int[N + 1];
	//memset(Arr, 0, sizeof(int) * (N + 1));

	Arr[0] = 0;
	Arr[1] = 1; 
	Arr[2] = 2; 

	for (int i = 3; i <= N; i++) {
		Arr[i] = (Arr[i - 2] + Arr[i - 1]) % 15746;
	}

	cout << Arr[N] << "\n";

	return 0;
}
#include <iostream>
using namespace std;

long long Arr[91];
int n;

void fibo_function(int n)
{
	Arr[0] = 0;
	Arr[1] = 1;
	for (int i = 2; i <= n; i++) //�Ǻ���ġ 3��°���� ����
	{
		Arr[i] = Arr[i - 1] + Arr[i - 2];
	}

}

int main()
{
	cin >> n;

	fibo_function(n);

	printf("%lld", Arr[n]);

	return 0;
}
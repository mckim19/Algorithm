#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int X = 0;
int Poll_Arr[7] = {64,32,16,8,4,2,1};
int ans = 0;

int main()
{
	cin >> X;

	for (int i = 0; i < 7; i++)
	{
		if (0 <= X - Poll_Arr[i])
		{
			ans++;
			X -= Poll_Arr[i];
		}

	}

	cout << ans;

	return 0;
}
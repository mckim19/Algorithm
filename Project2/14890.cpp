#include <iostream>
#include <string.h>
using namespace std;

int** Arr;
int** Visited;
int N, L, ans = 0;


int main() 
{
	
	cin >> N >> L;

	Arr = new int*[N];

	for (int i = 0; i < N; i++)
	{
		Arr[i] = new int[N];
		memset(Arr[i], 0, sizeof(int) * N);
	}

	Visited = new int*[N];

	for (int i = 0; i < N; i++)
	{
		Visited[i] = new int[N];
		memset(Visited[i], 0, sizeof(int) * N);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> Arr[i][j];
		}
	}

	//가로로
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N-1; j++)
		{
			bool ans_flag = false;

			if (Arr[i][j] + 1 == Arr[i][j + 1])
			{
				for (int z = 0; z < L; z++)
				{
					if (j - z >= 0 && Arr[i][j] == Arr[i][j - z] && Visited[i][j - z] != 1)
					{
						Visited[i][j - z] = 1;
					}
					else
					{
						ans_flag = true;
					}
				}
			}
			else if (Arr[i][j] == Arr[i][j + 1] + 1 )
			{
				for (int z = 0; z < L; z++)
				{
					if (j + 1 + z < N && Arr[i][j+1] == Arr[i][j+1 + z] && Visited[i][j + 1 + z] != 1)
					{
						Visited[i][j + 1 + z] = 1;
					}
					else
					{
						ans_flag = true;
					}
				}
			}
			else if (Arr[i][j] == Arr[i][j + 1])
			{
				
			}
			else
			{
				break;
			}
			
			if (ans_flag == true)
			{
				break;
			}

			if (j == N - 2)
			{
				ans++;
			}
				
		}
	}
	
	for (int i = 0; i < N; i++)
	{
		memset(Visited[i], 0, sizeof(int) * N);
	}	

	//세로로
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			bool ans_flag = false;

			if (Arr[j][i] + 1 == Arr[j + 1][i] && Visited[j][i] != 1)
			{
				for (int z = 0; z < L; z++)
				{
					if (j - z >= 0 && Arr[j][i] == Arr[j - z][i])
					{
						Visited[j - z][i] = 1;
					}
					else
					{
						ans_flag = true;
					}
				}
			}
			else if (Arr[j][i] == Arr[j + 1][i] + 1 && Visited[j + 1][i] != 1)
			{
				for (int z = 0; z < L; z++)
				{
					if (j + 1 + z < N && Arr[j+1][i] == Arr[j + 1 + z][i])
					{
						Visited[j + 1 + z][i] = 1;
					}
					else
					{
						ans_flag = true;
					}
				}
			}
			else if (Arr[j][i] == Arr[j + 1][i])
			{
				
			}
			else
			{
				break;
			}

			if (ans_flag == true)
			{
				break;
			}

			if (j == N - 2)
			{
				ans++;
			}

		}
	}
	

	cout << "ans : " << ans << "\n";


	

	return 0;
}
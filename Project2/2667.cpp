#include <iostream>	
#include <queue>
#include <string.h>
using namespace std;

int dansi_cnt, N = 0;
int** Arr;
int** Visited;
int Ans[625] = { 0, };
int dir[4][2] = { {-1,0},{0, -1},{1,0},{0,1} };

void BFS(int x, int y)
{
	if (Arr[x][y] == 0 || Visited[x][y] == 1)
	{
		return;
	}

	queue<pair<int, int> > qu;

	qu.push(make_pair(x, y));


	while (!qu.empty())
	{
		int x = qu.front().first;
		int y = qu.front().second;
		Visited[x][y] = 1;
		qu.pop();
		Ans[dansi_cnt]++;
		

		for (int i = 0; i < 4; i++)
		{
			int new_x = x + dir[i][0];
			int new_y = y + dir[i][1];

			if (new_x >= 0 && new_y >= 0 && new_x < N && new_y < N && Visited[new_x][new_y] != 1 && Arr[new_x][new_y] != 0)
			{
				qu.push(make_pair(new_x, new_y));
				Visited[new_x][new_y] = 1;
			}
		}
	}
	dansi_cnt++;

	return;
}

int main()
{

	cin >> N;
	
	Arr = new int*[N];

	for (int i = 0; i < N; i++)
	{
		Arr[i] = new int[N];
		memset(Arr[i], 0, sizeof(int) * N);
	}
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf_s("%1d", &Arr[i][j]);
		}
	}

	Visited = new int* [N];

	for (int i = 0; i < N; i++)
	{
		Visited[i] = new int[N];
		memset(Visited[i], 0, sizeof(int) * N);
	}
	
	///////////////////////////////////////////////////////////////

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			BFS(i, j);
		}
	}
	
	cout << dansi_cnt << "\n";

	for (int i = 0; i < dansi_cnt; i++)
	{
		cout << Ans[i] << "\n";
	}

	return 0;
}
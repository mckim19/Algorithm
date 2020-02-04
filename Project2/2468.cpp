#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

int N, ans = 0;
int **area;
int** visited;
int dir[4][2] = { {1,0},{-1,0},{0,-1},{0,1} };

void areaBFS(int water_height)
{

	queue<pair<int, int> > qu;
	int cnt = 0;


	//메모리 할당
	visited = new int* [N];

	for (int i = 0; i < N; i++)
	{
		visited[i] = new int[N];
		memset(visited[i], 0, sizeof(int) * N);
	}



	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			visited[i][j] = 0;
		}
	}


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (area[i][j] > water_height && visited[i][j] == 0)
			{
				qu.push(make_pair(i, j));
				visited[i][j] = 1;
				cnt++;

				while (!qu.empty())
				{

					int x = qu.front().first;
					int y = qu.front().second;
					qu.pop();

					for (int z = 0; z < 4; z++)
					{
						int new_x = x + dir[z][0];
						int new_y = y + dir[z][1];

						if (new_x >= 0 && new_x < N && new_y >= 0 && new_y < N && area[new_x][new_y] > water_height && visited[new_x][new_y] == 0)
						{
							qu.push(make_pair(new_x, new_y));
							visited[new_x][new_y] = 1;
						}
					}
					
				}
			}
		}
	}
	
	//메모리 해제
	for (int i = 0; i < N; i++)
	{
		delete[] visited[i];
	}
	delete[] visited;

	ans = max(cnt, ans);
}


int  main()
{
	cin >> N;

	//메모리 할당
	area = new int*[N];
	
	for (int i = 0; i < N; i++)
	{
		area[i] = new int[N];
		memset(area[i], 0, sizeof(int) * N);
	}


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> area[i][j];
		}
	}

	for (int i = 0; i <= 100; i++)
	{
		areaBFS(i);	

		if (ans == 0)
			break;
	}



	//메모리 해제
	for (int i = 0; i < N; i++)
	{
		delete[] area[i];
	}
	delete[] area;

	//정답 출력
	cout << ans;

	return 0;
}
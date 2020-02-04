#include <iostream>
#include <string.h>
using namespace std;

int** adj;
int nodeNumber, edgeNumber, ans  = 0;
int* visited;

void DFS(int d)
{
	visited[d] = 1;

	for (int i = 0; i < nodeNumber; i++)
	{
		if (visited[i] != 1 && adj[d][i] == 1)
		{
			DFS(i);
			ans++;
		}
	}
}

int main()
{

	cin >> nodeNumber;
	cin >> edgeNumber;

	//////////////////////////////////////////
	//메모리 할당
	adj = new int*[nodeNumber];

	for (int i = 0; i < nodeNumber; i++)
	{
		adj[i] = new int[nodeNumber];
		memset(adj[i], 0, sizeof(int) * nodeNumber);
	}

	visited = new int[nodeNumber];
	memset(visited, 0, sizeof(int));
	//////////////////////////////////////////

	for (int i = 0; i < edgeNumber; i++)
	{
		int first, second = 0;
		cin >> first >> second;
		adj[first - 1][second - 1] = 1;
		adj[second - 1][first - 1] = 1;
	}
	
	for (int i = 0; i < nodeNumber; i++)
	{
		visited[i] = 0;
	}




	DFS(0);

	cout << ans;

	return 0;
}
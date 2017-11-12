#define _CRT_SECURE_NO_WARNINGS
#define SIZE 111
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[SIZE];
bool visited[SIZE];

int N, ssang;

void __init__()
{
	cin >> N;
	cin >> ssang;

	for (int i = 0; i < ssang; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
}

int check()
{
	int ret = 0;
	for (int i = 1; i <= N; i++)
		if (visited[i]) ret++;

	return ret;
}

int bfs()
{
	queue<int> q;
	visited[1] = true;
	q.push(1);

	while (!q.empty())
	{
		int here = q.front();	q.pop();
		
		int len = (int)adj[here].size();
		for (int i = 0; i < len; i++)
		{
			int there = adj[here][i];
			if (!visited[there])
			{
				q.push(there);
				visited[there] = true;
			}
		}
	}

	return check() - 1;
}

int main(void)
{
	freopen("input.txt", "r", stdin);
	__init__();
	cout << bfs();

	return 0;
}

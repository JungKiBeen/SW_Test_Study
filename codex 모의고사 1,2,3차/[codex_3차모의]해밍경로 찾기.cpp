#define _CRT_SECURE_NO_WARNINGS
#define NSIZE 1111
#include <iostream>
#include <climits>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
using namespace std;

int N, K, src, dst;
int dist[NSIZE], parent[NSIZE];
string codes[NSIZE];
vector<int> adj[NSIZE];


void __init__()
{
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++)
		cin >> codes[i];
	scanf("%d %d", &src, &dst);
}

inline bool is_adj(string a, string b)
{
	int diff = 0;
	for (int i = 0; i < K; i++)
	{
		if (a[i] != b[i]) diff++;
	}

	return (diff == 1);
}


void mk_adj()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = i+1; j <= N; j++)
		{
			if (is_adj(codes[i], codes[j]))
			{
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
}

void show_path(int vtx)
{
	vector<int> path;
	int prev = -1;
	while (vtx != prev)
	{
		path.push_back(vtx);
		prev = vtx;
		vtx = parent[vtx];
	}

	int left = 0, right = path.size() - 1;
	while (left < right)
	{
		int temp = path[left];
		path[left] = path[right];
		path[right] = temp;
		left++, right--;
	}
	int len = (int)path.size();
	for (int i = 0; i < len; i++)
		printf("%d ", path[i]);
}


void bfs()
{
	queue<int> q;
	q.push(src);
	dist[src] = 1; // 실제거리 + 1, 0 : not visited
	parent[src] = src;

	while (!q.empty())
	{
		int here = q.front(); q.pop();
		int cost = dist[here];
		if (here == dst)
		{
			show_path(dst);
			return;
		}

		int len = (int)adj[here].size();
		for (int i = 0; i < len; i++)
		{
			int there = adj[here][i];
			if (dist[there] == 0)
			{
				dist[there] = cost + 1;
				parent[there] = here;
				q.push(there);
			}
		}
	}

	printf("%d", -1);
}

int main(void)
{
	__init__();
	mk_adj();
	bfs();
	return 0;
}
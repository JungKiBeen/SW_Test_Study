// 1) iomaip으로는 반올림시 반드시 소수 세자리까지 출력하지는 않는다. ex) 1.70

#define _CRT_SECURE_NO_WARNINGS
#define NSIZE 555

#include <iostream>
#include<cstdio>
#include<climits>
#include<queue>
#include<vector>
#include<utility>
#include<algorithm>
#include<string>
using namespace std;

vector<int> adj[NSIZE];
int N, SOL, last;

void __init__()
{
	last = -1;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		last = max(last, a);
		last = max(last, b);
		adj[a].push_back(b);
	}
}

void dijkstra(int src)
{
	vector<int> dist(last + 1, INT_MAX);
	priority_queue<pair<int, int> > pq; // cost, vertex
	pq.push(make_pair(0, src));

	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int vtx = pq.top().second; pq.pop();

		if (dist[vtx] < cost) continue;

		int len = (int)adj[vtx].size();
		for (int i = 0; i < len; i++)
		{
			int there = adj[vtx][i];
			int next_cost = cost + 1;
			if (next_cost < dist[there])
			{
				dist[there] = next_cost;
				pq.push(make_pair(-next_cost, there));
			}
		}
	}

	for (int i = 1; i <= last; i++)
	{
		if (i != src) SOL += dist[i];
	}
}

int main(void)
{
	__init__();
	for (int i = 1; i <= last; i++)
	{
		dijkstra(i);
	}

	double temp = (double)SOL / (last * (last - 1));
	string _temp = to_string(temp);
	if (_temp[5] >= '5')
	{
		_temp[4] = _temp[4] + 1;
	}
	cout << _temp.substr(0, 5);

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <climits>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

vector<vector<pair<int, double> > > adj;	// 인접 정점과 가중치를 가지고 있음
vector<double> dist;
vector<int> parent;
int n, m;

double dijkstra(int src, int dest)
{
	priority_queue<pair<double, int> > pq;
	pq.push(make_pair(-1.0, src));
	dist[src] = 1.0;
	parent[src] = src;

	while (!pq.empty())
	{
		int here = pq.top().second;
		double cost = -(pq.top().first);
		pq.pop();

		if (cost > dist[here]) continue;	// here는 유효하지 않은 정점이다.

		int size = adj[here].size();
		for (int i = 0; i < size; i++)
		{
			int there = adj[here][i].first;
			double there_cost = cost * adj[here][i].second;

			if(dist[there] > there_cost)
			{
				pq.push(make_pair(-there_cost, there));
				dist[there] = there_cost;
				parent[there] = here;
			}
		}// for
	}// while

	return dist[dest];
}


void __init__()
{
	cin >> n >> m;
	adj = vector<vector<pair<int, double> > >(n);
	dist = vector<double>(n, INT_MAX);
	parent = vector<int>(n);

	for (int i = 0; i < m; i++)
	{
		int a, b; double c;
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(b, c));
		adj[b].push_back(make_pair(a, c));
	}
}

void show_parent(int dest)
{
	string path = "";
	int v = dest;
	while (v != parent[v])
	{
		path.push_back('a' + v);
		path.push_back(' ');
		v = parent[v];
	}
	path.push_back('a' + v);
	reverse(path.begin(), path.end());
	cout << path;
}


int main(void)
{
	std::ios_base::sync_with_stdio(false);
	freopen("sample_input.txt", "r", stdin);
	int T; cin >> T;
	
	for (int tc = 1; tc <= T; tc++)
	{
		__init__();
		cout << "#" << tc << " " << dijkstra(0, n - 1) << " : "; show_parent(n - 1); puts("");
	}

	return 0;
}
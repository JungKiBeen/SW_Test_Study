#define _CRT_SECURE_NO_WARNINGS
#define SIZE 15
#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <utility>
#include <climits>

using namespace std;

int N;
int adj[SIZE][SIZE];	// 1번 부터 사용
bool visited[SIZE];

// 첫번재 방문 부터, n은 n번째 방문
void dfs(int n, int here, int pay, int &sol)
{
	if (pay >= sol) return;
	if (n == N)
	{
		if(adj[here][1] > 0) sol = min(pay + adj[here][1], sol);
		return;
	}

	for (int comp = 2; comp <= N; comp++)
	{
		if (!visited[comp] && adj[here][comp] > 0)
		{
			visited[comp] = true;
			dfs(n + 1, comp, pay + adj[here][comp], sol);
			visited[comp] = false;
		}
	}
	
}

void __init__()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			scanf("%d", &adj[i][j]);
	}
}

int main(void)
{
	//freopen("input.txt", "r", stdin);
	__init__();
	int sol = INT_MAX;
	visited[1] = true;
	dfs(1, 1, 0, sol);
	cout << sol;
	return 0;
}

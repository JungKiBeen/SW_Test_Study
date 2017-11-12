// 1) 그래프의 컴포넌트는 visted : bool[]을 공유하여 bfs_all() 호출 횟수로 구할 수 있다. 

#define _CRT_SECURE_NO_WARNINGS
#define SIZE 111
#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <utility>
#include <climits>

using namespace std;

int N;
int MAP[SIZE][SIZE]; // 0.. N-1
bool jamsu[SIZE][SIZE];	// true 물에 잠김

int r_dir[] = { -1, 0, 1, 0 };
int c_dir[] = { 0, 1, 0, -1 };

void __init__()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &MAP[i][j]);
		}
	}
}

void bfs_all(int r, int c, int bi, vector<vector<bool> > &visited)
{
	queue<pair<int, int> > q;
	visited[r][c] = true;
	q.push(make_pair(r, c));

	while (!q.empty())
	{
		pair<int, int> here = q.front(); q.pop();

		for (int i = 0; i < 4; i++)
		{
			int rr = here.first + r_dir[i]; int cc = here.second + c_dir[i];
			if (rr < 0 || rr >= N || cc < 0 || cc >= N) continue;

			if (MAP[rr][cc] > bi && !visited[rr][cc])
			{
				visited[rr][cc] = true;
				q.push(make_pair(rr, cc));
			}
		}
	}
}

int solve()
{
	int MAX = 0;

	for (int bi = 0; bi <= 100; bi++)
	{
		vector<vector<bool> > visited(N + 5, vector<bool>(N + 5, false));
		int safe_area = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (MAP[i][j] > bi && !visited[i][j])	// 잠기지 않고 방문하지 않았으면
				{
					bfs_all(i, j, bi, visited);
					safe_area++;
				}
			}
		}
		MAX = max(MAX, safe_area);
	}
	printf("%d", MAX);
}

int main(void)
{
	//freopen("input.txt", "r", stdin);
	__init__();
	solve();
	return 0;
}

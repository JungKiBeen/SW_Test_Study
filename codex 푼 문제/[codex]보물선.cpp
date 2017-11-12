#define _CRT_SECURE_NO_WARNINGS
#define SIZE 55
#include <iostream>
#include <cstdio>
#include <utility>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int r_dir[] = { -1, 0, 1, 0 };
int c_dir[] = { 0, 1, 0, -1 };

int ROW, COL;
char map[SIZE][SIZE];

void __init__()
{
	scanf("%d %d", &ROW, &COL);
	for (int i = 0; i < ROW; i++)
		scanf("%s", map[i]);
}


int bfs(int r, int c)
{
	queue<pair<int, int> > q;
	vector<vector<int> > dist(ROW, vector<int>(COL, -1));

	q.push(make_pair(r, c));
	dist[r][c] = 0;

	pair<int, int> here;
	while (!q.empty())
	{
		here = q.front(); q.pop();
		int cost = dist[here.first][here.second];

		for (int i = 0; i < 4; i++)
		{
			int rr = here.first + r_dir[i];		int cc = here.second + c_dir[i];
			if (rr < 0 || rr >= ROW || cc < 0 || cc >= COL)
				continue;

			if (map[rr][cc] == 'L' && dist[rr][cc] == -1)
			{
				dist[rr][cc] = cost + 1;
				q.push(make_pair(rr, cc));
			}
		}
	} // while

	return dist[here.first][here.second];
}

int solve()
{
	int MAX = -1;
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (map[i + 1][j] == 'L' && map[i - 1][j] == 'L') continue;
			if (map[i][j + 1] == 'L' && map[i][j - 1] == 'L') continue;
			if (map[i][j] == 'L')
			{
				int sol = bfs(i, j);
				MAX = max(sol, MAX);
			}
		}
	}
	return MAX;
}
int main(void)
{
	//freopen("input.txt", "r", stdin);
	__init__();
	cout << solve();
	return 0;
}
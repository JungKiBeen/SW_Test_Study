#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

int dr[] = { -1, 0 , 1, 0 };	int dc[] = { 0, 1, 0, -1 };
int n, m;

int BFS(vector<vector<int>> &mat, vector<vector<int>> &cost)
{
	queue<pair<int, int>> q;
	queue<pair<int, int>> next_q;

	q.push(make_pair(1, 1));
	cost[1][1] = 0;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == n && y == m) break;

		for (int i = 0; i < 4; i++)
		{
			int xx = x + dr[i];	int yy = y + dc[i];
			if (xx <= 0 || xx > n || yy <= 0 || yy > m)	continue;

			if (cost[xx][yy] == -1)
			{
				if (mat[xx][yy] == 1)	// 벽이면
				{
					cost[xx][yy] = cost[x][y] + 1;	// cost 증가
					next_q.push(make_pair(xx, yy));
				}

				else
				{
					cost[xx][yy] = cost[x][y];		// 이전 cost 유지
					q.push(make_pair(xx, yy));
				}
			}
		}

		if (q.empty())
		{
			q = next_q;
			next_q = queue<pair<int, int>>();
		}
	}

	return cost[n][m];
}

int main()
{
	//freopen("a.txt", "r", stdin);
	cin >> m >> n;

	vector<vector<int>> mat(n + 1, vector<int>(m + 1));
	vector<vector<int>> cost(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%1d", &mat[i][j]);	// mat [1..n][1..m]
			cost[i][j] = -1;
		}
	}

	int sol = BFS(mat, cost);

	cout << sol;
	return 0;
}
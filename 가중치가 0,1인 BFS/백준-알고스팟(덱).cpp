#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<deque>
using namespace std;

int dr[] = { -1, 0 , 1, 0 };	int dc[] = { 0, 1, 0, -1 };
int n, m;

int BFS(vector<vector<int>> &mat, vector<vector<int>> &cost)
{
	deque<pair<int, int>> d;

	d.push_front(make_pair(1, 1));
	cost[1][1] = 0;

	while (!d.empty())
	{
		int x = d.front().first;
		int y = d.front().second;
		d.pop_front();

		if (x == n && y == m) break;

		for (int i = 0; i < 4; i++)
		{
			int xx = x + dr[i];	int yy = y + dc[i];
			if (xx <= 0 || xx > n || yy <= 0 || yy > m)	continue;

			if (cost[xx][yy] == -1)
			{
				if (mat[xx][yy] == 1)	// ���̸�
				{
					cost[xx][yy] = cost[x][y] + 1;	// cost ����
					d.push_back(make_pair(xx, yy));
				}
				
				else
				{
					cost[xx][yy] = cost[x][y];		// ���� cost ����
					d.push_front(make_pair(xx, yy));
				}
			}
		}

	}
	
	return cost[n][m];
}

int main()
{
	freopen("a.txt", "r", stdin);
	cin >> m >> n;

	vector<vector<int>> mat(n+1, vector<int>(m+1));
	vector<vector<int>> cost(n+1, vector<int>(m+1));
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
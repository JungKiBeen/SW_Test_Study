#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<queue>
#include<algorithm>
#include<vector>
#include<string.h>
#include<utility>
using namespace std;

int r_dir[] = { -1, 0, 1, 0 }; int c_dir[] = { 0, 1, 0, -1 };

int MAP[25][25];	// 1..N ; 1...40
int N, m;
int op_cost[25];

void bfs(int x, int y, vector<int> &hn)
{
	vector<vector<int> > dist(25, vector<int>(25, 0));
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	dist[x][y] = 1;

	while (!q.empty())
	{
		pair<int, int> here = q.front(); q.pop();
		int cost = dist[here.first][here.second];
		if (MAP[here.first][here.second] == 1) 	hn[cost]++;


		for (int i = 0; i < 4; i++)
		{

			int xx = here.first + r_dir[i];
			int yy = here.second + c_dir[i];
			if (xx < 1 || xx > N || yy < 1 || yy > N) continue;
			if (dist[xx][yy] == 0)
			{
				q.push(make_pair(xx, yy));
				dist[xx][yy] = cost + 1;
			}
		}
	}

}

void input()
{
	scanf("%d %d", &N, &m);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			scanf("%d", &MAP[i][j]);
	}
}

int solve()
{
	int sol = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			vector<int> hn(41, 0);
			bfs(i, j, hn);


			int prev_hn = 0;
			for (int k = 1; k <= 21; k++)
			{
				if (hn[k] != 0)
				{
					hn[k] += prev_hn;
					int pt = hn[k] * m - op_cost[k];
					if (pt >= 0)
					{
						sol = max(sol, hn[k]);
					}
					prev_hn = hn[k];
				}
				
			}
		}
	}
	return sol;
}


int main()
{
	//freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);

	for (int k = 1; k <= 21; k++)
	{
		op_cost[k] = k*k + (k - 1)*(k - 1);
	}

	for (int tc = 1; tc <= T; tc++)
	{
		input();
		printf("#%d %d\n", tc, solve());
	}

	return 0;
}
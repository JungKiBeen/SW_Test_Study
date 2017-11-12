#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<limits.h>

using namespace std;

int r_dir[] = { -1, 0, 1, 0 };
int c_dir[] = { 0, 1, 0, -1 };

int N, K, SOL;
int MAP[11][11], vtd[11][11]; // 1..N
int highest, hn;
int hx[7], hy[7];
int tt = 1;


void input()
{
	SOL = 0;
	highest = -1, hn = 0;
	scanf("%d %d", &N, &K);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &MAP[i][j]);
			highest = (MAP[i][j] > highest) ? MAP[i][j] : highest;
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (MAP[i][j] == highest)
			{
				++hn;
				hx[hn] = i, hy[hn] = j;
			}
		}
	}

}

void dfs(int n, int x, int y, bool is_pruned)
{
	for (int i = 0; i < 4; i++)
	{
		int xx = x + r_dir[i]; int yy = y + c_dir[i];
		if (xx < 1 || xx > N || yy < 1 || yy > N) continue;

		if (vtd[xx][yy] != tt)
		{
			if (MAP[x][y] > MAP[xx][yy])
			{
				vtd[xx][yy] = tt;
				dfs(n + 1, xx, yy, is_pruned);
				vtd[xx][yy] = 0;
			}

			else if(!is_pruned)
			{
				for (int k = 1; k <= K; k++)
				{
					if (MAP[x][y] > MAP[xx][yy] - k)
					{
						vtd[xx][yy] = tt;
						MAP[xx][yy] -= k;
						dfs(n + 1, xx, yy, true);
						MAP[xx][yy] += k;
						vtd[xx][yy] = 0;
					}
				}
			}
		}
	} // for
	SOL = (n > SOL) ? n : SOL;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++)
	{
		input();
		for (int i = 1; i <= hn; i++)
		{

			tt++;
			vtd[hx[i]][hy[i]] = tt;
			dfs(1, hx[i], hy[i], false);
			vtd[hx[i]][hy[i]] = 0;
		}
		printf("#%d %d\n",tc, SOL);
	}

	return 0;
}
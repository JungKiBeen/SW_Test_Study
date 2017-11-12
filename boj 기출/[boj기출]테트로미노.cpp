#define SIZE 555
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<climits>
using namespace std;

int r_dir[] = { -1, 0, 1, 0 };
int c_dir[] = { 0, 1, 0, -1 };

int R, C, SOL;
int MAP[SIZE][SIZE]; bool vtd[SIZE][SIZE];
int bk_x[SIZE], bk_y[SIZE];

void __init__()
{
	SOL = -1;
	scanf("%d %d", &R, &C);
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
			scanf("%d", &MAP[i][j]);
	}
}

// 1.. n번째 블록 까지
void dfs(int n)
{
	if (n > 4)
	{
		int temp = 0;
		for (int i = 1; i <= 4; i++)
		{
			temp += MAP[bk_x[i]][bk_y[i]];
		}
		if (SOL < temp) SOL = temp;
		return;
	}

	for (int i = 1; i < n; i++)
	{
		for (int dir = 0; dir < 4; dir++)
		{
			int xx = bk_x[i] + r_dir[dir]; int yy = bk_y[i] + c_dir[dir];
			if (xx < 1 || xx > R || yy  < 1 || yy > C) continue;
			if (!vtd[xx][yy])
			{
				vtd[xx][yy] = true;
				bk_x[n] = xx, bk_y[n] = yy;
				dfs(n + 1);
				vtd[xx][yy] = false;
			}
		}
	}
}

int main(void)
{
	//freopen("input.txt", "r", stdin);
	__init__();
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			vtd[i][j] = true;
			bk_x[1] = i, bk_y[1] = j;
			dfs(2);
			vtd[i][j] = false;
		}
	}
	printf("%d", SOL);
	return 0;
}
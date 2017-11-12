#define _CRT_SECURE_NO_WARNINGS
#define A 0
#define B 1
#define DSIZE 15
#define WSIZE 25

#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<string.h>

using namespace std;
int D, W, K, SOL;
int MAP[DSIZE][WSIZE];
int dsel[DSIZE];

bool inspec(int(*tmap)[WSIZE])
{
	for (int j = 1; j <= W; j++)
	{
		int tt = 1;
		int t = 1;
		for (int i = 1; i < D; i++)
		{
			if (tmap[i][j] == tmap[i + 1][j])
			{
				t++;
				tt = (t > tt) ? t : tt;
			}

			else
			{
				t = 1;
			}
		}

		if (tt < K) return false;
	}
	return true;
}


void dfs(int n, int cnt)
{
	if (cnt >= SOL) return;
	if (n >= D + 1)
	{
		int tmap[DSIZE][WSIZE];
		for (int i = 1; i <= D; i++)
		{
			if (dsel[i] == -1)
			{
				for (int j = 1; j <= W; j++)
					tmap[i][j] = MAP[i][j];
			}

			else if (dsel[i] == A)
			{
				for (int j = 1; j <= W; j++)
					tmap[i][j] = A;
			}

			else
				for (int j = 1; j <= W; j++)
					tmap[i][j] = B;
		}

		if (inspec(tmap))
		{
			SOL = (cnt < SOL) ? cnt : SOL;
		}
		return;
	}

	dsel[n] = -1;
	dfs(n + 1, cnt);

	dsel[n] = A;
	dfs(n + 1, cnt + 1);

	dsel[n] = B;
	dfs(n + 1, cnt + 1);

}

void input()
{
	memset(dsel, -1, sizeof(dsel));
	SOL = INT_MAX;
	scanf("%d %d %d", &D, &W, &K);
	for (int i = 1; i <= D; i++)
	{
		for (int j = 1; j <= W; j++)
			scanf("%d", &MAP[i][j]);
	}
}

int main()
{
	//	freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++)
	{
		input();
		if (inspec(MAP)) SOL = 0;
		else dfs(1, 0);
		printf("#%d %d\n", tc, SOL);
	}

	return 0;
}
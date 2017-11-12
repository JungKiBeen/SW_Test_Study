#define _CRT_SECURE_NO_WARNINGS
#define A 0
#define B 1
#define NON -1
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

void copy(int* dst, int* src, int size)
{
	for (int i = 1; i <= size; i++)
		dst[i] = src[i];
}

void dfs(int n, int cnt, int* cont, int* max_cont, bool is_sati)
{
	if (is_sati)
	{
		SOL = (cnt < SOL) ? cnt : SOL;
		return;
	}
	
	if (n >= D + 1 || cnt >= SOL || cnt >= K)  return;
	int tcont[WSIZE], tmax_cont[WSIZE];

	for (int i = NON; i <= B; i++)
	{
		copy(tcont, cont, W);
		copy(tmax_cont, max_cont, W);

		is_sati = true;
		for (int w = 1; w <= W; w++)
		{
			int cur = (i == NON) ? MAP[n][w] : i;
			int prev = (dsel[n - 1] == NON) ? MAP[n - 1][w] : dsel[n - 1];

			if (cur == prev)  	tcont[w]++;
			else tcont[w] = 1;

			tmax_cont[w] = (tcont[w] > tmax_cont[w]) ? tcont[w] : tmax_cont[w];
			if (tmax_cont[w] < K) is_sati = false;
		}

		dsel[n] = i;
		dfs(n + 1, cnt + (i == NON ? 0 : 1), tcont, tmax_cont, is_sati);
	}
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
	//freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++)
	{
		input();
		int cont[WSIZE], max_cont[WSIZE];
		for (int i = 0; i < WSIZE; i++)
			cont[i] = max_cont[i] = 1;
		
		dsel[1] = NON; 
		dfs(2, 0, cont, max_cont, (K == 1) ? true : false);

		dsel[1] = A;
		dfs(2, 1, cont, max_cont, (K == 1) ? true : false);

		dsel[1] = B;
		dfs(2, 1, cont, max_cont,(K == 1) ? true : false);

		printf("#%d %d\n", tc, SOL);
	}

	return 0;
}
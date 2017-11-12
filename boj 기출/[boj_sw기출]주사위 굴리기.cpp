#define _CRT_SECURE_NO_WARNINGS
#define MSIZE 22

#include<iostream>
#include<cstdio>
using namespace std;

int r_dir[] = { 0, 0, 0, -1, 1 }; int c_dir[] = { 0, 1, -1, 0, 0 };


int dx, dy, R, C, K;
int U, D, N, S, W, E;
int MAP[MSIZE][MSIZE]; // 0 .. R-1, C-1

inline bool move(int dir) // 바깥으로 나가는 경우 false 반환
{
	int dxx = dx + r_dir[dir]; int dyy = dy + c_dir[dir];
	if (dxx < 0 || dxx >= R || dyy < 0 || dyy >= C) return false;

	dx = dxx, dy = dyy;
	if (dir == 1)
	{
		int temp = D;
		D = E, E = U, U = W, W = temp;
	}
	else if (dir == 2)
	{
		int temp = D;
		D = W, W = U, U = E, E = temp;
	}
	else if (dir == 3)
	{
		int temp = D;
		D = N, N = U, U = S, S = temp;
	}
	else if (dir == 4)
	{
		int temp = D;
		D = S, S = U, U = N, N = temp;
	}
	return true;
}


void solve()
{
	scanf("%d %d %d %d %d", &R, &C, &dx, &dy, &K);
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			scanf("%d", &MAP[i][j]);
		}
	}
	for (int i = 1; i <= K; i++)
	{
		int dir;
		scanf("%d", &dir);
		if (move(dir))
		{
			if (MAP[dx][dy] == 0)
			{
				MAP[dx][dy] = D;
			}

			else
			{
				D = MAP[dx][dy];
				MAP[dx][dy] = 0;
			}
			printf("%d\n", U);
		}
	}
}



int main(void)
{
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
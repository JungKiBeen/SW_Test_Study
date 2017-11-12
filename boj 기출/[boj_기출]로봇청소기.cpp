#define _CRT_SECURE_NO_WARNINGS
#define SIZE 55

#include<iostream>
#include<cstdio>
#include <cstring>

using namespace std;

int l_dir[] = { 3, 0, 1, 2 };
int r_dir[] = { -1, 0, 1, 0 };
int c_dir[] = { 0, 1, 0, - 1 };

int MAP[SIZE][SIZE];
bool visited[SIZE][SIZE];
int R, C, sr, sc, sd;

bool flag = false;
int sol = 0;

void dfs(int r, int c, int d)
{
	if (MAP[r][c] == 1)
	{
		flag = true;
		return;
	}

	if (!visited[r][c] && MAP[r][c] ==0)
	{
		visited[r][c] = true;
		sol++;
	}

	for (int i = 0; i < 4; i++)
	{
		d = l_dir[d];
		int rr = r + r_dir[d], cc = c + c_dir[d];
		if (MAP[rr][cc] == 0 && !visited[rr][cc])
			dfs(rr, cc, d);
		if (flag) return;
	}

	int backward = (d + 2) % 4;
	int br = r + r_dir[backward], bc = c + c_dir[backward];
	dfs(br, bc,d );
}

void __init__()
{
	scanf("%d %d", &R, &C);
	scanf("%d %d %d", &sr, &sc, &sd);
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
			scanf("%d", &MAP[i][j]);
	}
}

int main(void)
{
	//freopen("input.txt", "r", stdin);
	__init__();
	dfs(sr, sc, sd);
	printf("%d", sol);
	return 0;
}
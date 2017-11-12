#define SIZE 11
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<climits>
#include<utility>
#include<queue>

using namespace std;

int r_dir[] = { -1, 0, 1, 0 };
int c_dir[] = { 0, 1, 0, -1 };

int R, C, SOL, d_safe;
int MAP[SIZE][SIZE], vvtd[SIZE][SIZE]; int tt;
int bx[1000], by[1000], vx[1000], vy[1000];  int bn, vn;

void __init__()
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
			MAP[i][j] = 1;
	}

	scanf("%d %d", &R, &C);
	bn = 0;
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			scanf("%d", &MAP[i][j]);
			if (MAP[i][j] == 0)
			{
				bx[++bn] = i;
				by[bn] = j;
			}

			else if (MAP[i][j] == 2)
			{ 
				vx[++vn] = i;
				vy[vn] = j;
			}
		}
	}
	d_safe = bn;
}

int spread()
{
	tt++;
	queue<pair<int, int> > q;
	for (int i = 1; i <= vn; i++)
	{
		q.push(make_pair(vx[i], vy[i])); vvtd[vx[i]][vy[i]] = tt;
	}

	int ret = 0;
	while (!q.empty())
	{
		pair<int, int> here = q.front(); q.pop();

		for (int i = 0; i < 4; i++)
		{
			int rr = here.first + r_dir[i], cc = here.second + c_dir[i];
			if (MAP[rr][cc] == 0 && vvtd[rr][cc] != tt) 
			{
				q.push(make_pair(rr, cc));	vvtd[rr][cc] = tt;
				ret++;
			}
		}
	}
	return ret;
}

void dfs(int now, int n)
{
	if (n > 3)
	{
		int temp = d_safe - 3 - spread();
		if (SOL < temp) SOL = temp;
 		return;
	}
	
	if (now > bn) return;

	MAP[bx[now]][by[now]] = 1;
	dfs(now + 1, n + 1);
	MAP[bx[now]][by[now]] = 0;
	dfs(now + 1, n);
}


int main(void)
{
	//freopen("input.txt", "r", stdin);
	__init__();
	SOL = -1;
	dfs(1, 1);
	printf("%d", SOL);
	return 0;
}
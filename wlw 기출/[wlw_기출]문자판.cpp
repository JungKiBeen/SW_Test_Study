#define _CRT_SECURE_NO_WARNINGS
#define NSIZE 111
#define MSIZE 111
#define ASIZE 100

#include<iostream>
#include<queue>
#include<stdio.h>
#include<string>
#include<utility>
using namespace std;
struct elem { int x, y, n; };
int N, M, K, SOL;
char MAP[NSIZE][MSIZE]; int vtd[NSIZE][MSIZE][100]; // 1.. M,N
string a; int an;

int r_dir[] = { -1, 0, 1, 0 }; int c_dir[] = { 0, 1, 0 ,-1 };

void input()
{
	SOL = 0;
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
			scanf(" %c", &MAP[i][j]);
	}
	cin >> a;
	an = (int)a.size();
}


void bfs()
{
	queue<elem> q;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (MAP[i][j] == a[0])
			{
				vtd[i][j][0] = 1;
				q.push({i, j, 0});
			}
		}
	}

	while (!q.empty())
	{
		elem here = q.front(); q.pop();
		if (here.n == an - 1 && MAP[here.x][here.y] == a[an - 1])
		{
			SOL += vtd[here.x][here.y][an-1];
			continue;
		}

		for (int i = 0; i < 4; i++)
		{
			for (int k = 1; k <= K; k++)
			{
				int xx = here.x + r_dir[i] * k; int yy = here.y + c_dir[i] * k;
				if (xx < 1 || xx > N || yy < 1 || yy> M) continue;

				if (MAP[xx][yy] == a[here.n + 1])
				{
					if (vtd[xx][yy][here.n + 1] != 0)
						vtd[xx][yy][here.n + 1] += vtd[here.x][here.y][here.n];
					else
					{
						vtd[xx][yy][here.n + 1] = vtd[here.x][here.y][here.n];
						q.push({ xx, yy, here.n + 1 });
					}

				}
			}
		}
	}
}

int main(void)
{
	//freopen("input.txt", "r", stdin);
	input();
	bfs();
	printf("%d", SOL);
	return 0;
}


#define _CRT_SECURE_NO_WARNINGS
#define MSIZE 55
#include <iostream>
#include<cstdio>
#include<climits>
#include<queue>
#include<utility>
using namespace std;

int r_dir[] = { -1, 0, 1, 0 }; int c_dir[] = { 0, 1, 0, -1 };

int N, M, SOL = INT_MAX;
char MAP[MSIZE][MSIZE];
int vtd[MSIZE][MSIZE], dist[MSIZE][MSIZE];
int sx[MSIZE*MSIZE], sy[MSIZE*MSIZE]; int sn;

void __init__()
{
	for (int i = 0; i < MSIZE; i++)
	{
		for (int j = 0; j < MSIZE; j++)
			MAP[i][j] = '!';
	}

	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
			scanf(" %1c", &MAP[i][j]);
	}
}

inline bool is_edge(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int xx = x + r_dir[i]; int yy = y + c_dir[i];
		if (MAP[xx][yy] == '.') return true;
	}
	return false;
}

void mk_y()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
			if (MAP[i][j] == 'X')
			{
				queue<pair<int, int> > q;

				MAP[i][j] = 'Y';
				q.push(make_pair(i, j));

				while (!q.empty())
				{
					pair<int, int> here = q.front(); q.pop();
					if (is_edge(here.first, here.second))
					{
						++sn, sx[sn] = here.first, sy[sn] = here.second;
					}

					for (int i = 0; i < 4; i++)
					{
						int xx = here.first + r_dir[i]; int yy = here.second + c_dir[i];

						if (MAP[xx][yy] == 'X')
						{
							MAP[xx][yy] = 'Y';
							q.push(make_pair(xx, yy));
						}
					}
				}
				return;
			}
	}
}

void bfs(int tt)
{
	queue<pair<int, int> > q;
	vtd[sx[tt]][sy[tt]] = tt;
	dist[sx[tt]][sy[tt]] = 0;
	q.push(make_pair(sx[tt], sy[tt]));

	while (!q.empty())
	{
		pair<int, int> here = q.front(); q.pop();
		int cost = dist[here.first][here.second];

		if (cost - 1 >= SOL) return;

		if (MAP[here.first][here.second] == 'X')
		{
			int lsol = cost - 1;
			SOL = (lsol < SOL) ? lsol : SOL;
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			int xx = here.first + r_dir[i]; int yy = here.second + c_dir[i];
			if ((vtd[xx][yy] != tt) && (MAP[xx][yy] == '.' || MAP[xx][yy] == 'X'))
			{
				vtd[xx][yy] = tt;
				dist[xx][yy] = cost + 1;
				q.push(make_pair(xx, yy));
			}
		}
	}
}

int main(void)
{
	//freopen("input.txt", "r", stdin);
	__init__();
	mk_y();
	for (int i = 1; i <= sn; i++)
	{
		bfs(i);
	}
	printf("%d", SOL);
	return 0;
}
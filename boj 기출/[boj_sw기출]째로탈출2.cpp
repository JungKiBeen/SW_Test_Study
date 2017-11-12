#define _CRT_SECURE_NO_WARNINGS
#define MSIZE 15
#define IS_WALL(xx, yy, i) (MAP[(xx) + r_dir[(i)]][(yy) + c_dir[(i)]] == '#')
#define IS_HOLE(xx, yy) (MAP[(xx)][(yy)] == 'O')
#define CALC_DIST(x,y,xx,yy) (abs((x)-(xx)) + abs((y)-(yy)))
#include<iostream>
#include<cstdio>
#include<climits>
#include<queue>
#include<utility>
#include<cmath>
using namespace std;

struct state
{
	int rx, ry, bx, by;
};

int r_dir[] = { -1, 0, 1, 0 }; int c_dir[] = { 0, 1, 0, -1 };

char MAP[MSIZE][MSIZE];
int R, C, srx, sry, sbx, sby;
int dist[MSIZE][MSIZE][MSIZE][MSIZE];

void __init__()
{
	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			scanf(" %c", &MAP[i][j]);
			if (MAP[i][j] == 'R')
			{
				srx = i, sry = j;
				MAP[i][j] = '.';
			}

			else if (MAP[i][j] == 'B')
			{
				sbx = i, sby = j;
				MAP[i][j] = '.';
			}
		}
	}
}


void bfs()
{
	queue <state> q;
	state here;
	dist[srx][sry][sbx][sby] = 1;
	here.rx = srx; here.ry = sry; here.bx = sbx; here.by = sby;
	q.push(here);

	while (!q.empty())
	{
		here = q.front(); q.pop();
		int rx = here.rx; int ry = here.ry; int bx = here.bx; int by = here.by;
		int cost = dist[rx][ry][bx][by];

		if (MAP[bx][by] == 'O' || cost - 1 > 10) continue;
		if (MAP[rx][ry] == 'O')
		{
			printf("%d", cost - 1);
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			bool rmove = true, bmove = true;
			int rxx = rx; int ryy = ry;
			int bxx = bx; int byy = by;

			while (!IS_WALL(rxx, ryy, i) && !IS_HOLE(rxx, ryy))
			{
				rxx += r_dir[i], ryy += c_dir[i];
			}

			while (!IS_WALL(bxx, byy, i) && !IS_HOLE(bxx, byy))
			{
				bxx += r_dir[i], byy += c_dir[i];
			}
			
			if (rxx == bxx && ryy == byy && MAP[rxx][ryy] != 'O')
			{
				if (CALC_DIST(rx, ry, rxx, ryy) > CALC_DIST(bx, by, bxx, byy))
				{
					rxx -= r_dir[i], ryy -= c_dir[i];
				}

				else
				{
					bxx -= r_dir[i], byy -= c_dir[i];
				}
			}

			if (dist[rxx][ryy][bxx][byy] ==0)
			{
				state there; 
				there.rx = rxx, there.ry = ryy, there.bx = bxx, there.by = byy;
				dist[rxx][ryy][bxx][byy] = cost + 1;
				q.push(there);
			}
		}
	}

	printf("%d", -1);
}

int main(void)
{
	//freopen("input.txt", "r", stdin);
	__init__();
	bfs();
	return 0;
}
// 1) bfs 리턴 값으로 벡터를 채우는 과정에서 뭔가 이상이 발생함..; 원인은 모르겠음

#define _CRT_SECURE_NO_WARNINGS
#define MSIZE 111

#include<utility>
#include <iostream>
#include<queue>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int r_dir[] = { -1, 0, 1, 0 }; int c_dir[] = { 0, 1, 0, -1 };

int MAP[MSIZE][MSIZE];
vector<int> tsol;
int R, C, K, tt; // M = R, N = C

inline void chil(int x1, int y1, int x2, int y2)
{
	for (int i = x1; i <= x2; i++)
	{
		for (int j = y1; j <= y2; j++)
			MAP[i][j] = -1;
	}
}

void __init__()
{
	tsol = vector<int>(10000);
	scanf("%d %d %d", &R, &C, &K);
	for (int i = 1; i <= K; i++)
	{
		int lux, luy, rdx, rdy;
		scanf("%d %d %d %d", &luy, &lux, &rdy, &rdx);
		chil(lux + 1, luy + 1, rdx, rdy);
	}
}

void bfs(int srcx, int srcy)
{
	++tt;
	int lsol = 0;
	queue<pair<int, int> > q;
	q.push(make_pair(srcx, srcy));
	MAP[srcx][srcy] = tt;  // MAP[x][y] == tt이면 방문함

	while (!q.empty())
	{
		pair<int, int> here = q.front(); q.pop();
		lsol++;

		for (int i = 0; i < 4; i++)
		{
			int rr = here.first + r_dir[i]; int cc = here.second + c_dir[i];
			if (rr < 1 || rr > R || cc < 1 || cc > C) continue;

			if (MAP[rr][cc] == 0)
			{
				MAP[rr][cc] = tt;
				q.push(make_pair(rr, cc));
			}
		}
	}
	tsol[tt - 1] = lsol;
}



int main(void)
{
	//freopen("input.txt", "r", stdin);
	__init__();
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			if (MAP[i][j] == 0)
				bfs(i, j);
		}
	}

	sort(tsol.begin(), tsol.begin() + tt);

	printf("%d\n", tt);
	for (int i = 0; i < tt; i++)
	{
		printf("%d", tsol[i]);
		if (i != tt - 1) printf(" ");
	}

	return 0;
}
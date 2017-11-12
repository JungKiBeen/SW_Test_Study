#define _CRT_SECURE_NO_WARNINGS
#define SIZE 111

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int miro[SIZE][SIZE];
int cost[SIZE][SIZE];

int row, col, srow, scol, frow, fcol;

int r_dir[] = { -1, 0, 1, 0 };
int c_dir[] = { 0, 1, 0, -1 };

struct pos
{
	int r;
	int c;
};

int bfs()
{
	queue<pos> q;
	pos t;
	t.r = srow; t.c = scol;
	q.push(t);
	cost[srow][scol] = 1;

	while (!q.empty())
	{
		pos here = q.front();	q.pop();

		if (here.r == frow && here.c== fcol)
			return cost[here.r][here.c] - 1;

		for (int i = 0; i < 4; i++)
		{
			pos there;
			there.r = here.r + r_dir[i], there.c = here.c + c_dir[i];
			if (there.r  < 1 || there.r  > row || there.c < 1 || there.c > col)	continue;
			if (miro[there.r][there.c] == 0 && cost[there.r][there.c] == 0)
			{
				cost[there.r][there.c] = cost[here.r][here.c] + 1;
				q.push(there);
			}
		}
	}
	return -1;
}


void __init__()
{
	cin >> col >> row;
	cin >> scol >> srow >> fcol >> frow;

	for (int i = 1; i <= row; ++i)
	{
		for (int j = 1; j <= col; ++j)
			scanf("%1d", &miro[i][j]);
	}

}
int main(void)
{
	//freopen("input.txt", "r", stdin);
	__init__();

	cout << bfs();
	return 0;
}
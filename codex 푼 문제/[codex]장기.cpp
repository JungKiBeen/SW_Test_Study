#define _CRT_SECURE_NO_WARNINGS
#define SIZE 111
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int ROW, COL, mr, mc, jr, jc;
int cost[SIZE][SIZE];	// 1.1 부터 시작

int r_dir[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int c_dir[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

void __init__()
{
	scanf("%d %d", &ROW, &COL);
	scanf("%d %d %d %d", &mr, &mc, &jr, &jc);
}

int bfs()
{
	queue<pair<int, int>> q;
	q.push(make_pair(mr, mc));
	cost[mr][mc] = 1;

	while (!q.empty())
	{
		pair<int, int> here = q.front();	q.pop();
		if (here.first == jr && here.second == jc)
			return cost[jr][jc] - 1;

		for (int i = 0; i < 8; i++)
		{
			pair<int, int> there;
			there.first = here.first + r_dir[i];	there.second = here.second + c_dir[i];

			if (there.first < 1 || there.first > ROW || there.second < 1 || there.second > COL)
				continue;

			if (cost[there.first][there.second] == 0)
			{
				cost[there.first][there.second] = cost[here.first][here.second] + 1;
				q.push(make_pair(there.first, there.second));
			}
		}
	} // while
	return -1;
}


int main(void)
{
	__init__();
	printf("%d", bfs());
	return 0;
}

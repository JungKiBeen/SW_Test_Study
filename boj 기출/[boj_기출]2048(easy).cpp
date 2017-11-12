#define _CRT_SECURE_NO_WARNINGS
#define NSIZE 25

#include<iostream>
#include <stdio.h>
#include<queue>
using namespace std;

int N, SOL;
int mmap[NSIZE][NSIZE]; // 1.. N




void merge(int dir)
{
	queue<int> q;

	switch (dir)
	{
	case 0:
		for (int y = 1; y <= N; y++)
		{
			for (int x = 1; x <= N; x++)
			{
				if (mmap[x][y] != 0)
					q.push(mmap[x][y]);

				mmap[x][y] = 0;
			}

			int idx = 1;
			while (!q.empty())
			{
				int val = q.front(); q.pop();

				if (mmap[idx][y] == 0)
					mmap[idx][y] = val;

				else if (mmap[idx][y] == val)
				{
					mmap[idx][y] *= 2;
					idx++;
				}

				else mmap[++idx][y] = val;
			}
		}
		break;

	case 1:
		for (int x = 1; x <= N; x++)
		{
			for (int y = N; y >= 1; y--)
			{
				if (mmap[x][y] != 0)
					q.push(mmap[x][y]);
				mmap[x][y] = 0;
			}
			int idx = N;
			while (!q.empty())
			{
				int val = q.front(); q.pop();
				if (mmap[x][idx] == 0)
					mmap[x][idx] = val;

				else if (mmap[x][idx] == val)
				{
					mmap[x][idx] *= 2;
					idx--;
				}
				else
					mmap[x][--idx] = val;
			}
		}

		break;
	case 2:
		for (int y = 1; y <= N; y++)
		{
			for (int x = N; x >= 1; x--)
			{
				if (mmap[x][y] != 0)
					q.push(mmap[x][y]);
				mmap[x][y] = 0;
			}

			int idx = N;
			while (!q.empty())
			{
				int val = q.front(); q.pop();
				if (mmap[idx][y] == 0)
					mmap[idx][y] = val;

				else if (mmap[idx][y] == val)
				{
					mmap[idx][y] *= 2;
					idx--;
				}
				else
					mmap[--idx][y] = val;
			}
		}
		break;

	case 3:
		for (int x = 1; x <= N; x++)
		{
			for (int y = 1; y <= N; y++)
			{
				if (mmap[x][y] != 0)
					q.push(mmap[x][y]);
				mmap[x][y] = 0;
			}


			int idx = 1;
			while (!q.empty())
			{
				int val = q.front(); q.pop();
				if (mmap[x][idx] == 0)
					mmap[x][idx] = val;

				else if (mmap[x][idx] == val)
				{
					mmap[x][idx] *= 2;
					idx++;
				}
				else
					mmap[x][++idx] = val;
			}

		}
		break;
	} // switch

}

void copy(int(*arr)[NSIZE], int(*arr2)[NSIZE]) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			arr[i][j] = arr2[i][j];
		}
	}
}

void dfs(int n)
{
	if (n == 5)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (mmap[i][j] > SOL) SOL = mmap[i][j];
			}

		}
		return;
	}

	int cmmap[NSIZE][NSIZE];
	copy(cmmap, mmap);
	for (int dir = 0; dir < 4; dir++)
	{
		merge(dir);
		dfs(n + 1);
		copy(mmap, cmmap);

	} // for
}
void input()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			scanf("%d", &mmap[i][j]);
	}
}



int main()
{
	//	freopen("input.txt", "r", stdin);
	input();
	dfs(0);
	printf("%d\n", SOL);
	return 0;
}
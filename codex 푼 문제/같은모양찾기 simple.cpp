#define _CRT_SECURE_NO_WARNINGS
#define SIZE 111
#include <iostream>
#include <cstdio>

using namespace std;

int M, P;

int r_dir[] = { -1, 0, 1, 0 };
int c_dir[] = { 0, 1, 0, -1 };

int monu[SIZE][SIZE];
int pat[SIZE][SIZE];

void __init__()
{
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
			scanf("%1d", &monu[i][j]);
	}

	scanf("%d", &P);
	for (int i = 0; i < P; i++)
	{
		for (int j = 0; j < P; j++)
			scanf("%1d", &pat[i][j]);
	}
}

int equal(int r, int c)
{
	if (r + P - 1 < 0 || r + P - 1 >= M || c + P - 1 < 0 || c + P - 1 >= M)
		return 0;

	for (int row = r; row < r + P; row++)
	{
		for (int col = c; col < c + P; col++)
			if (monu[row][col] != pat[row - r][col - c])
				return 0;
	}

	return 1;
}

int sol()
{
	int ret = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
			ret += equal(i, j);
	}
	return ret;
}

int main(void)
{
	__init__();

	// 출력하는 부분
	printf("%d", sol());

	return 0;
}
#define SIZE 111
#include <iostream>
#include <cstdio>

using namespace std;

int dowha[SIZE][SIZE];
int n;

void sack(int r, int c)
{
	for (int i = r; i < r + 10; i++)
	{
		for (int j = c; j < c + 10; j++)
			dowha[i][j] = 1;
	}
}

int sol()
{
	int ret = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
			if (dowha[i][j]) ret++;
	}
	return ret;
}

int main(void)
{
	int i;

	// 입력받는 부분
	scanf("%d", &n);
	for (i = 0; i<n; i++)
	{
		int r, c;
		scanf("%d %d", &c, &r);
		sack(r, c);
	}

	// 출력하는 부분
	printf("%d", sol());

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#define MSIZE 8
#define LMTD (25 - K + 1)
#define IS_VTD ((hx == yx) && (hy == yy))
//#define IS_NVALID(x,y) ((x) < 1 || (x) > 5 || (y) < 1 || (y) > 5)

#include <iostream>
#include<cstdio>

using namespace std;

int r_dir[] = { -1, 0, 1, 0 };
int c_dir[] = { 0, 1, 0, -1 };

int K, SOL;
char MAP[MSIZE][MSIZE]; 

void __init__()
{
	scanf("%d", &K);
	for (int i = 0; i <= MSIZE; i++)
		for (int j = 0; j <= MSIZE; j++)
			MAP[i][j] = '!';

	for (int i = 1; i <= 5; i++)
		for (int j = 1; j <= 5; j++)
			MAP[i][j] = '.';

	for (int i = 1; i <= K; i++)
	{
		int kx, ky;
		scanf("%d %d", &kx, &ky);
		MAP[kx][ky] = 'x';
	}
}

void dfs(int hx, int hy, int yx, int yy, int namu)
{
	if (namu == LMTD && IS_VTD)
	{
		SOL++;
	}

	else if (!(namu == LMTD) && IS_VTD) return; // 만나지 않고서 도달할 수 있는 최대 나무 수는 LMTD - 2이다. 그 이상은 진전이 안되므로 리턴을 할 필요 없음

	for (int i = 0; i < 4; i++)
	{
		int hxx = hx + r_dir[i]; int hyy = hy + c_dir[i];
		//if (IS_NVALID(hxx, hyy)) continue;

		if (MAP[hxx][hyy] == '.')
		{
			for (int j = 0; j < 4; j++)
			{
				int yxx = yx + r_dir[j]; int yyy = yy + c_dir[j];
				//if (IS_NVALID(yxx, yyy)) continue;

				if (MAP[yxx][yyy] == '.')
				{
					MAP[hxx][hyy] = 'h';
					MAP[yxx][yyy] = 'y';
					dfs(hxx, hyy, yxx, yyy, namu + 2);
					MAP[hxx][hyy] = '.';
					MAP[yxx][yyy] = '.';
				}
			}
		}
	}
}

int main(void)
{
	//freopen("input.txt", "r", stdin);
	__init__();
	MAP[1][1] = 'h';
	MAP[5][5] = 'y';
	dfs(1, 1, 5, 5, 2);
	printf("%d", SOL);
	return 0;
}
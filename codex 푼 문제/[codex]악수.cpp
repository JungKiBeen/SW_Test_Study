#define _CRT_SECURE_NO_WARNINGS
#define SIZE 55
#include <iostream>
#include <cstdio>
#include <utility>

using namespace std;

int R, C;
char map[SIZE][SIZE];
bool visited[SIZE][SIZE];

int r_dir[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int c_dir[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int check(int r, int c)
{
	int ret = 0;
	for (int i = 0; i < 8; i++)
	{
		int rr = r + r_dir[i]; int cc = c + c_dir[i];
		if (rr < 0 || rr >= R || cc < 0 || cc >= C)
			continue;

		if (map[rr][cc] == 'o')
			ret++;
	}
	return ret;
}

int aksu()
{
	int ret = 0;
	for (int r = 0; r < R; r++)
	{
		for (int c = 0; c < C; c++)
		{
			if (map[r][c] == 'o')
			{
				visited[r][c] = true;
				for (int i = 0; i < 8; i++)
				{
					int rr = r + r_dir[i]; int cc = c + c_dir[i];
					if (rr < 0 || rr >= R || cc < 0 || cc >= C)
						continue;

					if (!visited[rr][cc] && map[rr][cc] == 'o')
						ret++;
				}
			}
		}
	}
	return ret;
}

int sol()
{
	int MAX = -1;
	pair<int, int> pos;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
			if (map[i][j] == '.')
			{
				int cnt = check(i, j);
				if (cnt > MAX)
				{
					MAX = cnt;
					pos.first = i, pos.second = j;
				}
				if (cnt == 8) goto exit;
			}
	}

exit:
	if (MAX != -1) map[pos.first][pos.second] = 'o';

	return aksu();
}

int main(void)
{
	cin >> R >> C;

	for (int i = 0; i < R; i++)
		scanf("%s", map[i]);

	cout << sol();
	return 0;
}
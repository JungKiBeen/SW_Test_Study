#define _CRT_SECURE_NO_WARNINGS
#define SIZE 111
#define AP 2

#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

int r_dir[] = { -1, 0, 1, 0 };
int c_dir[] = { 0, 1, 0, -1 };

queue<pair<long long, char> > hq, tq;

int MAP[SIZE][SIZE];
int N, apple, comm; long long SEC;
int hx, hy, hd, tx, ty, td, len;

void __init__()
{
	len = 1;
	hx = 1, hy = 1, tx = 1, ty = 1;  hd = 1, td = 1;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			MAP[i][j] = 1;
	}
	//MAP[1][1] = 0;

	scanf("%d", &apple);
	for (int i = 1; i <= apple; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		MAP[x][y] = AP;
	}

	scanf("%d", &comm);
	for (int i = 1; i <= comm; i++)
	{
		long long s; char c;
		scanf("%lld %c", &s, &c);
		hq.push(make_pair(s, c));
	}
}

void set_dir()
{
	if (!hq.empty() && hq.front().first == SEC)
	{
		char c = hq.front().second; hq.pop();
		tq.push(make_pair(SEC + len - 1, c));
		if (c == 'D')
			hd = (hd + 1) % 4;

		else
		{
			hd--; if (hd == -1) hd = 3;
		}
	}

	if (!tq.empty() && tq.front().first == SEC)
	{
		char c = tq.front().second; tq.pop();
		if (c == 'D') // ¿À¸¥ÂÊ
			td = (td + 1) % 4;

		else
		{
			td--; if (td == -1) td = 3;
		}
	}
}

long long solve()
{
	SEC = 0;
	while(true)
	{
		hx = hx + r_dir[hd];  hy = hy + c_dir[hd];
		if (MAP[hx][hy] == 0)
			return SEC + 1;

		if (MAP[hx][hy] == AP) 
		{
			len++;
			if (!tq.empty())
			{
				queue<pair<long long, char> > temp;
				while (!tq.empty())
				{
					pair<long long, char> t = tq.front(); tq.pop();
					t.first = t.first + 1;
					temp.push(t);
				}
				tq = temp;
			}
		}
		else
		{
			MAP[tx][ty] = 1;
			tx = tx + r_dir[td];  ty = ty + c_dir[td];
		}

		MAP[hx][hy] = 0;
		SEC++;
		set_dir();
	}
	return -1;
}

int main(void)
{
	//freopen("input.txt", "r", stdin);
	__init__();
	printf("%lld", solve());
}
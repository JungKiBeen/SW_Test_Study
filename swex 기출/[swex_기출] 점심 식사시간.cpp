#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<queue>
#include<vector>
#include<algorithm>
#include<limits.h>

using namespace std;

struct elem
{
	int d1, d2;
};

int MAP[15][15];
int N, MIN;
int kx[3], ky[3], kk[3]; int kn;
int px[15], py[15], choice[15]; int pn;
elem pd[15];


inline int calc_dist(int i, int x, int y)
{
	return abs(x - kx[i]) + abs(y - ky[i]) + 1;
}

void input()
{
	MIN = INT_MAX;
	pn = 0, kn = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &MAP[i][j]);
			if (MAP[i][j] == 1)
			{
				++pn;
				px[pn] = i, py[pn] = j;
			}

			else if (MAP[i][j] > 1)
			{
				++kn;
				kx[kn] = i, ky[kn] = j, kk[kn] = MAP[i][j];
			}
		}
	}

	for (int i = 1; i <= pn; i++)
	{
		pd[i].d1 = calc_dist(1, px[i], py[i]);
		pd[i].d2 = calc_dist(2, px[i], py[i]);
	}

}
int solve()
{
	vector<int> arr1, arr2, s1(4, 0), s2(4, 0);
	queue<int> q1, q2;

	for (int i = 1; i <= pn; i++)
	{
		if (choice[i] == 1) arr1.push_back(pd[i].d1);
		else arr2.push_back(pd[i].d2);
	}

	sort(arr1.begin(), arr1.end());
	sort(arr2.begin(), arr2.end());

	for (int i = 0; i < (int)arr1.size(); i++)	q1.push(arr1[i]);
	for (int i = 0; i < (int)arr2.size(); i++)	q2.push(arr2[i]);

	int tm = 0;
	int cnt = 0;
	
	while (cnt != pn)
	{
		for (int i = 1; i <= 3; i++)
		{
			if (s1[i] > 0)
			{
				if (--s1[i] == 0) cnt++;
			}

			if (s1[i] == 0)
			{
				if (!q1.empty() && q1.front() <= tm)
				{
					q1.pop(); s1[i] = kk[1];
				}
			}

			if (s2[i] > 0)
			{
				if (--s2[i] == 0) cnt++;
			}

			if (s2[i] == 0)
			{
				if (!q2.empty() && q2.front() <= tm)
				{
					q2.pop(); s2[i] = kk[2];
				}
			}
		
		} // for

		tm++;
	} // while

	return tm - 1;
}

void dfs(int n)
{
	if (n == pn + 1)
	{
		MIN = min(MIN, solve());
		return;
	}

	choice[n] = 1;
	dfs(n + 1);

	choice[n] = 2;
	dfs(n + 1);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	
	for (int tc = 1; tc <= T; tc++)
	{
		input();
		dfs(1);
		printf("#%d %d\n", tc, MIN);
	}

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

struct elem
{
	int n, t;
};

int CN, PN, K, A, B;
int a[11], b[11];
elem cs[1111];

void input()
{
	scanf("%d %d %d %d %d", &CN, &PN, &K, &A, &B);
	for (int i = 1; i <= CN; i++) scanf("%d", &a[i]);
	for (int j = 1; j <= PN; j++) scanf("%d", &b[j]);
	for (int k = 1; k <= K; k++) { scanf("%d", &cs[k].t); cs[k].n = k; }
}

// 도착시간이 작거나 OR 도착시간이 같으면 고객번호가 낮을수록 우선순위가 높다
void mk_rcq(queue<elem> &rcq)
{
	for (int i = 1; i < K; i++)
	{
		int MIN = i;
		for (int j = i + 1; j <= K; j++)
		{
			if (cs[j].t < cs[i].t || (cs[j].t == cs[i].t && cs[j].n < cs[i].n))
				MIN = j;
		}

		swap(cs[MIN], cs[i]);
	}

	for (int i = 1; i <= K; i++)
		rcq.push(cs[i]);
}

int solve()
{
	queue<elem> rcq;
	queue<int> rpq;
	vector<elem> rec(11), rep(11);
	vector<int> sol_rec(K + 5), sol_rep(K + 5);

	mk_rcq(rcq);
	
	int tm = rcq.front().t, cnt = 0;
	while (cnt != K)
	{
		for (int i = 1; i <= CN; i++)
		{
			if (rec[i].t > 0)
			{
				if (--rec[i].t == 0)
				{
					rpq.push(rec[i].n);
					rec[i].n = 0;
				}
			}
			if (rec[i].t == 0)
			{
				if (!rcq.empty() && rcq.front().t <= tm)
				{
					sol_rec[rcq.front().n] = i;
					rec[i].n = rcq.front().n; rcq.pop();
					rec[i].t = a[i];
				}
			}
		}

		for (int i = 1; i <= PN; i++)
		{
			if (rep[i].t > 0)
			{
				if (--rep[i].t == 0)
				{
					++cnt;
					rep[i].n = 0;
				}
			}
			if (rep[i].t == 0)
			{
				if (!rpq.empty())
				{
					sol_rep[rpq.front()] = i;
					rep[i].n = rpq.front(); rpq.pop();
					rep[i].t = b[i];
				}
			}
		}
		++tm;
	}
	
	int ret = 0;
	for(int i = 1; i <= K; i++)
	{
		if (sol_rec[i] == A && sol_rep[i] == B) ret += i;
	}
	if (ret == 0) ret = -1;
	return ret;
}

int main()
{
	freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++)
	{
		input();
		printf("#%d %d\n", tc, solve());
	}

	return 0;
}
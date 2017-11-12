#define _CRT_SECURE_NO_WARNINGS
#define DSIZE 3333
#define NSIZE 3333333
#define INCR() ptr = (ptr + 1) % N
#define UPDATE_SOL() SOL = max(SOL, LSOL + ((vtd[c]) ? 0 : 1));

#include <iostream>
#include<cstdio>
#include<climits>
#include<queue>
#include<algorithm>

using namespace std;

int vtd[DSIZE]; short belt[NSIZE]; int ptr;
queue<int> q;
int N, d, k, c;

void __init__()
{
	ptr = -1;
	scanf("%d %d %d %d", &N, &d, &k, &c);
	for (int i = 0; i < N; i++)
		scanf("%hd", &belt[i]);
}

int solve()
{
	int SOL = -1, LSOL = 0, finish;
		
	for (int i = 0; i < k; i++)
	{
		INCR();
		q.push(belt[ptr]);
		if (vtd[belt[ptr]] == 0) LSOL++;
		vtd[belt[ptr]]++;
	}
	UPDATE_SOL();
	finish = ptr; 	INCR();

	while (ptr != finish)
	{
		int prev = q.front(); q.pop();
		vtd[prev]--;
		if (vtd[prev] == 0) LSOL--;

		q.push(belt[ptr]);
		if (vtd[belt[ptr]] == 0) LSOL++;
		vtd[belt[ptr]]++;

		UPDATE_SOL();
		INCR();
	}
	return SOL;
}

int main(void)
{
	__init__();
	printf("%d", solve());
	return 0;
}


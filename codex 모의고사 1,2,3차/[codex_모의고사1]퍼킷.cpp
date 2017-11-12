#define _CRT_SECURE_NO_WARNINGS
#define NSIZE 13
#include <iostream>
#include<algorithm>
#include<climits>
#include<cstdio>
using namespace std;

int N; long long SOL = LLONG_MAX;
long long ns[NSIZE], nb[NSIZE];

void dfs(int i, long long s, long long b, bool flag)
{
	if (i == N + 1)
	{
		if (flag)
			SOL = min(SOL, llabs(s - b));
		return;
	}
	
	dfs(i + 1, s * ns[i], b + nb[i], true);
	dfs(i + 1, s, b, flag);
}

void __init__()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%lld %lld", &ns[i], &nb[i]);
}

int main(void)
{
	__init__();
	dfs(1, 1, 0, false);
	printf("%lld", SOL);
	return 0;
}
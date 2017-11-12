#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
using namespace std;

int N, chong, sub;
int ai[1000000 + 10];

void __init__()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &ai[i]);

	scanf("%d %d", &chong, &sub);
}

long long solve()
{
	long long ret = 0;
	for (int i = 1; i <= N; i++)
	{
		ai[i] -= chong;
		ret++;
		if (ai[i] > 0)
		{
			ret += (ai[i] / sub);
			if (ai[i] % sub) ret++;
		}
	}
	return ret;
}

int main(void)
{
	//freopen("input.txt", "r", stdin);
	__init__();
	printf("%lld", solve());
	return 0;
}


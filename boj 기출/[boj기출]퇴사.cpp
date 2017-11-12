#define SIZE 55
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<climits>
using namespace std;

int N, SOL;
int ti[SIZE], pi[SIZE];

void __init__()
{
	SOL = -1;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d %d", &ti[i], &pi[i]);
}

void dfs(int n, int sum)
{
	if (n > N)
	{
		if ( (n == (N+1)) && (sum > SOL)) SOL = sum;
		return;
	}

	dfs(n + ti[n], sum + pi[n]);
	dfs(n + 1 , sum);
}

int main(void)
{
	//freopen("input.txt", "r", stdin);
	__init__();
	dfs(1, 0);
	printf("%d", SOL);
	return 0;
}
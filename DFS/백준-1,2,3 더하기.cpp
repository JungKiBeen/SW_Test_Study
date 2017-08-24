#include<iostream>
#include<cstdio>
#include <algorithm>
#include<queue>
#include<cstring>
#include <string>
using namespace std;

int k;
int sol;

void DFS(int n, int sum)
{
	if (sum >= k)
	{
		if (sum == k)	sol++;
		return;
	}
	
	for (int i = 1; i <= 3; i++)
	{
		DFS(n + 1, sum + i);
	}
}

int main()
{
	freopen("a.txt","r", stdin);
	int t;
	cin >> t;

	while (t--)
	{
		sol = 0;
		scanf("%d", &k);
		DFS(0, 0);
		printf("%d\n", sol);
	}
	return 0;
}
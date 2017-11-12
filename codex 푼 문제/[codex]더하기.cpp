#define _CRT_SECURE_NO_WARNINGS
#define SIZE 22
#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>

using namespace std;

bool sol;	int N, K;
int di[SIZE];

void dfs(int i, int sum)
{
	if (sum > K) return;
	if (i == N)
	{
		if (sum == K)
			sol = true;
		return;
	}

	dfs(i + 1, sum + di[i]);
	if (sol) return;
	dfs(i + 1, sum);
	if (sol) return;
}


int main(void)
{
	int T;
	cin >> T;
	
	while (T--)
	{
		cin >> N >> K;
		sol = false;
		for (int i = 0; i < N; i++)
			scanf("%d", &di[i]);

		dfs(0, 0);
		if (sol) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}
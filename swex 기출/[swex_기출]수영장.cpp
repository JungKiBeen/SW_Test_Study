#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<cstdio>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

int day, mon, tmon, year;
int use[13];
int MIN;

void dfs(int n, int pay)
{
	if (n >= 13)
	{
		MIN = min(MIN, pay);
		return;
	}

	dfs(n + 1, pay + use[n] * day);
	dfs(n + 1, pay + mon);
	dfs(n + 3, pay + tmon);
}

void __init__()
{
	MIN = INT_MAX;
	cin >> day >> mon >> tmon >> year;
	for (int i = 1; i < 13; i++)
		cin >> use[i];
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	freopen("sample_input.txt", "r", stdin);

	int T; cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		__init__();
		dfs(1, 0);
		cout << "#" << tc << " " << min(year, MIN) << "\n";
	}

	return 0;
}
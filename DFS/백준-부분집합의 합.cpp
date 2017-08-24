/*
<어려웠던 점>

1. 공집합을 flag로 구분해내는 것이 좀 어려웠음



*/





#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int N, S, SOL = 0;
vector<int> a(20);


void DFS(int n, int sum, bool flag)
{
	if (n == N)
	{
		if (sum == S && flag) SOL++;

		return;
	}

	DFS(n + 1, sum, flag);	// n번째 인덱스 포함 안함
	DFS(n + 1, sum + a[n], true);	// n번째 인덱스 포함
}

int main()
{
	//freopen("a.txt", "r", stdin);
	cin >> N >> S;

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}

	DFS(0,0, false);

	cout << SOL;
	return 0;
}
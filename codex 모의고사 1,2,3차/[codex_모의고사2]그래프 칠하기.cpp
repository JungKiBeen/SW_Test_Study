#define _CRT_SECURE_NO_WARNINGS
#define NON 0
#define NSIZE 15
#include <iostream>
#include<vector>
using namespace std;

vector<int> adj[NSIZE];
int slist[NSIZE]; int max_sack;
int N, M;

void __init__()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			int temp;
			scanf("%d", &temp);
			if (temp == 1)
			{
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
}

bool flag = false;
void dfs(int n, int sack)
{
	if (n == N + 1)
	{
		flag = true;
		return;
	}

	int len = (int)adj[n].size();
	for (int i = 0; i < len; i++)
	{
		if (slist[adj[n][i]] == sack)	// 인접 노드가 같은 색이면 가지치기
			return;
	}

	for (int i = 1; i <= M; i++)
	{
		slist[n + 1] = i;
		dfs(n + 1, i);
		if (flag) return;
		slist[n + 1] = NON;
	}
}

int main(void)
{
	//freopen("input.txt", "r", stdin);
	__init__();
	slist[1] = 1;
	dfs(1, 1);

	if (flag)
	{
		for (int i = 1; i <= N; i++) printf("%d ", slist[i]);
	}
	
	else
	{
		printf("%d", -1);
	}

	return 0;
}

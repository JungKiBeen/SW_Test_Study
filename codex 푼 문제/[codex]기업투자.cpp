#define _CRT_SECURE_NO_WARNINGS
#define SIZE 55

#include<iostream>
#include<cstdio>
#include<climits>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<cstring>

using namespace std;

int limit, N;
int table[SIZE][SIZE];
long long d[SIZE][SIZE];
int prev_j[SIZE][SIZE];

void __init__()
{
	memset(d, -1, sizeof(d));
	scanf("%d", &limit);
	scanf("%d", &N);
	for (int i = 1; i <= limit; i++)
	{
		int tuja;	scanf("%d", &tuja);
		for (int j = 1; j <= N; j++)
			scanf("%d", &table[tuja][j]);
	}
}

void show_path(int last_i, int last_j)
{
	vector<int> path(N+10);

	while (last_i)
	{
		path[last_i] = last_j - prev_j[last_i][last_j];
		last_j = prev_j[last_i][last_j];
		last_i--;
	}

	for (int i = 1; i <= N; i++)
		printf("%d ", path[i]);

}

void memo()
{
	for (int i = 0; i <= limit; i++)
		d[1][i] = table[i][1];

	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j <= limit; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				long long temp = d[i - 1][k] + table[j - k][i];
				if (d[i][j] < temp)
				{
					d[i][j] = temp;
					prev_j[i][j] = k;
				}
			}
				
		}
	}

	long long sol =  -1;
	int last_j;
	for (int i = 0; i <= limit; i++)
	{
		if (sol < d[N][i])
		{
			sol = d[N][i];
			last_j = i;
		}
	}

	printf("%lld\n", sol);
	show_path(N, last_j);
}



int main(void)
{
//	freopen("input.txt", "r", stdin);
	__init__();
	memo();
	return 0;
}


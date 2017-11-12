// d[i][j] : i번째 정비소에서 j km 이동하였을 때 최소 총 정비비용
// *초기 조건 d[1][0] = cost[1];		d[1][dist[1]] = 0;
// *재귀식 : limit을 초과하지 않는 (0 부터 limit-dist[i+1] 이동 거리) d[i][j]에 대하여
//          d[i + 1][0] = min(d[i + 1][0], d[i][j] + cost[i + 1])    ; 방문한 상황
//         	d[i + 1][j + dist[i + 1]] = d[i][j]     ; 방문하지 않은 상황
//  * d[i][j]에 대하여 방문한 상황, 방문하지 않은 상황을 모두 고려하였으므로 옳은 설계이다
//  * d[i][(limit - dist[i+1] +1) .. limit]은 소실되지 않는가? 이는 어짜피 잘못된 가정의 d값이다
//  * 오버플로우로 인하여 d[i][j] == INT_MAX 일 경우 continue로 처리하였음

#define SIZE 55
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;

int limit, N;
int dist[SIZE], cost[SIZE];
vector<vector<int> > d;
void __init__()
{
	scanf("%d", &limit);
	scanf("%d", &N);
	for (int i = 1; i <= N + 1; i++)
		scanf("%d", &dist[i]);
	
	for (int i = 1; i <= N; i++)
		scanf("%d", &cost[i]);
	d = vector<vector<int> >(N + 10, vector<int>(limit + 10, INT_MAX));
}

int memo()
{
	d[1][0] = cost[1];		d[1][dist[1]] = 0;

	for (int i = 1; i <= N; i++)
	{
		int t = limit - dist[i + 1];
		for (int j = 0; j <= t; j++)
		{
			if (d[i][j] == INT_MAX) continue;
			d[i + 1][0] = min(d[i + 1][0], d[i][j] + cost[i + 1]);
			d[i + 1][j + dist[i + 1]] = d[i][j];
		}
	}

	int ret = INT_MAX;
	for (int j = 0; j <= limit; j++)
	{
		ret = min(ret, d[N + 1][j]);
	}
	return ret;
}


int main(void)
{
	//freopen("input.txt", "r", stdin);
	__init__();
	cout << memo();
	return 0;
}
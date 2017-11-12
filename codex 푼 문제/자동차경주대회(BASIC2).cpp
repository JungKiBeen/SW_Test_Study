// d[i][j] : i��° ����ҿ��� j km �̵��Ͽ��� �� �ּ� �� ������
// *�ʱ� ���� d[1][0] = cost[1];		d[1][dist[1]] = 0;
// *��ͽ� : limit�� �ʰ����� �ʴ� (0 ���� limit-dist[i+1] �̵� �Ÿ�) d[i][j]�� ���Ͽ�
//          d[i + 1][0] = min(d[i + 1][0], d[i][j] + cost[i + 1])    ; �湮�� ��Ȳ
//         	d[i + 1][j + dist[i + 1]] = d[i][j]     ; �湮���� ���� ��Ȳ
//  * d[i][j]�� ���Ͽ� �湮�� ��Ȳ, �湮���� ���� ��Ȳ�� ��� ����Ͽ����Ƿ� ���� �����̴�
//  * d[i][(limit - dist[i+1] +1) .. limit]�� �ҽǵ��� �ʴ°�? �̴� ��¥�� �߸��� ������ d���̴�
//  * �����÷ο�� ���Ͽ� d[i][j] == INT_MAX �� ��� continue�� ó���Ͽ���

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
// 1) �ٱ� ������ �ϳ��� �������� ������ �� 
//    ����, ���� �ܰ� ���� ��θ� ���� �湮�Ѵ�. (�ٱ� ���� ��𿡼� �����Ͽ��� ����)
// 2) ���ͽ�Ʈ�� �˰����� ���� �� dist[fr][fc]�� ��ȯ�Ѵ�.

#define _CRT_SECURE_NO_WARNINGS
#define SIZE 100
#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <utility>
#include <climits>

using namespace std;

int N, fr, fc;
int hi[SIZE][SIZE];

int r_dir[] = { -1, 0, 1, 0 };
int c_dir[] = { 0, 1, 0, -1 };

void __init__()
{
	cin >> N >> fr >> fc;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			scanf("%d", &hi[i][j]);
	}
}

int move(int here_hi, int next_hi)
{
	if (here_hi == next_hi)		return 0;

	else if (here_hi > next_hi)	return (here_hi - next_hi); // ������

	else  return ((next_hi - here_hi)*(next_hi - here_hi));	// ������
}

int dijkstra()
{
	priority_queue<pair<int, pair<int, int> > > pq;
	vector<vector<int> > dist(N + 1, vector<int>(N + 1, INT_MAX));
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i == 1 || i == N || j == 1 || j == N)
			{
				int next_cost = move(0, hi[i][j]);
				dist[i][j] = next_cost;
				pq.push(make_pair(-next_cost, make_pair(i, j)));
			}
		}
	}

	while (!pq.empty())
	{
		int cost = -pq.top().first;
		pair<int, int> here = pq.top().second;	pq.pop();
		
		if (dist[here.first][here.second] < cost) continue;	// �� ª�� �Ÿ��� �˸� �����Ѵ�
		for (int i = 0; i < 4; i++)
		{
			int rr = here.first + r_dir[i];	int cc = here.second + c_dir[i];
			if (rr < 1 || rr > N || cc < 1 || cc > N) continue;
			
			int next_cost = cost + move(hi[here.first][here.second], hi[rr][cc]);
			if (dist[rr][cc] > next_cost)
			{
				dist[rr][cc] = next_cost;
				pq.push(make_pair(-next_cost, make_pair(rr, cc)));
			}
		}
	}

	return dist[fr][fc];
}

int main(void)
{
	//freopen("input.txt", "r", stdin);
	__init__();
	cout << dijkstra();
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#define SIZE 55
#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int map[SIZE][SIZE];	// 1.1 부터 시작
bool visited[SIZE][SIZE];	// 1.1 부터 시작

int r_dir[] = { -1, 0, 1, 0 };
int c_dir[] = { 0, 1, 0, -1 };

void __init__()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%1d", &map[i][j]);
}

int bfs(int r, int c)
{
	queue<pair<int, int>> q;
	q.push(make_pair(r, c));
	visited[r][c] = true;
	pair<int, int> here;

	int ret = 1;
	while (!q.empty())
	{
		here = q.front();	q.pop();

		for (int i = 0; i < 4; i++)
		{
			pair<int, int> there;
			there.first = here.first + r_dir[i];	there.second = here.second + c_dir[i];
			if (there.first < 0 || there.first >= N || there.second < 0 || there.second >= N)
				continue;
			if (map[there.first][there.second] == 1 && !visited[there.first][there.second] )
			{
				visited[there.first][there.second] = true;
				q.push(make_pair(there.first, there.second));
				ret++;
			}
		}
	} // while
	return ret;
}

int main(void)
{
	//freopen("input.txt", "r", stdin);
	vector<int> sol;
	__init__();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 1 && !visited[i][j])
			{
				int temp = bfs(i, j);
				if (temp > 0)	sol.push_back(temp);
			}
		}
	}
	sort(sol.begin(), sol.end());
	int len = sol.size();
	printf("%d\n", len);
	for(int i = 0 ; i < len; i++)
		printf("%d\n", sol[i]);

	return 0;
}

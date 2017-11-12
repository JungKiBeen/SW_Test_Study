
// 1) sol�� �̸� ���� �� ��ġ���� ȿ���� �ش��Ͽ���. �� 10%�� ���� ���� ȿ���� ����
// 2) ������ &�� ����Ѵ��ϴ��� STL �����̳ʸ� �Ű������� ����ϴ� �� ��ü�� ū ���� ���ϰ� �ȴ�. 
//    ������ push_bakc, pop_back ����� �����ؾ� �Ѵ�.

// * path�� ���ͷ� �����Ͽ���.

#define _CRT_SECURE_NO_WARNINGS
#define SIZE 55

#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>

using namespace std;

int MAP[SIZE][SIZE];	// builiding, loc
bool visited[SIZE];
int N, sol; 
vector<int> sol_path;
vector<int> path;

void __init__()
{
	sol = INT_MAX;
	cin >> N;
	sol_path = vector<int>(N+1);
	path = vector<int>(N + 1);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			scanf("%d", &MAP[i][j]);
	}
}

void dfs(int building, int pay)
{
	if (pay > sol) return;
	if (building > N)
	{
		if (pay < sol)
		{
			sol = pay;
			sol_path = path;
		}
		return;
	}

	for (int loc = 1; loc <= N; loc++)
	{
		if (!visited[loc])
		{
			visited[loc] = true;
			path[building] = loc;
			dfs(building + 1, pay + MAP[building][loc]);
			visited[loc] = false;
		}
	}
}

int pre_setting()
{
	int ret = 0;
	vector<bool> local_visited(N+1, false);

	for (int builindg = 1; builindg <= N; builindg++)
	{
		int min_loc = -1;
		int min_cost = INT_MAX;

		for (int loc = 1; loc <= N; loc++)
		{
			if (!local_visited[loc] && min_cost > MAP[builindg][loc])
			{
				min_loc = loc;
				min_cost = MAP[builindg][loc];
			}
		}
		local_visited[min_loc] = true;
		ret += min_cost;
	}
	return ret;
}

int main(void)
{
	//freopen("input.txt", "r", stdin);
	__init__();
	sol = pre_setting();
	dfs(1, 0);
	cout << sol <<"\n" ;

	for (int i = 1; i <= N; i++)
		printf("%d ", sol_path[i]);

	return 0;
}
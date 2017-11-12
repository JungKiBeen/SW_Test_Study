// 1) �ݵ�� ������ ������ Optimal solution�� ��, ���� ��迡 ��ġ�� �ִ�. 
//    ���� ������� row, col�� ������ ���� ��ġ�� �����ص� �ȴ�.
// 2) ����ġ�� : l*l �׹� �� ������ ����Ⱑ MAX���� ������ ȣ������ �ʴ´�.
// 3)1*1 ������ N�� ���� ������ �ȴ�. ������, �̸� ����� �ʿ�� ����. ��¥�� �� Ȥ�� �������� ��ĭ �̵��Ͽ� ġ�� �ȴٰ� �����ϸ� �Ǳ⿡


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <queue>
#include <set>
#include <algorithm>
#include <vector>
#include <utility>
#include <climits>

using namespace std;

int N, l, M;
vector<pair<int, int> > mulgo;
set<int> rclust, cclust;

// ù���� �湮 ����, n�� n��° �湮


void __init__()
{
	cin >> N >> l >> M;

	for (int i = 1; i <= M; i++)
	{
		int r, c;
		scanf("%d %d", &r, &c);
		rclust.insert(r); cclust.insert(c);
		mulgo.push_back(make_pair(r, c));
	}
}

int mulgo_count(int r, int c, int garo, int sero)
{
	int ret = 0;
	for (int i = 0; i < M; i++)
	{
		int mr = mulgo[i].first;	int mc = mulgo[i].second;
		if (mr >= r && mr <= r + garo && mc >= c && mc <= c + sero)
			ret++;
	}

	return ret;
}

int solve(int r, int c)
{
	int local_max = -1;
	for (int garo = 1; garo < l; garo++)
	{
		for (int sero = 1; sero < l; sero++)
		{
			if (garo * 2 + sero * 2 == l)
			{
				local_max = max(local_max, mulgo_count(r, c, garo, sero));
			}
		}
	}
	return local_max;
}

int main(void)
{
	int MAX = -1;
	//freopen("input.txt", "r", stdin);
	__init__();

	set<int> ::iterator row, col;

	for (row = rclust.begin(); row != rclust.end(); ++row)
	{
		for (col = cclust.begin(); col != cclust.end(); ++col)
			if (mulgo_count(*row, *col, l, l) > MAX)
				MAX = max(solve(*row, *col), MAX);
	}
	cout << MAX;
	return 0;
}

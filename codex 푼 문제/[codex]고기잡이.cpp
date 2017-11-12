// 1) 반드시 임의의 물고기는 Optimal solution의 위, 왼쪽 경계에 위치해 있다. 
//    따라서 물고기의 row, col의 조합을 배의 위치로 한정해도 된다.
// 2) 가지치기 : l*l 그물 내 잡히는 물고기가 MAX보다 작으면 호출하지 않는다.
// 3)1*1 영역만 N을 넘지 않으면 된다. 하지만, 이를 고려할 필요는 없다. 어짜피 위 혹은 왼쪽으로 한칸 이동하여 치면 된다고 가정하면 되기에


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

// 첫번재 방문 부터, n은 n번째 방문


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

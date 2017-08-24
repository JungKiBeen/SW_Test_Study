#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include<string>
#include<list>
#include<queue>
#include<vector>
#include<stack>
#include<map>

#include<cmath>
#include<cctype>
#include <ctime>
#include <cstdlib>
#include<cstring>
#include<climits>
#include<cassert>
using namespace std;

typedef vector<int> table;


int sgn(int x)
{
	if (!x) return 0;

	else return x > 0 ? 1 : -1;
}

int incr(int x)
{
	return x > 0 ? x + 1 : x - 1;
}

int get_idx(int x, int dir)
{
	switch (dir)
	{
	case 0:
		if (x % 3 == 0) return -1;
		return x - 1;
	case 1:
		if (x < 3) return -1;
		return x - 3;
	case 2:
		if (x % 3 == 2) return -1;
		return x + 1;
	case 3:
		if (x > 5) return -1;
		return x + 3;
	}
}

// 양방향 bfs 구현
map<table, int> m;
int bfs(table start, table dest)
{
	// 예외처리
	if (start == dest) return 0;

	queue<table> q;
	q.push(start);
	q.push(dest);
	m[start] = 1;
	m[dest] = -1;

	while (!q.empty())
	{
		table here = q.front();  	q.pop();
		int cost = m[here];

		table::iterator it = find(here.begin(), here.end(), 0);
		assert(it != here.end());
		int x = it - here.begin();

		for (int i = 0; i < 4; i++)
		{
			int y = get_idx(x, i);
			if (y == -1) continue;
			swap(here[x], here[y]);

			if (m.count(here) == 0)
			{
				m[here] = incr(cost);
				q.push(here);
			}
			else if (sgn(cost) != sgn(m[here]))
				return abs(cost) + abs(m[here]) - 1;
			
			swap(here[x], here[y]);
		}
	}
	return -1;
}


int main(void)
{
	freopen("input.txt", "r", stdin);
	std::ios_base::sync_with_stdio(false);
	
	table dest(9);
	table start(9);

	int num = 1;
	for (int i = 0; i < 9; i++)
	{
		cin >> start[i];
		dest[i] = num++;
	}
	dest[8] = 0;

	cout << bfs(start, dest);
	return 0;
}




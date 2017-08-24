#include<iostream>
#include<cstdio>
#include <algorithm>
#include<queue>
#include<cstring>
#include <string>
using namespace std;

int a, b;		char dr[] = { 'D', 'S','L','R' };
bool visit[10001];	int from[10001];	char how[10001];

void BFS()
{
	queue<int> q;

	q.push(a);	visit[a] = true;

	while (!q.empty())
	{
		int x, xx;
		x = q.front();	q.pop();
		if (x == b)	break;

		for (int i = 0; i < 4; i++)
		{
			switch (dr[i])
			{
			case 'D':
				xx = (2 * x) % 10000;
				break;
			case 'S':
				xx = x - 1;
				if (x == 0) xx = 9999;
				break;
			case 'L':
				xx = (x % 1000) * 10 + x / 1000;
				break;
			case 'R':
				xx = x / 10 + (x % 10) * 1000;
				break;
			}

			if (visit[xx] == false)
			{
				q.push(xx);	
				visit[xx] = true;	from[xx] = x;	how[xx] = dr[i];
			}
		}
	}
}

int main()
{
	freopen("a.txt","r", stdin);
	int t;
	cin >> t;

	while (t--)
	{
		memset(visit, false, sizeof(visit));
		memset(from, 0, sizeof(from));
		memset(how, 0, sizeof(how));
		scanf("%d %d", &a, &b);
		BFS();

		string sol = "";
		while (b != a)
		{
			sol += how[b];
			b = from[b];
		}
		reverse(sol.begin(), sol.end());
		cout << sol << '\n';
	}
	return 0;
}
/*
1. 큐와 상태를 vector로 나타내었다.
2. sol은 set으로 구현해도 좋고, bool 배열로 구현하여도 좋다.
*/


#include<iostream>
#include<cstdio>

#include<algorithm>
#include<map>
#include<queue>
#include<vector>
using namespace std;

bool sol[201];


void BFS(vector<int> &full)
{
	map<vector<int>, bool> visit;
	queue<vector<int>> q;

	vector<int> init(3);	init[0] = 0; init[1] = 0; init[2] = full[2];

	visit[init] = true;
	q.push(init);


	while (!q.empty())
	{
		vector<int> now = q.front();
		q.pop();

		if (now[0] == 0)
		{
			sol[now[2]] = true;
		}
		for (int sen = 2; sen >= 0; sen--)
		{
			if (now[sen] == 0)	continue;
			vector<int> next;
			next.insert(next.begin(), now.begin(), now.end());

			for (int j = 1; j <= 2; j++)
			{
				int rec = (sen + j) % 3;
				int yang = min(next[sen], full[rec] - next[rec]);
				next[sen] -= yang;
				next[rec] += yang;

				if (visit[next] == 0)
				{
					visit[next] = true;
					q.push(next);
				}
			}
		}
	}

}

int main()
{
	vector<int> full(3);

	for (int i = 0; i < 3; i++)
	{
		cin >> full[i];
	}
	BFS(full);

	for (int i = 0; i <= 200; i++)
	{
		if (sol[i])	printf("%d ", i);
	}

	return 0;
}
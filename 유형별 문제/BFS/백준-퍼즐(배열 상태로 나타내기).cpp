1. DFS는 적합하지 못하다.종결조건을 명시하기 어렵다.

2. 그래프의 상태는 2차원 배열이 된다.queue에 넣는 부하를 줄이기 위해 2차원 배열을 정수로 파싱하여 상태를 나타낸다. (핵심)

3. 상태의 수는 순열이 되어 9!이 된다.

4. visit 테이블을 map으로 구현한다.

5. 스왑하는 과정은 상태(정수)를 스트링으로 변환하여 구현한다

#include<iostream>
#include<cstdio>
#include<string>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;

int dr[] = { -1, 0, 1, 0 };	int dc[] = { 0, 1, 0, -1 };

int BFS(int &start)
{
	map<int, int> cost;
	queue<int> q;
	
	cost[start] = 0;

	q.push(start);

	while (!q.empty())
	{
		int now_num = q.front();
		q.pop();

		if (now_num == 123456789)	break;

		string now = to_string(now_num);
		int zero = now.find('9');
		
		int x = zero / 3;
		int y = zero % 3;

		for (int i = 0; i < 4; i++)
		{
			int xx = x + dr[i];	int yy = y + dc[i];

			if (xx < 0 || xx > 2 || yy < 0 || yy > 2)	continue;

			string next = now;
			
			swap(next[zero], next[xx * 3 + yy]);
			int next_num = stoi(next);

			if (cost.count(next_num) == 0)
			{
				cost[next_num] = cost[now_num] + 1;
				q.push(next_num);
			}
		}
	}

	if (cost.count(123456789) == 0)
		return -1;

	else 
		return cost[123456789];
}

int main()
{
	//freopen("a.txt", "r", stdin);

	int start = 0;
	for (int i = 0; i < 9 ; i++)
	{
		int temp;
		scanf("%d", &temp);
		if (temp == 0)	temp = 9;
		
		start = start * 10 + temp;
	}
	
	int sol = BFS(start);
	cout << sol;

	return 0;
}
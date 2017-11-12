1. DFS�� �������� ���ϴ�.���������� ����ϱ� ��ƴ�.

2. �׷����� ���´� 2���� �迭�� �ȴ�.queue�� �ִ� ���ϸ� ���̱� ���� 2���� �迭�� ������ �Ľ��Ͽ� ���¸� ��Ÿ����. (�ٽ�)

3. ������ ���� ������ �Ǿ� 9!�� �ȴ�.

4. visit ���̺��� map���� �����Ѵ�.

5. �����ϴ� ������ ����(����)�� ��Ʈ������ ��ȯ�Ͽ� �����Ѵ�

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
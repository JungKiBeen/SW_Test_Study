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

using namespace std;

map<vector<int>, int> m; // distance ���̺�

void bfs(int n)
{
	vector<int> sorted;
	for (int i = 1; i <= n; ++i)
		sorted.push_back(i);
	queue<vector<int>> q;
	q.push(sorted);
	m[sorted] = 0;
	while (!q.empty())
	{
		vector<int> here = q.front(); q.pop();
		int dist = m[here];
		// ���������� ������ �ʿ� ����. sorted ���� ��� �迭 ���¸� Ž���ؾ� �Ѵ�.
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				reverse(here.begin() + i, here.begin() + j + 1);
				if (m.count(here) == 0)	// �湮���� �ʾ�����
				{
					m[here] = dist + 1;
					q.push(here);
				}
				reverse(here.begin() + i, here.begin() + j + 1);
			}
		}
	}
}

int main(void)
{
	freopen("input.txt", "r", stdin);
	std::ios_base::sync_with_stdio(false);
	int c;
	cin >> c;

	for (int i = 1; i <= 8; ++i)
		bfs(i);

	while (c--)
	{
		vector<int> temp;
		vector<int> general;
		general.clear();
		temp.clear();
		int n;
		cin >> n;
		
		for (int i = 0; i < n; i++)
			cin >> temp[i];

		for (int i = 0; i < n; ++i)
		{
			int cnt = 0;
			for (int j = 0; j < n; ++j)
			{
				if (temp[j] <= temp[i])
					cnt++;
			}
			general.push_back(cnt);
		}
		cout << m[general] << "\n";
	}

	return 0;
}


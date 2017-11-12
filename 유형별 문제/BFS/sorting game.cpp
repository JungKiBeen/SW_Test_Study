
// * 맵 검사하는 코드는 if (!distance[there])보다 if(distance.count(there) == 0) 이 더 낫다
// * 매번 벡터를 생성하는 것 보다, 다시 reverse하는 것이 효율적이다.
// * check_arranged 함수 구현도 좋다. 하지만 vector에 이미 정의 되어있는 비교 연산자를 사용하자

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

vector<int> reverse_subarr(vector<int> v, int start, int end)
{
	reverse(v.begin() + start, v.begin() + end+1);

	return v;
}

bool check_arranged(vector<int> &v)
{
	for (int j = 1; j < (int)v.size(); ++j)
	{
		int i = j - 1;

		if (v[i] > v[j]) return false;
	}

	return true;
}

int bfs(vector<int> v)
{
	map<vector<int>, int> distance;
	queue<vector<int>> q;

	distance[v] = 1;
	q.push(v);

	while (!q.empty())
	{
		vector<int> here = q.front();	q.pop();
		if (check_arranged(here))
			return distance[here] - 1;
		
		for (int end = 1; end < (int)here.size(); end++)
		{
			int start = 0;
			int temp = end;

			while (temp < (int)here.size())
			{
				vector<int> there = reverse_subarr(here, start, temp);
				if (!distance[there])
				{
					distance[there] = distance[here] + 1;
					q.push(there);
				}

				++start; ++temp;
			}
		}
	}

	return -1;
}

int main(void)
{
	freopen("input.txt", "r", stdin);
	std::ios_base::sync_with_stdio(false);
	int c;
	cin >> c;

	while (c--)
	{
		int n;
		cin >> n;
		vector<int> v;

		for (int i = 0; i < n; ++i)
		{
			int temp;
			cin >> temp;
			v.push_back(temp);
		}
		
		cout << bfs(v) << "\n";
	}
	return 0;
}


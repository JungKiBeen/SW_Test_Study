#include <iostream>
#include <cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int a[40];

int main()
{
	//freopen("a.txt", "r", stdin);
	int n, s;
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	int m1 = n / 2;	//up 의 길이
	int m2 = n - m1;

	vector<int> up;
	vector<int> down;

	for (int i = 0; i < (1 << m1); i++)
	{
		int sum = 0;
		for (int k = 0; k < m1; k++)
		{
			if (i & (1 << k))
			{
				sum += a[k];
			}
		}

		up.push_back(sum);
	}

	for (int i = 0; i < (1 << m2); i++)
	{
		int sum = 0;
		for (int k = 0; k < m2; k++)
		{
			if (i & (1 << k))
			{
				sum += a[k + m1];
			}
		}

		down.push_back(sum);
	}

	sort(up.begin(), up.end());
	sort(down.begin(), down.end());
	reverse(down.begin(), down.end());

	long long sol = 0;
	int i, j;
	i = j = 0;
	while (i < up.size() && j < down.size())
	{
		long long sum = up[i] + down[j];

		if (sum == s)
		{
			long long c1 = 1;
			long long c2 = 1;

			i++; j++;

			while (i < up.size() && up[i - 1] == up[i])
			{
				c1++;
				i++;
			}

			while (j < down.size() && down[j - 1] == down[j])		// 항상 유효 검사하자!
			{
				c2++;
				j++;
			}

			sol += c1* c2;
		}

		else if (sum < s)
		{
			i++;
		}

		else
		{
			j++;
		}
	}

	if (s == 0) sol--;	// s 가 0일때, 공집합의 경우도 포함된다.

	cout << sol;

	return 0;
}
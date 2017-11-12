
#include<iostream>
#include<cstdio>
#include<limits>
#include<vector>
#include<algorithm>
using namespace std;

bool temp[4000000];
int prime[4000000];

int main()
{
	int n;
	cin >> n;
	if (n == 1)
	{
		cout << 0;
		return 0;
	}

	temp[0] = true;	 temp[1] = true;
	for (int i = 2; i <= n; i++)
	{
		if (temp[i] == true)	continue;
		for (int j = i * 2; j <= n; j += i)
		{
			temp[j] = true;
		}
	}

	for (int i = 0; i <= n; i++)
	{
		temp[i] = !temp[i];
	}

	vector<int> prime;

	for (int i = 2; i <= n; i++)
	{
		if (temp[i])	prime.push_back(i);
	}

	int left, right, sol =0;
	left = right = 0;

	long long sum = prime[0];
	int len = prime.size();

	while(left <= right && right < len)
	{
		if (sum < n)
		{
			right++;
			if (right == len)	break;
			sum += prime[right];
		}

		else if (sum > n)
		{
			sum -= prime[left];
			left++;
		}

		else if (sum == n)
		{
			sol++;

			right++;
			if (right == len)	break;
			sum += prime[right];
		}
	} 

	cout << sol;
	return 0;
}
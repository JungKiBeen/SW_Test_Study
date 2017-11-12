#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<cstdio>
#include<cstdlib>
#include <assert.h>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, c, b1r, b2l;
vector<int> map, bucket1, bucket2;

//true : sum <= c
bool check_buceket(int left, int right)
{
	int sum = 0;
	for (int i = left; i <= right; i++)
	{
		sum += map[i];
	}

	return sum <= c;
}

int sumation_bucket(int left, int right)
{
	int sum = 0;
	for (int i = left; i <= right; i++)
	{
		sum += (map[i] * map[i]);
	}

	return sum;
}

// 제곱의 합이 최대가 되도록 선택
int BUCKET_MAX;
void dfs(vector<int> &v, int n, int sum, int profit)
{
	if (sum > c) return;
	if (n == (int)v.size())
	{
		BUCKET_MAX = max(profit, BUCKET_MAX);
		return;
	}

	dfs(v, n + 1, sum + v[n], profit + (v[n]*v[n]));
	dfs(v, n + 1, sum, profit);
}


int get_profit()
{
	int ret;
	if (check_buceket(b1r - (m-1), b1r))
		ret = sumation_bucket(b1r - (m - 1), b1r);

	else
	{	
		BUCKET_MAX = 0;
		int k = 0;
		for (int i = (b1r - (m - 1)); i <= b1r; i++, k++)
			bucket1[k] = map[i];

		dfs(bucket1, 0, 0, 0);
		ret = BUCKET_MAX;
	}

	if (check_buceket(b2l, b2l + (m-1)))
		ret += sumation_bucket(b2l, b2l + (m - 1));

	else
	{
		BUCKET_MAX = 0;
		int k = 0;
		for (int i = b2l; i <= b2l + (m - 1); i++, k++)
			bucket2[k] = map[i];

		dfs(bucket2, 0, 0, 0);
		ret += BUCKET_MAX;
	}

	return ret;
}

///////////////////////

void move(int x)
{
	if (x == 1)
		b1r += (b1r % n == n-1) ? m : 1;

	else if(x == 2)
		b2l -= (b2l % n == 0) ? m : 1;
}


int sol()
{
	int MAX = -1;

	while (b1r < b2l)
	{
		while (b1r < b2l)
		{
			int temp = get_profit();
			MAX = max(MAX, temp);
			move(2);
		}

		b2l = n*n - m;
		move(1);
	}

	return MAX;
}


void __init__()
{
	cin >> n >> m >> c;
	map = vector<int>(n*n);
	for (int i = 0; i < n*n; i++)
		cin >> map[i];

	bucket1 = vector<int>(m);
	bucket2 = vector<int>(m);
	b1r = m - 1; b2l = n*n - m;
}


int main(void)
{
	std::ios_base::sync_with_stdio(false);
	freopen("sample_input.txt", "r", stdin);

	int T; cin >> T;

	for (int i = 1; i <= T; i++)
	{
		__init__();
		cout << "#" << i << " " << sol() << "\n";
	}

	return 0;
}
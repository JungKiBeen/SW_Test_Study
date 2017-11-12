#define _CRT_SECURE_NO_WARNINGS
#define SIZE 111
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int droot(int root);

int n;


int main(void)
{
	priority_queue<pair<int, int>> pq;
	scanf("%d", &n);

	while (n--)
	{
		int m;
		scanf("%d", &m);
		pq.push(make_pair(droot(m), -m));
	}

	printf("%d", -pq.top().second);

	return 0;
}


int droot(int root)
{
	while (root > 9)
	{
		int temp = 0;
		while (root > 0)
		{
			temp += root % 10;
			root /= 10;
		}
		root = temp;
	}
	return root;
}
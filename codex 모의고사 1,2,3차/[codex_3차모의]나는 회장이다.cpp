#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstdio>
#include<climits>
#include<cstring>
using namespace std;

int total[4], cnt[4][4];
bool P[4]; int pn;
int N;


inline void print_sol()
{
	int pres;
	for (int i = 1; i <= 3; i++)
		if (P[i]) pres = i;
	printf("%d %d", pres, total[pres]); // �ĺ� ��ȣ�� �� �ĺ��� ������ ���
}

bool func(int x)
{
	int MAX;
	memset(P, false, sizeof(P)), pn = 0;

	MAX = (cnt[1][x] > cnt[2][x]) ? cnt[1][x] : cnt[2][x];
	MAX = (MAX > cnt[3][x]) ? MAX : cnt[3][x];

	for (int i = 1; i <= 3; i++)
	{
		if (MAX == cnt[i][x])
		{
			++pn, P[i] = true;
		}
	}
	
	if (pn == 1)
	{
		print_sol();
		return true;
	}
	
	else return false;
}

void solve()
{
	int MAX;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		int s1, s2, s3;
		scanf("%d %d %d", &s1, &s2, &s3);
		total[1] += s1, total[2] += s2, total[3] += s3;
		cnt[1][s1]++, cnt[2][s2]++, cnt[3][s3]++;
	}

	MAX = (total[1] > total[2]) ? total[1] : total[2]; // ���� �ְ� ���� ���Ѵ�
	MAX = (MAX > total[3]) ? MAX : total[3];
	
	// MAX�� ���� ���� ������ �ĺ��� üũ�Ѵ�
	for (int i = 1; i <= 3; i++)
	{
		if (MAX == total[i])
		{
			++pn, P[i] = true;
		}
	}

	if (pn == 1)
	{
		print_sol();
	}

	else if (pn > 1)
	{
		if (!func(3) && !func(2))
		{
			printf("%d %d", 0, total[1]); // �ĺ��� �����ϰ� ������ �� ���� ���

		}
	}
}

int main(void)
{
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
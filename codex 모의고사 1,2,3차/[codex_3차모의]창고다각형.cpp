// slist[] : ���õ� ����� �ε���. ������ �����ϰ� �ϴϱ� �򰥸���;

#define _CRT_SECURE_NO_WARNINGS
#define NSIZE 1111
#include <iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int N, H, SOL;
int cl[NSIZE], ch[NSIZE], sl[NSIZE], sh[NSIZE]; int sn;

void __init__()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d %d", &cl[i], &ch[i]);
	// L ���� �������� ����. ������ ����� �������� ����, ������ �ִ��� �˱� ���� �ϱ� ����
	for (int i = 1; i < N; i++)
	{
		int MIN = i;
		for (int j = i + 1; j <= N; j++)
		{
			if (cl[j] < cl[MIN])
				MIN = j;
		}
		swap(cl[i], cl[MIN]);
		swap(ch[i], ch[MIN]);
	}

	H = 1;
	for (int i = 2; i <= N; i++)
	{
		if (ch[i] > ch[H])
			H = i;
	}
}

void ldvq(int hst)
{
	if (hst == 1) // ���� ����
		return;

	int lh = 1;
	for (int i = 2; i < hst; i++)
	{
		if (ch[i] > ch[lh])
			lh = i;
	}
	++sn; sl[sn] = cl[lh]; sh[sn] = ch[lh];
	ldvq(lh);
}

void rdvq(int hst)
{
	if (hst == N) // ���� ������
		return;

	int lh = hst+1;
	for (int i = hst+2; i <= N; i++)
	{
		if (ch[i] > ch[lh])
			lh = i;
	}
	++sn; sl[sn] = cl[lh]; sh[sn] = ch[lh];
	rdvq(lh);
}


int main(void)
{
//	freopen("input.txt", "r", stdin);
	__init__();
	++sn; sl[sn] = cl[H]; sh[sn] = ch[H];
	ldvq(H);
	rdvq(H);
	
	// sl�� �������� ����
	for (int i = 1; i < sn; i++)
	{
		int MIN = i;
		for (int j = i + 1; j <= sn; j++)
		{
			if (sl[j] < sl[MIN])
				MIN = j;
		}
		swap(sl[i], sl[MIN]);
		swap(sh[i], sh[MIN]);

	}

	for (int i = 1; i < sn; i++)
	{
		SOL += sh[i];
		int lower = (sh[i] < sh[i+1]) ? sh[i] :sh[i+1];
		SOL += (sl[i+1] - sl[i] - 1) * lower;
	}
	SOL += sh[sn];
	printf("%d", SOL);
	return 0;
}
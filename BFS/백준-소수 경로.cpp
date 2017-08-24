/*
<������� ��>
1. �Ҽ� ����Ʈ�� ���� �� �˰� ���Ͼ� Ž���� �Ϸ� �ߴ�. 
�Ź� deque�� �� ���� 1000�� ����Ʈ�� ���Ͼ� Ž���߾�� ����.

-> �� ����� ���� ���� v ���� �� �ڸ��� �ٲ㰡�鼭 �Ҽ��� üũ�ϴ� ������� �ٲ�
   �� ��� 40���� Ž���� �ϸ� ��.

2. ���� üũ�� ����� �̷������ �ʾ���.
-> �� �κп��� ����� ���鼭 ����� �߾�� ����. ������� �������� �ع�����.
-> ó�� t�� i�ڸ����� 0���� ����� �κп��� ���ڿ� ��ȯ ����� �� ������ �ʾ��� ��

3. ���� �׽�Ʈ ���̽� ��쿡�� visit�� ����� �ʱ�ȭ ���� �ʾ���.
-> ���� �׽�Ʈ ���̽��� ���, �������� ���̴� ������������ �� üũ�������.
   
   int change(int num, int index, int digit) {
   if (index == 0 && digit == 0) return -1;
   string s = to_string(num);
   s[index] = digit+'0';
   return stoi(s);
   }

   �̷������� �ڸ� ���� �ٲٴ� �ڵ带 ����ϴ°� �� ������ �� ����. 
   to_srting, stoi ������ �ð����⵵�� affordable �� �����̴�.

4. ������׽� ü�� �̿��Ͽ� �Ҽ��� �����Ѵ�.


<���Ҵ� ��>
1. ���� v���� ���ڸ� ���̳��� ��� �Ҽ����� queue �ִ� ����� �¾���

2. �ڸ��� ���� dr[] ���̺��� ���� �ڵ� ������ ���� ���� �� �־���

3. prime[] ���̺��� ���� �ð����⵵�� ���� ���� �� �־���




�Ҽ������� Ȯ���ϴ� �ڵ�� �� § �� ����!

*/


#include <iostream>
#include<stdio.h>

#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

int A, B; bool succes;
bool prime[9999 + 1];
int dr[] = {1, 10, 100, 1000};

bool calc(const int &num)
{
	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)	return false;
	}

	return true;
}


int BFS()
{
	succes = false;
	queue<int> q;

	vector<int> visit(9999 + 1);

	fill(visit.begin(), visit.end(), 0);

	q.push(A);
	visit[A] = 1;

	int v;
	while(!q.empty())
	{
		v = q.front();
		q.pop();

		if (v == B)
		{
			succes = true;
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int t, t2;
			t= t2 = v;

			for (int j = 0; j < i; j++)	t2 /= 10;

			t -= (t2 % 10) *dr[i];
			for (int j = 0; j <= 9; j++, t+= dr[i])
			{
				if (t < 1000) continue;

				if ((visit[t] == 0) && prime[t])
				{
					visit[t] = visit[v] + 1;
					q.push(t);
				}

			}
		}
	}

	return visit[v] - 1;
}

int main()
{
	freopen("a.txt", "r", stdin);
	int T;
	cin >> T;


	for (int i = 2 ;i <= 9999; i++)
	{
		prime[i] = true;
	}


	// 2�� ������ ��� 2�� ����� üũ�Ѵ�.
	//	3�� ������ ��� 3�� ����� üũ�Ѵ�.
	//	4�� �Ʊ� üũ�������Ƿ� �Ҽ� �ƴ�.(�߿�)
	//	5�� ������ ��� 5�� ����� üũ�Ѵ�.
	//	...
	// true�� �Ҽ�

	for (int i = 2 ; i<= 9999; i++)
	{
		if (prime[i] == false)	continue;

		for (int j = 2 * i; j <= 9999; j += i)
		{
			prime[j] = false;
		}
	}

	for (int i = 0; i < T; i++)
	{
		scanf("%d %d", &A, &B);
		int sol = BFS();
		if(succes)	printf("%d\n", sol);
		else printf("Impossible\n");
	}
	return 0;
}
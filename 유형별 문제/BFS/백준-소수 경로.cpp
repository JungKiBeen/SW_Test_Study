/*
<어려웠던 점>
1. 소수 리스트가 적을 줄 알고 리니어 탐색을 하려 했다. 
매번 deque할 때 마다 1000개 리스트를 리니어 탐색했어야 했음.

-> 이 방법을 현재 숫자 v 에서 한 자리씩 바꿔가면서 소수를 체크하는 방식으로 바꿈
   이 경우 40번의 탐색만 하면 됨.

2. 범위 체크가 제대로 이루어지지 않았음.
-> 이 부분에서 제대로 쓰면서 계산을 했어야 했음. 디버깅을 여러차례 해버렸음.
-> 처음 t의 i자리수를 0으로 만드는 부분에서 문자열 변환 기법을 썼어도 나쁘지 않았을 듯

3. 여러 테스트 케이스 경우에서 visit을 제대로 초기화 하지 않았음.
-> 여러 테스트 케이스인 경우, 공용으로 쓰이는 전역변수들을 꼭 체크해줘야함.
   
   int change(int num, int index, int digit) {
   if (index == 0 && digit == 0) return -1;
   string s = to_string(num);
   s[index] = digit+'0';
   return stoi(s);
   }

   이런식으로 자리 수를 바꾸는 코드를 사용하는게 더 나았을 것 같다. 
   to_srting, stoi 정도는 시간복잡도가 affordable 한 정도이다.

4. 에라토네스 체를 이용하여 소수를 구현한다.


<좋았던 점>
1. 현재 v에서 한자리 차이나는 모든 소수들을 queue 넣는 방식은 맞았음

2. 자리수 별로 dr[] 테이블을 만들어서 코드 라인을 많이 줄일 수 있었음

3. prime[] 테이블을 만들어서 시간복잡도를 많이 줄일 수 있엇음




소수인지를 확인하는 코드는 잘 짠 것 같다!

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


	// 2를 제외한 모든 2의 배수를 체크한다.
	//	3을 제외한 모든 3의 배수를 체크한다.
	//	4는 아까 체크당했으므로 소수 아님.(중요)
	//	5를 제외한 모든 5의 배수를 체크한다.
	//	...
	// true가 소수

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
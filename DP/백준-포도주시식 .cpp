/*
	#어려웠던 점
	
	1. d[n][j] 는  n개의 포도잔으로 마실수 있는 가장 많은 양
	2. d[1][2] 초기값 설정해서, 2잔 마시는 경우는 없다. 그렇다고 0을 저장해서는 안된다. 한잔 마셨다고 저장하는 것이 더 자연스럽다.
	3. d[i][0]은 이번잔을 마시지 않는 경우이다. 그래서, 나는 이전 경우중 최대가 d[i-1][2]라 생각하고 d[i-1][2]를 저장했다. 이것은 틀린 가정이다. 
	심지어 d[i-1][0]이 최대가 될 수도 있다. max를 이용하여 구현해 줘야 한다. 
*/

#include<iostream>
#include<algorithm>
#include<stdio.h>

using namespace std;

int a[10000 + 1];
long long d[10000 + 1][3];


int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}

	d[1][0] = 0;
	d[1][1] = a[1];
	d[1][2] = a[1];

	for (int i = 2; i <= n; i++)
	{
		d[i][0] = max(d[i-1][0], max(d[i-1][1], d[i-1][2]));
		d[i][1] = d[i - 1][0] + a[i];
		d[i][2] = d[i - 1][1] + a[i];
	}
	
	cout << max(max(d[n][0], d[n][1]), d[n][2]) << '\n';

	return 0;
}
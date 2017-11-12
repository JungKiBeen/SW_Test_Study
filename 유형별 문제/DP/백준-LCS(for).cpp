/*
-���� : d[1..m][1..n]���� d[i][j]�� s1�� �ε��� i-1�� s2�� �ε��� j-1������ LCS�� ����	// -1 ������ ���� d�迭�� ��ĭ �̷�

- ������ :
d[m][n] �� ������.
*/


#include<iostream>
#include<cstdio>
#include<cstring>

#include<string>
#include<algorithm>
using namespace std;

string s1, s2;	// s1[0..m-1], s2[0..n-1]
int m, n;
int d[1000 + 1][1000 + 1];		// �ִ� 1000�̴�.

int main()
{
	//freopen("a.txt", "r", stdin);
	cin >> s1 >> s2;
	m = s1.size();
	n = s2.size();

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{

			if (s1[i-1] == s2[j-1])
			{
				d[i][j] = d[i - 1][j - 1] + 1;
			}

			else
			{
				d[i][j] = max(d[i][j - 1], d[i - 1][j]);
			}
		}
	}
	cout << d[m][n];
	return 0;
}
/*
	-정의 : d[0..m-1][0..n-1]에서 d[i][j]는 s1의 인덱스 i와 s2의 인덱스 j에서으 LCS의 길이
	-재귀식 : 
	
	if(s1[i] == s2[j]) d[i][j] = 1 + d[i-1][j-1]	
	// 서로 문자열에 맵핑 되지 않는 새로운 두 알파벳이 나올 때, LCS의 길이를 1증가 시켜야 한다. 이를 보장하기 위해 d[i-1][j-1]에 1을 증가시킴
		s1 :AA  s2: AAA 일때 (1,2) = 2이어야 함.		
		그런데, (1,1) =2, (0,2) = 1 이 되기 때문에, (1,2) = 3이 되버림

	
	else
	{	
		d[i][j] = max(memo(i-1, j), memo(i, j-1));
	}

	- 예외사항 : 
	// s1:B s2:AAA 에서 d[0,3]은 d[0,2]로 갱신되야 한다. [-1,3]은 범위를 벗어나므로.. 이 경우 0을 예외로 반환하도록 한다
	// s1 : A S2:AAA 에서 d[0,3]은 1로 갱신되야 한다. 이 경우 [-1,3]은 범위를나므로 0을 예외로 반환하도록 한다.

	- 최종답 :
	d[m-1][n-1] 에 존재함.
*/


#include<iostream>
#include<cstdio>
#include<cstring>

#include<string>
#include<algorithm>
using namespace std;

string s1, s2;	// s1[0..m-1], s2[0..n-1]
int m, n;
int d[1000+10][1000+10];		// 최대 1000이다.

int memo(int i, int j)
{
	/*
	if (i == 0 || j == 0)
	{
		return (s1[i] == s2[j]);		// 1. s1:B s2:AAA 에서 d[0,3]은 d[0,2]로 갱신되야 한다. [-1,3]은 범위를 벗어나므로.. 이 경우 0을 예외로 반환하도록 한다 
										// 2. s1 : A S2:AAA 에서 d[0,3]은 1로 갱신되야 한다. 이 경우 [-1,3]은 범위를나므로 0을 예외로 반환하도록 한다.
	}
	*/
	
	if (i == -1 || j == -1)
	{
		return 0;
	}
	

	else
	{
		if (d[i][j] != -1)
		{
			return d[i][j];
		}

		/*
		if (s1[i] == s2[j])
		{
			d[i][j] = max(memo(i - 1, j), memo(i, j - 1)) + 1;		// s1 :AA  s2: AAA 일때 (1,2) = 2이어야 함.
																	// 그런데, (1,1) =2, (0,2) = 1 이 되기 때문에, (1,2) = 3이 되버림
		}
		*/
		
		if (s1[i] == s2[j])
		{
			d[i][j] = memo(i-1,j-1) + 1;	// 서로 문자열에 맵핑 되지 않는 s1[i], s2[i]가 나올 때 LCS의 길이를 1증가 시켜야 한다.
											// 즉, s[i], s[j]가 나오기전 문자열 상태의 LCS의 길이와 1합해야함.
		}
		

		else
		{
			d[i][j] = max(memo(i-1, j), memo(i, j-1));
		}

		return d[i][j];
	}
}

int main()
{
	//freopen("a.txt", "r", stdin);
	cin >> s1 >> s2;
	memset(d, -1, sizeof(d));
	m = s1.size();
	n = s2.size();

	cout << memo(m-1,n-1);

	return 0;
}
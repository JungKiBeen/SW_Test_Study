#define _CRT_SECURE_NO_WARNINGS
#define KSIZE 1111
#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

int r_dir[] = { 0, -1, 1, 0, 0 }; int c_dir[] = { 0, 0, 0, -1, 1 };

int N, M, K;
int kx[KSIZE], ky[KSIZE], kn[KSIZE], kd[KSIZE]; // 1.. K

void input()
{
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 1; i <= K; i++)
		scanf("%d %d %d %d", &kx[i], &ky[i], &kn[i], &kd[i]);
}

inline int reverse(int dir)
{
	if (dir == 1) return 2;
	else if (dir == 2) return 1;
	else if (dir == 3) return 4;
	else return 3;
}

// 출력의 예외는 없음
int solve()
{
	vector<vector<int> > MAP(N+2, vector<int>(N+2, 0));
	vector<vector<int> > merge(N + 2, vector<int>(N + 2, 0));

	int t = 0;
	while (t != M)
	{
		for (int i = 1; i <= K; i++)
		{
			if (kn[i] == 0) continue;
			MAP[kx[i]][ky[i]] = 0;
			kx[i] += r_dir[kd[i]]; ky[i] += c_dir[kd[i]];
		} // for

		for (int i = 1; i <= K; i++)
		{
			if (kn[i] == 0) continue;

			if (kx[i] == 0 || kx[i] == N - 1 || ky[i] == 0 || ky[i] == N - 1)
			{
				kn[i] = kn[i] / 2;
				kd[i] = reverse(kd[i]);
			}

			if (MAP[kx[i]][ky[i]] == 0)
				MAP[kx[i]][ky[i]] = i;

			else
			{
				int c = MAP[kx[i]][ky[i]];
				MAP[kx[i]][ky[i]] = (kn[i] > kn[c]) ? i : c;
				merge[kx[i]][ky[i]] = t;
			}

		} //
	
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (merge[i][j] == t)
				{
					for (int k = 1; k <= K; k++)
					{
						if (kx[k] == i && ky[k] == j && k != MAP[i][j])
						{
							if (kn[k] == 0) continue;
							kn[MAP[i][j]] += kn[k];
							kn[k] = 0;
 						}
					}
				}
			}
		}
		t++;
	}

	int ret = 0;
	for (int k = 1; k <= K; k++)
	{
		ret += kn[k];
	}

	return ret;
}

int main()
{
//	freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++)
	{
		input();
		printf("#%d %d\n", tc, solve());
	}

	return 0;
}
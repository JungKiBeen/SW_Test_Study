#define _CRT_SECURE_NO_WARNINGS
#define SIZE 15
#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

bool c_row[SIZE], c_fdiag[SIZE*2], c_onediag[SIZE*2];
int map[SIZE][SIZE];
int N;

void dfs(int col, int &sol)
{
	if (col == N)
	{
		sol++;
		return;
	}

	for (int row = 0; row < N; row++)
	{
		int cur_fidag = col - row + (N - 1);	int cur_onediag = row + col;
		if (!c_row[row] && !c_fdiag[cur_fidag] && !c_onediag[cur_onediag])
		{
			c_row[row] = true; c_fdiag[cur_fidag] = true; c_onediag[cur_onediag] = true;
			dfs(col + 1, sol);
			c_row[row] = false; c_fdiag[cur_fidag] = false; c_onediag[cur_onediag] = false;
		}
	}
}

int main(void)
{
	cin >> N;

	int sol = 0;
	dfs(0, sol);
	cout << sol;
	return 0;
}

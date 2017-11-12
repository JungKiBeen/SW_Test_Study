#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<cstdio>
#include<cstdlib>
#include <assert.h>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

int n, MAX;
vector<vector<int> > map;

void __init__()
{
	MAX = -1;
	cin >> n;
	map = vector<vector<int> >(n * 2 - 1, vector<int>(n*2 - 1));
	int row = n - 1, col = 0;
	for(int i = 0; i < n ; i++)
	{
		int _row = row, _col = col;
		for (int j = 0; j < n; j++)
			cin >> map[_row--][_col++];
		row++, col++;
	}
}

int get_profit(int row1, int row2, int col1, int col2)
{
	int ret = 0;
	bool rowflag, colflag;
	vector<bool> desert(101, false); // 1 ~ 100
	for (int i = row1; i <= row2; i += 2)
	{
		if (i == row1 || i == row2) rowflag = true;
		else rowflag = false;
		for (int j = col1; j <= col2; j += 2)
		{
			if (j == col1 || j == col2) colflag = true;
			else colflag = false;

			if (!rowflag && !colflag) continue;
			if ((map[i][j] == 0) || desert[map[i][j]])
				return -1;	// 중복
			desert[map[i][j]] = true;
			ret++;
		}
	}
	return ret;
}

void dfs(int nr, int nc, int row1, int row2, int col1, int col2)
{
	if (nr == 2 && nc == 2)
	{
		assert(row1 < row2 && col1 < col2);
		int profit = get_profit(row1, row2, col1, col2);
		if (profit != -1)	MAX = max(MAX, profit);
		return;
	}

	if (row1 == -1)
	{
		for (int i = 0; i <= ((n - 1) * 2); i++)
			dfs(nr + 1, nc, i, row2, col1, col2);
	}
	// 항상 row1 < row2
	else if (row2 == -1)
	{
		for (int i = row1 + 2; i <= ((n - 1) * 2); i+=2)
				dfs(nr + 1, nc, row1, i, col1, col2);
	}

	else if (col1 == -1)
	{
		for (int i = 0; i <= ((n - 1) * 2); i++)
			dfs(nr, nc + 1, row1, row2, i, col2);
	}

	// 항상 col1 < col2
	else if (col2 == -1)
	{
		for (int i = col1+2; i <= ((n - 1) * 2); i+=2)
				dfs(nr, nc + 1, row1, row2, col1, i);
	}
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	freopen("sample_input.txt", "r", stdin);

	int T; cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		__init__();
		dfs(0, 0, -1, -1, -1, -1);
		cout << "#" << tc << " " << MAX << "\n";
	}

	return 0;
}
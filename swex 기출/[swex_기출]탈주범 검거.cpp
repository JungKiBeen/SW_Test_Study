#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int n, m, R, C, L;
vector<vector<int> > table;
vector<vector<bool> > visit;
//map<int, map<int, map<int, bool> > > rule;
bool rule[8][8][4];


int rdir[] = { -1, 0, 1, 0 };
int cdir[] = { 0, 1, 0, -1 };

struct elem
{
	int r, c, t;
};

void make_rule()
{
	rule[1][1][0] = true;
	rule[1][2][0] = true;
	rule[1][5][0] = true;
	rule[1][6][0] = true;

	rule[1][1][1] = true;
	rule[1][3][1] = true;
	rule[1][6][1] = true;
	rule[1][7][1] = true;

	rule[1][1][2] = true;
	rule[1][2][2] = true;
	rule[1][4][2] = true;
	rule[1][7][2] = true;

	rule[1][1][3] = true;
	rule[1][3][3] = true;
	rule[1][4][3] = true;
	rule[1][5][3] = true;

	rule[2][1][0] = true;
	rule[2][2][0] = true;
	rule[2][5][0] = true;
	rule[2][6][0] = true;

	rule[2][1][2] = true;
	rule[2][2][2] = true;
	rule[2][4][2] = true;
	rule[2][7][2] = true;

	rule[3][1][1] = true;
	rule[3][3][1] = true;
	rule[3][6][1] = true;
	rule[3][7][1] = true;

	rule[3][1][3] = true;
	rule[3][3][3] = true;
	rule[3][4][3] = true;
	rule[3][5][3] = true;

	rule[4][1][0] = true;
	rule[4][2][0] = true;
	rule[4][5][0] = true;
	rule[4][6][0] = true;

	rule[4][1][1] = true;
	rule[4][3][1] = true;
	rule[4][6][1] = true;
	rule[4][7][1] = true;

	rule[5][1][1] = true;
	rule[5][3][1] = true;
	rule[5][6][1] = true;
	rule[5][7][1] = true;

	rule[5][1][2] = true;
	rule[5][2][2] = true;
	rule[5][4][2] = true;
	rule[5][7][2] = true;

	rule[6][1][2] = true;
	rule[6][2][2] = true;
	rule[6][4][2] = true;
	rule[6][7][2] = true;

	rule[6][1][3] = true;
	rule[6][3][3] = true;
	rule[6][4][3] = true;
	rule[6][5][3] = true;

	rule[7][1][0] = true;
	rule[7][2][0] = true;
	rule[7][5][0] = true;
	rule[7][6][0] = true;

	rule[7][1][3] = true;
	rule[7][3][3] = true;
	rule[7][4][3] = true;
	rule[7][5][3] = true;

}

void __init__()
{
	cin >> n >> m >> R >> C >> L;
	table = vector<vector<int> >(n, vector<int>(m));
	visit = vector<vector<bool> >(n, vector<bool>(m, false));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> table[i][j];
}

int check_visit()
{
	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			if (visit[i][j])	ret++;
	}
	return ret;
}

int sol()
{
	queue<elem> q;
	elem t;
	t.r = R; t.c = C; t.t = 1;
	q.push(t);

	while (!q.empty())
	{
		t = q.front(); q.pop();
		if (t.t > L) break;
		visit[t.r][t.c] = true;

		for (int dir = 0; dir < 4; dir++)
		{
			elem tt;
			tt.r = t.r + rdir[dir];		tt.c = t.c + cdir[dir];
			if (tt.r < 0 || tt.r > n - 1 || tt.c < 0 || tt.c > m - 1)	continue;
			if (rule[table[t.r][t.c]][table[tt.r][tt.c]][dir] && !visit[tt.r][tt.c])
			{
				tt.t = t.t + 1;
				q.push(tt);
			}
		}
	}
	return check_visit();
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	//freopen("sample_input.txt", "r", stdin);
	int T; cin >> T;
	make_rule();

	for (int tc = 1; tc <= T; tc++)
	{
		__init__();
		cout << "#" << tc << " " << sol() << "\n";
	}
	return 0;
}
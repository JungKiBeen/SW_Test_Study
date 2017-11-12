#define _CRT_SECURE_NO_WARNINGS
#define SIZE 1111
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <utility>

using namespace std;

int r_dir[] = { -1, 0, 1, 0 };
int c_dir[] = { 0, 1, 0, -1 };

int ROW, COL;
int tomato[SIZE][SIZE];

set<pair<int, int>> s;

void __init__()
{
	scanf("%d %d", &COL, &ROW);
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			scanf("%d", &tomato[i][j]);
			if (tomato[i][j] == 1)
				s.insert(make_pair(i, j));
		}
	}
}

bool check()
{
	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COL; j++)
			if (tomato[i][j] == 0) return false;

	return true;
}

void ik()
{
	set<pair<int, int> > temp;
	set<pair<int, int> > ::iterator it;
	for (it = s.begin(); it != s.end(); ++it)
	{
		int r = it->first; int c = it->second;
		for (int i = 0; i < 4; i++)
		{
			int rr = r + r_dir[i];	int cc = c + c_dir[i];
			if (rr < 0 || rr >= ROW || cc < 0 || cc >= COL)
				continue;
			if (tomato[rr][cc] == 0)
			{
				tomato[rr][cc] = 1;
				temp.insert(make_pair(rr, cc));
			}
		}
	}

	s = temp;
}

int sol()
{
	// 다 익지 않음
	int ret = 0;
	while (!check())
	{
		ik();
		if (s.size() == 0)	return -1;
		ret++;
	}
	return ret;
}


int main(void)
{
	//freopen("input.txt", "r", stdin);
	__init__();

	printf("%d", sol());
	return 0;
	
}
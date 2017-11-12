#define TRUN_LEFT() d = (d + 3) % 4
#define TRUN_RIGHT() d = (d + 1) % 4
#define HORI 0
#define VERTI 1
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;

int r_dir[] = { -1, 0, 1, 0 };
int c_dir[] = { 0, 1, 0, -1 };


struct line
{
	int x1, y1, x2, y2, type;
	line(int _x1, int _y1, int _x2, int _y2) : x1(_x1), x2(_x2), y1(_y1), y2(_y2)
	{
		if (x1 == x2)     type = HORI;
		else if(y1 == y2)	type = VERTI;
		set_posi();
	}

	void set_posi()
	{
		if (x1 > x2) swap(x1, x2);
		if (y1 > y2) swap(y1, y2);
	}
};

vector<line> hori, verti;
int L, N;

long long solve()
{
	long long SEC = 0;
	int d = 1, hx = 0, hy = 0;
	scanf("%d", &N);

	for (int i = 1; i <= N + 1; i++)
	{
		int ti; char diri;
		if(i <= N) scanf("%d %c", &ti, &diri);
		else { ti = INT_MAX, diri = -1; }

		int dist = INT_MAX;

		if (d == 0)
		{
			int len = (int)hori.size();
			for (int i = 0; i < len; i++)
			{
				line ln = hori[i];
				if (ln.x1 < hx && ln.y2 >= hy && ln.y1 <= hy)
					dist = min(dist, hx - ln.x1);
			}

			len = (int)verti.size();
			for (int i = 0; i < len; i++)
			{
				line ln = verti[i];
				if (ln.y1 == hy && ln.x2 < hx)
					dist = min(dist, hx - ln.x2);
			}

		}
		else if (d == 2)
		{
			int len = (int)hori.size();
			for (int i = 0; i < len; i++)
			{
				line ln = hori[i];
				if (ln.x1 > hx && ln.y2 >= hy && ln.y1 <= hy)
					dist = min(dist, ln.x1 - hx);
			}

			len = (int)verti.size();
			for (int i = 0; i < len; i++)
			{
				line ln = verti[i];
				if (ln.y1 == hy && ln.x1 > hx)
					dist = min(dist, ln.x1 - hx);
			}
		}

		else if (d == 1)
		{
			int len = (int)verti.size();
			for (int i = 0; i < len; i++)
			{
				line ln = verti[i];
				if (ln.y1 > hy && ln.x2 >= hx && ln.x1 <= hx)
					dist = min(dist, ln.y1 - hy);
			}

			len = (int)hori.size();
			for (int i = 0; i < len; i++)
			{
				line ln = hori[i];
				if (ln.x1 == hx && ln.y1 > hy)
					dist = min(dist, ln.y1 - hy);
			}
		}

		else if(d == 3)
		{
			int len = (int)verti.size();
			for (int i = 0; i < len; i++)
			{
				line ln = verti[i];
				if (ln.y1 < hy && ln.x2 >= hx && ln.x1 <= hx)
					dist = min(dist, hy - ln.y1);
			}

			len = (int)hori.size();
			for (int i = 0; i < len; i++)
			{
				line ln = hori[i];
				if (ln.x1 == hx && ln.y2 < hy)
					dist = min(dist, hy - ln.y2);
			}
		}

		if (ti >= dist)
		{
			SEC += dist;
			break;
		}

		SEC += ti;

		int hxx = hx + r_dir[d] * ti; int hyy = hy + c_dir[d] * ti;
		if (d == 0 || d == 2)
			verti.push_back(line(hx, hy, hxx, hyy));
		else
			hori.push_back(line(hx, hy, hxx, hyy));
		
		hx = hxx, hy = hyy;

		if (diri == 'L')  TRUN_LEFT();
		else		TRUN_RIGHT();
	}

	return SEC;

}

int main(void)
{
	//freopen("input.txt", "r", stdin);
	scanf("%d", &L);
	
	hori.reserve(10000), verti.reserve(10000);
	
	hori.push_back(line(-L - 1, -L, -L - 1, L));
	hori.push_back(line(L + 1, -L, L + 1, L));
	verti.push_back(line(-L, -L - 1, L, -L - 1));
	verti.push_back(line(-L, L + 1, L, L + 1));

	printf("%lld", solve());
	return 0;
}
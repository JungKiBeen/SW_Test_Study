#define _CRT_SECURE_NO_WARNINGS
#define MSIZE 111
#define NVTD 1
#define EMTY -1
#define HOLE 0
 
#include <iostream>
#include<queue>
#include<utility>

using namespace std;

int r_dir[] = { -1, 0, 1, 0 };
int c_dir[] = { 0, 1, 0, -1 };

int MAP[MSIZE][MSIZE]; // 1.. 100
bool evtd[MSIZE][MSIZE]; // 1.. 100
int N, srcx, srcy;

void __init__()
{
	scanf("%d", &N);
	scanf("%d %d", &srcy, &srcx); 	MAP[srcx][srcy] = NVTD;

	for (int i = 2; i <= N; i++)
	{
		int r, c; // 1.. 100
		scanf("%d %d", &c, &r);
		MAP[r][c] = NVTD;
	}
	
}

int bfs()
{
	int SOL = 0;
	queue<pair<int, int> > q;

	q.push(make_pair(srcx, srcy));
	MAP[srcx][srcy]++;

	while (!q.empty())
	{
		pair<int, int> here = q.front(); 
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int rr = here.first + r_dir[i]; int cc = here.second + c_dir[i];
			if (MAP[rr][cc] == EMTY && MAP[rr][cc] != HOLE) SOL++;

			else if (MAP[rr][cc] == NVTD)
			{
				MAP[rr][cc]++;
				q.push(make_pair(rr, cc));
			}
		}
	}
	return SOL;
}


void mk_emty(int x, int y)
{
	queue<pair<int, int> > q;

	q.push(make_pair(x, y));
	evtd[x][y] = true;
	MAP[x][y] = EMTY;

	while (!q.empty())
	{
		pair<int, int> here = q.front();	q.pop();
		for (int i = 0; i < 4; i++)
		{
			int rr = here.first + r_dir[i]; int cc = here.second + c_dir[i];
			if (rr < 0 || rr >= MSIZE || cc < 0 || cc >= MSIZE) continue;

			if (MAP[rr][cc] == HOLE && !evtd[rr][cc])
			{
				MAP[rr][cc] = EMTY;
				evtd[rr][cc] = true;
				q.push(make_pair(rr, cc));
			}
		}
	}
}


int main(void)
{
	__init__();
	mk_emty(0,0);
	printf("%d", bfs());

	return 0;
}
#include<cstdio>
#include<iostream>
using namespace std;

int mat[20][20];
int dr[] = { 0, 0,0,-1,1 };	int dc[] = { 0, 1, -1, 0 ,0 };
int op[1000];
int d[7];

void smove()
{
	int temp = d[1];
	d[1] = d[2];
	d[2] = d[6];
	d[6] = d[5];
	d[5] = temp;
}

void wmove()
{
	int temp = d[1];
	d[1] = d[3];
	d[3] = d[6];
	d[6] = d[4];
	d[4] = temp;
}

void nmove()
{
	int temp = d[1];
	d[1] = d[5];
	d[5] = d[6];
	d[6] = d[2];
	d[2] = temp;
}

void emove()
{
	int temp = d[1];
	d[1] = d[4];
	d[4] = d[6];
	d[6] = d[3];
	d[3] = temp;
}

int main()
{
	//freopen("a.txt", "r", stdin);
	int n, m, x, y, k;
	cin >> n >> m >> x >> y >> k;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &mat[i][j]);	// mat[0..n-1][0..m-1]
		}
	}

	for (int i = 0; i < k; i++)
	{
		scanf("%d", &op[i]);		// op[0..k-1]
	}

	for (int i = 0; i < k; i++)
	{
		int xx = x + dr[op[i]];
		int yy = y + dc[op[i]];
		if (xx < 0 || xx >= n || yy < 0 || yy >= m)	continue;

		x = xx;	y = yy;

		switch (op[i])
		{
		case 1:
			emove();
			break;
		case 2:
			wmove();
			break;
		case 3:
			nmove();
			break;
		case 4:
			smove();
			break;
		}

		if (mat[x][y] == 0)
		{
			mat[x][y] = d[6];
		}

		else
		{
			d[6] = mat[x][y];
			mat[x][y] = 0;
		}

		printf("%d\n", d[1]);
	}

	return 0;
}
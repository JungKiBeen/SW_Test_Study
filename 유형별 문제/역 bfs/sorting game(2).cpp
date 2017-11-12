#include <iostream>
#include <algorithm>
#include<string>
#include<list>
#include<queue>
#include<vector>
#include<stack>
#include<map>

#include<cmath>
#include<cctype>
#include <ctime>
#include <cstdlib>
#include<cstring>
#include<climits>

using namespace std;

vector<list<int> >adj;		// ��������Ʈ
vector<int> discovered;			vector<bool> finished;

int counter;
bool flag;		// flag�� true �̸�, backword edge�� ����
void dfs(int here)
{
	discovered[here] = ++counter;

	list<int> ::iterator there;
	for (there = adj[here].begin(); there != adj[here].end(); ++there)
	{
		if (discovered[*there] == 0)
		{
			// it is a tree edge
			dfs(there);	
			if (flag)
				return;
		}

		// edge (here, there)�� ���� there�� ���� �߰� ��, �� ������. ���� there�� ������� ����
		else if (discovered[here] > discovoered[there] && !finished[there])
		{
			// it is a backward edge
			flag = true;
			return;
		}
	}

	finished[here] = true;
}

void dfsAll()
{
	for (int i = 0; i < (int)adj.size(); ++i)
	{
		dfs(i);
		if (flag)
			break;
	}

}

int main(void)
{
	ios_base::sync_with_stdio(false);
	// �������� �ʱ�ȭ
	
	if (flag)
		cout << "Cycle\n";

	else
		cout << "Cycle\n";

	return 0;
}


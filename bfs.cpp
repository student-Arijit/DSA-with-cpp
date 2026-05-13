#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph
{
	int v;
	list<int> *l;

public:
	Graph(int v)
	{
		this->v = v;
		l = new list<int>[v];
	}

	void addedge(int v, int u)
	{
		l[u].push_back(v);
		l[v].push_back(u);
	}

	void bfs()
	{
		queue<int> Q;
		vector<bool> vis(v, false);

		Q.push(0);
		vis[0] = true;
		while (Q.size() > 0)
		{
			int u = Q.front();
			Q.pop();
			cout << u << " ";
			for (int v : l[u])
			{
				if (!vis[v])
				{
					vis[v] = true;
					Q.push(v);
				}
			}
		}
		cout << endl;
	}
};

int main()
{
	Graph g(5);
	g.addedge(0, 1);
	g.addedge(1, 2);
	g.addedge(1, 3);
	g.addedge(2, 3);
	g.addedge(2, 4);

	g.bfs();
	return 0;
}

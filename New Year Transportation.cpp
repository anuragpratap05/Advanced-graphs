# Advanced-graphs#include<bits/stdc++.h>
using namespace std;

map<int, vector<int> > l;
class graph
{
	int v;

public:
	graph(int v)
	{
		this->v = v;
	}

	void addedge(int x, int y)
	{
		l[x].push_back(y);
	}

	bool dfs(int src, int dest)
	{
		//cout << src << endl;
		if (src == dest)
		{
			return true;
		}

		for (auto x : l[src])
		{
			bool y = dfs(x, dest);
			if (y)
			{
				return true;
			}
		}

		return false;
	}



};

int main()
{


	int n;
	int dest;


	cin >> n >> dest;

	graph g(n);
	int *a = new int[n + 1];

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	for (int i = 1; i < n; i++)
	{
		g.addedge(i, i + a[i]);
	}

	if (g.dfs(1, dest))
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}









}

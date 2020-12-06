# Advanced-graphs
#include<bits/stdc++.h>
using namespace std;

void bfs(vector<int>* edges, int start, vector<int>* component, bool* visited)
{
	visited[start] = true;
	component->push_back(start);

	for (int i = 0; i < edges[start].size(); i++)
	{
		int nbr = edges[start][i];
		if (!visited[nbr])
		{
			bfs(edges, nbr, component, visited);
		}
	}
}

vector<vector<int>*>* get_components(vector<int>* edges, int n)
{
	bool* visited = new bool[n];
	for (int i = 0; i < n; i++)
	{
		visited[i] = false;
	}

	vector<vector<int>*>* output = new vector<vector<int>*>();
	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			vector<int>* component = new vector<int>();
			bfs(edges, i, component, visited);
			output->push_back(component);
		}
	}
	return output;
}

int main()
{

	int t;
	cin >> t;
	while (t--)
	{

		int n;
		cin >> n;
		vector<int>* edges = new vector<int>[n];
		int m;
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			int x, y;
			cin >> x >> y;
			edges[x - 1].push_back(y - 1);
			edges[y - 1].push_back(x - 1);
		}

		long long a[n];
		for (int i = 0; i < n; i++)
		{
            long long q;
            cin>>q;
            a[i]=q;
			//cin >> a[i];
		}
		//int src;
		//cin >> src;

		vector<vector<int>*>* components = get_components(edges, n);

		long long ans = 0;
		long long max = 0;
		for (auto sets : *components)
		{
			ans = 0;
			for (auto x : *sets)
			{
				ans += a[x];
				//cout << a[x]  << " ";
			}

			//cout << ans << endl;
			if (ans > max)
				max = ans;

			//cout << endl;
		}
		cout << max << endl;
	}

}

# Advanced-graphs
#include<bits/stdc++.h>
using namespace std;

void bfs(vector<int>* edges, int n)
{
	//int level = 0;
	//bool visited[n];

	int dist[n];
    for(int i=0;i<n;i++)
    {
        dist[i]=INT_MAX;
    }

	queue<int> q;

	q.push(0);
	dist[0] = 0;
	//visited[0] = true;
	while (!q.empty())
	{
		int node = q.front();
		//cout << node + 1 << " ";
		q.pop();
		for (int i = 0; i < edges[node].size(); i++)
		{
			int nbr = edges[node][i];
			if (dist[nbr] == INT_MAX)
			{
				//level++;
				//cout << "aya";
				q.push(nbr);
				dist[nbr] = dist[node] + 1;
			}
			//level++;
		}
		//level++;
	}

	/*for (auto x : dist)
	{
		cout << x.first << " " << x.second << endl;
	}*/
	cout << dist[n - 1] << endl;
	//q.clear();

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

		//int src;
		//cin >> src;

		bfs(edges, n);
		edges->clear();
	}
}

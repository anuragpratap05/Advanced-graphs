# Advanced-graphs
//# C_B_Graph_Algorithms
#include<bits/stdc++.h>
using namespace std;

class graph
{
    int V;
    vector<vector<int>> edgelist;
public:
    graph(int V)
    {
        this->V = V;
    }
    void addedge(int x, int y, int w)
    {
        edgelist.push_back({w, x, y});
    }

    int findset(int x, int *parent)
    {
        if (parent[x] == -1)
        {
            return x;
        }
        return parent[x] = findset(parent[x], parent);
    }

    void union_set(int x, int y, int *parent, int *rank)
    {
        int s1 = findset(x, parent);
        int s2 = findset(y, parent);
        if (s1 != s2)
        {
            if (rank[s1] < rank[s2])
            {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else
            {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }

    pair<int, int> kruksal (int a)
    {
        int* parent = new int[V];
        int* rank = new int[V];
        for (int i = 0; i < V; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }
        int ans = 0;
        sort(edgelist.begin(), edgelist.end());
        for (auto edges : edgelist)
        {
            int w = edges[0];
            int x = edges[1];
            int y = edges[2];
            if (w >= a)
                break;

            int s1 = findset(x, parent);
            int s2 = findset(y, parent);
            if (s1 != s2)
            {
                ans += w;
                union_set(s1, s2, parent, rank);
            }


        }
        int c = 0;
        for (int i = 0; i < V; i++)
        {
            //cout << parent[i] << " ";
            if (parent[i] == -1)
                c++;
        }
        auto pair = make_pair(ans, c);
        delete [] parent;
        return pair;
    }
};

int main()
{

    int cc = 1;
    int t;
    cin >> t;
    while (t--)
    {
        /*graph g(5);
        g.addedge(0, 1, 20);
        g.addedge(2, 1, 30);
        g.addedge(3, 4, 40);*/
        //g.addedge(3, 0);
        int n, m, a;
        cin >> n >> m >> a;

        graph g(n);

        for (int i = 0; i < m; i++)
        {
            int x, y, c;
            cin >> x >> y >> c;
            g.addedge(x - 1, y - 1, c);
        }
        //g.kruksal(500);
        auto z = g.kruksal(a);
        int final = z.first + z.second * a;
        cout << "Case #" << cc++ << ":" << " " << final << " " << z.second << endl;
    }
    //cout << z.first << " " << z.second;
}


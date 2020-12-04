# Advanced-graphs
#include<bits/stdc++.h>
using namespace std;

void bfs(vector<int>* edges, int start, bool* visited, stack<int> & finishedvertices)
{
    visited[start] = true;
    for (int i = 0; i < edges[start].size(); i++)
    {
        int adjascent = edges[start][i];
        if (!visited[adjascent])
        {
            bfs(edges, adjascent, visited, finishedvertices);
        }
    }
    finishedvertices.push(start);
}

void bfs2(vector<int>* edges, int start, bool* visited, unordered_set<int>* component)
{
    visited[start] = true;
    component->insert(start);
    for (int i = 0; i < edges[start].size(); i++)
    {
        int adjascent = edges[start][i];
        if (!visited[adjascent])
        {
            bfs2(edges, adjascent, visited, component);
        }
    }
    //finishedvertices.push(start);
}

unordered_set<unordered_set<int>*>* getssc(vector<int>* edges, vector<int>* edgesT, int n)
{
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    stack<int> finishedvertices;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bfs(edges, i, visited, finishedvertices);
        }
    }

    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();

    while (!finishedvertices.empty())
    {
        int element = finishedvertices.top();
        finishedvertices.pop();
        if (visited[element])
        {
            continue;
        }
        unordered_set<int>* component = new unordered_set<int>();
        bfs2(edgesT, element, visited, component);
        output->insert(component);
    }
    return output;
}

int main()
{
#ifndef ONLINE_jUDGE
    freopen("input3.txt", "r", stdin);
    freopen("output3.txt", "w", stdout);
#endif
    int n;
    cin >> n;

    vector<int>* edges = new vector<int>[n];
    vector<int>* edgesT = new vector<int>[n];

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        edges[x - 1].push_back(y - 1);
        edgesT[y - 1].push_back(x - 1);

    }

    unordered_set<unordered_set<int>*>* components = getssc(edges, edgesT, n);

    for (auto sets : *components)
    {
        for (auto x : *sets)
        {
            cout << x + 1 << " ";
        }
        cout << endl;
    }

}

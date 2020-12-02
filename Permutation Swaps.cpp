#include <iostream>
#include <vector>
#include <unordered_set>
#include<bits/stdc++.h>
using namespace std;

void dfs(int start, vector<int>* edges, int n, unordered_set<int>& visited, unordered_set<int> * component) {
    visited.insert(start);
    component->insert(start);
    vector<int>::iterator it = edges[start].begin();
    for (; it != edges[start].end(); it++) {
        int i = *it;
        if (visited.count(i) > 0) {
            continue;
        }
        dfs(i, edges, n, visited, component);
    }
}

unordered_set<unordered_set<int>*>* getComponents(vector<int>* edges, int n) {
    unordered_set<int> visited;
    unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();
    for (int i = 0; i < n; i++) {
        if (visited.count(i) == 0) {
            unordered_set<int> * component = new unordered_set<int>();
            dfs(i, edges, n, visited, component);
            output->insert(component);
        }
    }
    return output;
}

int main() {

    int t;
    cin >> t;
    while (t--)
    {


        int n;
        cin >> n;
        vector<int>* edges = new vector<int>[n];



        int m;
        cin >> m;

        int p[n + 1] ;
        int q[n + 1] ;
        for (int i = 1; i <= n; i++)
        {
            cin >> p[i];
        }

        for (int i = 1; i <= n; i++)
        {
            cin >> q[i];
        }
        //cout << p[4] << endl;


        for (int i = 0; i < m; i++) {
            int j, k;
            cin >> j >> k;
            edges[j - 1].push_back(k - 1);
            edges[k - 1].push_back(j - 1);
        }

        vector<int> v1;
        vector<int> v2;
        int flag = 0;
        unordered_set<unordered_set<int>*>* components = getComponents(edges, n);
        unordered_set<unordered_set<int>*>::iterator it = components->begin();
        while (it != components->end()) {
            unordered_set<int>* component = *it;
            unordered_set<int>::iterator it2 = component->begin();
            while (it2 != component->end()) {
                //cout << "component " << *it2 + 1 << " ";
                v1.push_back(p[*it2 + 1]);
                v2.push_back(q[*it2 + 1]);
                //cout << p[*it2 + 1];
                it2++;
            }
            //cout << endl;
            sort(v1.begin(), v1.end());
            sort(v2.begin(), v2.end());
            /*cout << "v1" << endl;
            for (auto x : v1)
            {
                cout << x << " ";
            }
            cout << endl;
            cout << "v2" << endl;*/
            /*for (auto y : v2)
            {
                cout << y << " ";
            }*/

            for (int i = 0; i < v2.size(); i++)
            {
                //cout << v1[i] << " " << v2[i] << endl;
                if (v1[i] != v2[i])
                {
                    flag = 1;
                }
            }

            v1.clear();
            v2.clear();

            //cout << endl;
           // delete component;
            it++;
        }
        //v1.clear();
        //v2.clear();
        if (flag == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    //delete components;
    //delete edges;
}








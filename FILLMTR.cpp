# Advanced-graphs
#include<bits/stdc++.h>
using namespace std;

vector<long long> gp[100010];
pair<long long,pair<long long, long long>> query[1000010];
long long n,q;
long long color[100010];
map<long long,map<long long,long long>> m;

bool isBipartiteUtil(long long src){
    color[src] = 1;
    queue<long long> q;
    q.push(src);
    while(!q.empty()){
        long long u = q.front();
        q.pop();
        for(int v=0;v<gp[u].size();v++){
            int vv = gp[u][v];
            int c = m[u][vv];
            if(color[vv] == -1){
                if(c==0) color[vv] = color[u];
                else color[vv] = 1-color[u];
                q.push(gp[u][v]);
            }else if(abs(color[gp[u][v]]-color[u])!=c) return false;
        }
    }
    return true;
}

bool isBipartite(){
    for(int i=0;i<=n;i++) color[i] = -1;
    for(int i=1;i<=n;i++){
        if(color[i] == -1 && gp[i].size()>=1){
            if(isBipartiteUtil(i)==false) return false;
        }
    }
    return true;
}

int main(){
    long long t;
    cin>>t;
    while(t--){
        long long i=0;
        m.clear();
        bool ans = true;
        cin>>n>>q;
        for(long long j=0;j<=n;j++) gp[j].clear();
        while(i<q){
            long long a,b,c;
            cin>>a>>b>>c;
            query[i].first = a;
            query[i].second.first = b;
            query[i].second.second = c;
            gp[a].push_back(b);
            gp[b].push_back(a);
            if(m.find(a)!=m.end() && m[a].find(b)!=m[a].end()){
                int tt = m[a][b];
                if(tt!=c) ans=false;
            }
            else if(m.find(b)!=m.end() && m[b].find(a)!=m[b].end()){
                int tt = m[b][a];
                if(tt!=c) ans=false;
            }else m[a][b] = m[b][a] = c;
            i++;
        }
        if(ans==false){
            cout<<"no\n";
            continue;
        }
        ans = isBipartite();
        if(ans==false) cout<<"no\n";
        else cout<<"yes\n";
    }
    return 0;
}

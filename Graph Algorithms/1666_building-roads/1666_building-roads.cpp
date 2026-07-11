#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1);

    for(int i=0; i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n + 1, 0);
    vector<int> rep;
    for (int i =1; i<=n;i++) {
        if(!vis[i]){
            rep.push_back(i);
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int it : adj[node]) {
                    if (!vis[it]) {
                        vis[it] = 1;
                        q.push(it);
                    }
                }
            }
        }
    }

    cout<<rep.size()-1<<"\n";

    for (int i=1;i<rep.size(); i++) {
        cout <<rep[0]<<" "<<rep[i] <<"\n";
    }

    return 0;
}
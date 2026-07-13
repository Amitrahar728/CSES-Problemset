#include <bits/stdc++.h>
using namespace std;
int MOD = 1e9+7;

int main() {

    int n,m ;
    cin>>n>>m;
    vector<int> parent(n+1 ,-1);
    vector<int> indegree(n+1,0);
    vector<vector<int>> adj(n+1);
    while(m--){
        int x, y;
        cin>>x>>y;
        indegree[y]++;
        adj[x].push_back(y);
    }
    vector<int> topo;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }
    // int cnt =0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(int edge : adj[node]) {
            indegree[edge]--;
            // if(edge == n){
            //     cnt++;
            // }
            if(indegree[edge] == 0)
                q.push(edge);
        }
    }

    int cnt =0;
    vector<int> dp(n+1 , 0);
    dp[1]= 1;
    for(int i : topo){
        for(int edge: adj[i]){
           dp[edge] = (dp[i]+dp[edge])%MOD;
        }
    }
    cout<<dp[n]<<endl;
    return 0; 
}

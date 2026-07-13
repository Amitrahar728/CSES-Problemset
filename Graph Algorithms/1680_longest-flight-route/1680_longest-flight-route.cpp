#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin>>n>>m;
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

    while (!q.empty()) {
    int node = q.front();
    q.pop();
    topo.push_back(node);

    for (int edge : adj[node]) {
        indegree[edge]--;
        if (indegree[edge] == 0)
            q.push(edge);
    }
    }
    //12354
    vector<int> dp(n+1 , -1e9);
    dp[1] = 1;
    for(int i : topo){
        if (dp[i] == -1e9) continue;
        for(int edge: adj[i]){
            if(dp[edge]<1+dp[i]){
                dp[edge] = dp[i]+1;
                parent[edge] = i;
            }
        }
    }
    if (dp[n] == -1e9) {
    cout << "IMPOSSIBLE\n";
    return 0;
}
else {
    cout<<dp[n]<<endl;
    vector<int> ans;
    int val = n;
    while(val!=-1){
        ans.push_back(val);
        val = parent[val];
    }
    reverse(ans.begin(), ans.end());
    for(int x: ans){
        cout<<x<<" ";
    }
    cout<<endl;
}
    return 0;
}

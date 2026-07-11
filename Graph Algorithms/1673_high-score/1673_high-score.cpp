#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int start , end ; 
    long long weight;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //  in simple words bellman's ford algorithm is mentioned above 
    // told us that graph is negative weighted and find from one source to other and can have negative weight 
    // if there is a positive or negative weight cycle then the price increases too high return -1 .
    // vo hum detect kr shkte h nth relaxation pr change ho tohh 
    // bellman ford : we do relaxation of edges for n-1 times 

    long long n ,m ; cin>>n>>m;
    const long long INF = 1e18;
    vector<long long> dist(n+1, INF);
    dist[1] = 0;
    vector<Edge> adj;
    adj.reserve(m);
    vector<vector<int>> g(n+1);
    while(m--){
        int x, y; long long z;
        cin>>x>>y>>z;
        adj.push_back({x, y, -z});
        g[x].push_back(y);
    }

    for(int i =1 ; i<=n-1; i++){
        for(const Edge &e: adj){
            if(dist[e.start] != INF && dist[e.start]+e.weight < dist[e.end]){
                dist[e.end] = dist[e.start] + e.weight;
            } 
        }
    }

    // nth relaxation pr jo bhi change ho unhe queue me daal denge
    queue<int> q;
    vector<bool> inCycle(n+1, false);
    for(const Edge&e: adj){
        if(dist[e.start] != INF && dist[e.start]+e.weight < dist[e.end]){
            if(!inCycle[e.end]){
                inCycle[e.end] = true;
                q.push(e.end);
            }
        } 
    }

    // ab in sabse BFS krke dekhenge ki n tak pohoch pa rhe h ya nahi
    vector<bool> visited = inCycle;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : g[u]) if(!visited[v]){ visited[v] = true; q.push(v); }
    }

    if(visited[n]){
        cout<<-1<<endl;
    }
    else {
        cout<<-dist[n]<<endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;
const int MOD = 1e9 + 7;

int main() {
    int n , m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n+1);
    while(m--){
        int a , b, c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    vector<ll> dist(n + 1, INF);
    vector<ll> ways(n + 1, 0);
    vector<int> mn(n + 1, INT_MAX);
    vector<int> mx(n + 1, INT_MIN);
    priority_queue<pair <ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    dist[1] = 0; // starting node h ye 
    ways[1] = 1; // minimum ek to hoga hi 
    mn[1] = 0; // minimum 0 route start m 
    mx[1] = 0;

    pq.push({0, 1});

    while (!pq.empty()){
        auto [d, node] =pq.top();
        pq.pop();
        if(d>dist[node]) continue;
        for (auto [next, wt] : adj[node]) {
            if (dist[next] > dist[node]+ wt) {
                dist[next]= dist[node]+wt;
                ways[next]= ways[node];
                mn[next] =mn[node]+1;
                mx[next] =mx[node]+1;
                pq.push({dist[next],next});
            }
            else if(dist[next]==dist[node]+wt){
                ways[next]=(ways[next]+ways[node])%MOD;
                mn[next] = min(mn[next], mn[node] + 1);
                mx[next]= max(mx[next], mx[node] + 1);
            }
        }
    }
    cout <<dist[n]<<" "
         <<ways[n] << " "
         <<mn[n]<< " "
         << mx[n]<<endl;

    return 0;
}

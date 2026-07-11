#include <bits/stdc++.h>
using namespace std;
struct Edge{
    int start, end;
    long long weight;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // bellman ford se cycle pta lagalo and parent vector banalo
    //taki jab koi node nth relaxation m relax ho to usse backtrack kr shke uss tak 

    int n, m; cin >> n >> m;
    vector<Edge> adj;
    while(m--){
        int x, y, z;
        cin >> x >> y >> z;
        adj.push_back({x, y, z});
    }

    long long INF = 1e18;
    vector<long long> dist(n+1, 0);   // all nodes start at 0, so any cycle is detectable
    vector<int> parent(n+1, -1);

    // relaxation for n times (nth pass btayega cycle h ya nahi)
    int x = -1;
    for(int i = 1; i <= n; i++){
        x = -1;
        for(const Edge &e : adj){
            if(dist[e.start] + e.weight < dist[e.end]){
                dist[e.end] = dist[e.start] + e.weight;
                parent[e.end] = e.start;
                x = e.end;
            }
        }
    }

    if(x == -1){
        cout << "NO" << endl;
    } else {
        // walk back n times to guarantee landing inside the cycle
        for(int i = 0; i < n; i++){
            x = parent[x];
        }

        // ab x pkka cycle ke andar h, isse chalke cycle bana lo
        vector<int> cycle;
        for(int v = x; ; v = parent[v]){
            cycle.push_back(v);
            if(v == x && cycle.size() > 1) break;
        }
        reverse(cycle.begin(), cycle.end());

        cout << "YES" << endl;
        for(int v : cycle) cout << v << " ";
        cout << endl;
    }

    return 0;
}
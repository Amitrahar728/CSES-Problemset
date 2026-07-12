#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
// modified dijkstra instead of we keep only track of shortest distance yaha hum pura ek vector rakhenge k shortest values ka 
    vector<vector<pair<int, int>>> adj(n + 1);

    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    vector<vector<ll>> dist(n + 1);

    priority_queue<
        pair<ll, int>,
        vector<pair<ll, int>>,
        greater<pair<ll, int>>
    > pq;

    dist[1].push_back(0);
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (dist[u].back() < d)  continue;
        for (auto [v, w] : adj[u]) {
            ll nd = d + w;
            
            if (dist[v].size() < k) {
                dist[v].push_back(nd);
                sort(dist[v].begin(), dist[v].end());
                pq.push({nd, v});
            }
            else if (nd < dist[v].back()) {
                dist[v].back() = nd;
                sort(dist[v].begin(), dist[v].end());
                pq.push({nd, v});
            }
        }
    }

    for (ll x : dist[n])
        cout << x << " ";

    cout << "\n";

    return 0;
}
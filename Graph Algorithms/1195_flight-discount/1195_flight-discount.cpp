#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    vector<vector<int>> dist(n + 1, vector<int>(2, INF));
    priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>
    > pq;

    dist[1][0] = 0;
    pq.push({0, {1, 0}});

    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();

        int d = it.first;
        int node = it.second.first;
        int used = it.second.second;

        if (d > dist[node][used]) continue;

        for (auto edge : adj[node]) {
            int next = edge.first;
            int wt = edge.second;

            if (dist[next][used] > d + wt) {
                dist[next][used] = d + wt;
                pq.push({dist[next][used], {next, used}});
            }
            if (used == 0 && dist[next][1] > d + wt / 2) {
                dist[next][1] = d + wt / 2;
                pq.push({dist[next][1], {next, 1}});
            }
        }
    }

    cout << dist[n][1] << "\n";

    return 0;
}
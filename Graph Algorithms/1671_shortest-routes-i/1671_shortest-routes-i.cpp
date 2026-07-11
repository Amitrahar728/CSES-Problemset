#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
    }

    priority_queue< pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    vector<long long> dist(n + 1, 1e18);
    dist[1] = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        long long dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if (dis>dist[node]) continue;
        for (auto it : adj[node]) {
            int adja=it.first;
            int edge=it.second;

            if(dis+ edge < dist[adja]) {
                dist[adja] = dis + edge;
                pq.push({dist[adja], adja});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}
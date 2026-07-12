#include <bits/stdc++.h>
using namespace std;

int startNode = -1, endNode = -1;

bool dfs(int node, vector<vector<int>> &adj,
         vector<int> &vis,
         vector<int> &pathVis,
         vector<int> &parent) {

    vis[node] = 1;
    pathVis[node] = 1;

    for (auto it : adj[node]) {

        if (!vis[it]) {

            parent[it] = node;

            if (dfs(it, adj, vis, pathVis, parent))
                return true;
        }
        else if (pathVis[it]) {

            startNode = it;
            endNode = node;
            return true;
        }
    }

    pathVis[node] = 0;
    return false;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    while (m--) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    vector<int> vis(n + 1, 0);
    vector<int> pathVis(n + 1, 0);
    vector<int> parent(n + 1, -1);

    bool found = false;

    for (int i = 1; i <= n; i++) {

        if (!vis[i]) {

            if (dfs(i, adj, vis, pathVis, parent)) {
                found = true;
                break;
            }
        }
    }

    if (!found) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<int> cycle;

    cycle.push_back(startNode);

    int cur = endNode;

    while (cur != startNode) {
        cycle.push_back(cur);
        cur = parent[cur];
    }

    cycle.push_back(startNode);

    reverse(cycle.begin(), cycle.end());

    cout << cycle.size() << "\n";

    for (auto x : cycle)
        cout << x << " ";

    cout << "\n";
}
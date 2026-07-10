#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> vis, parent;
vector<int> cycle;

bool dfs(int node, int par) {
    vis[node] = 1;
    parent[node] = par;

    for (int x : adj[node]) {
        if (x == par) continue;

        if (!vis[x]) {
            if (dfs(x, node)) return true;
        }
        else {
            cycle.push_back(x);

            int cur = node;
            while (cur != x) {
                cycle.push_back(cur);
                cur = parent[cur];
            }

            cycle.push_back(x);
            reverse(cycle.begin(), cycle.end());
            return true;
        }
    }

    return false;
}

int main() {
    cin >> n >> m;

    adj.resize(n + 1);
    vis.assign(n + 1, 0);
    parent.assign(n + 1, -1);

    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool found = false;

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (dfs(i, -1)) {
                found = true;
                break;
            }
        }
    }

    if (!found) {
        cout << "IMPOSSIBLE\n";
    }
    else {
        cout << cycle.size() << "\n";
        for (int x : cycle) {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}
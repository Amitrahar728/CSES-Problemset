#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> vis(n + 1, -1);
    queue<int> q;
    vector<int> parent(n + 1, -1);

    q.push(1);
    vis[1] = 0;

    // int steps = 0;
    bool check = false;

    while (!q.empty()) {
        int sz = q.size();
        // steps++;

        if (check == true) {
            break;
        }

        for (int i = 0; i < sz; i++) {
            int node = q.front();
            q.pop();

            if (check == true) {
                break;
            }

            for (int z : adj[node]) {
                if (z == n) {
                    check = true;
                    vis[z] = 0;
                    parent[z] = node;
                    break;
                }

                if (vis[z] == -1) {
                    vis[z] = 0;
                    parent[z] = node;
                    q.push(z);
                }
            }
        }
    }
    vector<int> ans;
    
    if (check) {
        // cout << steps << endl;
        ans.push_back(n);
        int val = n;
        while (val != 1) {
            val = parent[val];
            ans.push_back(val);
        }
        cout<<ans.size()<<endl;
        for(int i = ans.size()-1; i>=0; i--){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}   vector<int> ans;

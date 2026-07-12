#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector < int > indegree(n + 1, 0);
    vector < vector < int >> adj(n + 1);
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        indegree[y]++;
        adj[x].push_back(y);
    }
    vector < int > ans;
    queue < int > q;
    vector<int> vis(n+1 , -1);
    for (int i = 1; i < n + 1; i++)
    {
        if (indegree[i] == 0  && vis[i] == -1)
        {
            q.push(i);
            vis[i] = 0;
            // ans.push_back(i);
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                ans.push_back(node);
                for (int x: adj[node])
                {
                    indegree[x]--;
                    if (indegree[x] == 0)
                    {
                        q.push(x);
                        vis[x] = 0;
                        // ans.push_back(x);
                    }
                }
            }
        }
    }
    // cout << ans.size() << endl;
    // for (int x: ans) {
    //         cout << x << " ";
    // }
    //     cout << endl;
    if (ans.size() == n) {
        for (int x: ans) {
            cout << x << " ";
        }
        cout << endl;
    }
    else {
        cout << "IMPOSSIBLE" << endl;
    }


    return 0;
}
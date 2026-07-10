#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    // matlb ki bipartite graph ka variation hai 
    // easily jo nodes connected h unko color krke group verify krlo 
    
    vector<vector<int>> adj(n + 1);

    while (m--)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> colors(n + 1, -1);
    queue<int> q;
    bool check = true;

    for (int i = 1; i <= n; i++)
    {
        if (colors[i] == -1)
        {
            q.push(i);
            colors[i] = 0;

            while (!q.empty())
            {
                int node = q.front();
                q.pop();

                for (int x : adj[node])
                {
                    if (colors[x] == -1)
                    {
                        colors[x] = 1 - colors[node];
                        q.push(x);
                    }
                    else if (colors[x] == colors[node])
                    {
                        check = false;
                        break;
                    }
                }

                if (!check)
                    break;
            }

            if (!check)
                break;
        }
    }

    if (!check)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            cout << colors[i] + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}
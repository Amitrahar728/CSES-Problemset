#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));

    queue<pair<int, int>> q;
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    //shortest pucha h tohh BFS kro 
    vector<vector<pair<int,int>>> parent(n,
        vector<pair<int,int>>(m, {-1,-1}));
    vector<vector<char>> moveTaken(n,
        vector<char>(m));

    pair<int,int> start, finish;
    // sabse pehle A and b ko store krlo kyunki given nhi h
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];

            if (grid[i][j] == 'A') {
                start = {i,j};
                q.push({i,j});
                vis[i][j] = true;
            }

            if(grid[i][j]=='B')
                finish={i,j};
        }
    }

    vector<int> row = {-1, 1, 0, 0};
    vector<int> col = {0, 0, -1, 1};
    vector<char> dir = {'U','D','L','R'};

    bool check = true;
    // int steps = -1;
    // traverse kro 
    while (!q.empty()) {
        int sz = q.size();
        // steps++;

        if (!check) break;

        for (int j = 0; j < sz; j++) {

            auto it = q.front();
            q.pop();

            if (!check) break;

            for (int i = 0; i < 4; i++) {
                int newx = it.first + row[i];
                int newy = it.second + col[i];
                // range m h ya nhi 
                if (newx >= 0 && newx < n &&
                    newy >= 0 && newy < m &&
                    !vis[newx][newy] &&
                    grid[newx][newy] != '#') {

                    vis[newx][newy] = true;
                    // parent kya h vo yadd rakhlo
                    parent[newx][newy] = {it.first,it.second};
                    moveTaken[newx][newy] = dir[i];

                    if (grid[newx][newy] == 'B') {
                        check = false;
                        // steps++;
                        break;
                    }

                    q.push({newx,newy});
                }
            }
        }
    }

    if (check) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
        string path;
        pair<int,int> cur = finish;
        while(cur != start){
            char ch = moveTaken[cur.first][cur.second];
            path.push_back(ch);
            cur = parent[cur.first][cur.second];
        }

        reverse(path.begin(), path.end());
        cout<<path.size()<<endl;
        cout << path << "\n";
    }
}
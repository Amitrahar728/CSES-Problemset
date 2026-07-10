#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));

    queue<pair<int,int>> q;

    vector<vector<int>> monsterTime(n, vector<int>(m, 1e9));
    vector<vector<int>> playerTime(n, vector<int>(m, -1));

    pair<int,int> start;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];

            if(grid[i][j] == 'M'){
                q.push({i,j});
                monsterTime[i][j] = 0;
            }

            if(grid[i][j] == 'A'){
                start = {i,j};
            }
        }
    }

    vector<int> dx = {-1,1,0,0};
    vector<int> dy = {0,0,-1,1};

    // Multi-source BFS for monsters
    while(!q.empty()){
        auto cur = q.front();
        q.pop();

        int x = cur.first;
        int y = cur.second;

        for(int k=0;k<4;k++){
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(nx>=0 && ny>=0 && nx<n && ny<m &&
               grid[nx][ny]!='#' &&
               monsterTime[nx][ny]==1e9){

                monsterTime[nx][ny]=monsterTime[x][y]+1;
                q.push({nx,ny});
            }
        }
    }

    vector<vector<pair<int,int>>> parent(n,
        vector<pair<int,int>>(m,{-1,-1}));

    vector<vector<char>> moveTaken(n,
        vector<char>(m));

    q.push(start);
    playerTime[start.first][start.second]=0;

    if(start.first==0 || start.first==n-1 ||
       start.second==0 || start.second==m-1){

        cout<<"YES\n";
        cout<<0<<"\n\n";
        return 0;
    }

    while(!q.empty()){

        auto cur=q.front();
        q.pop();

        int x=cur.first;
        int y=cur.second;

        for(int k=0;k<4;k++){

            int nx=x+dx[k];
            int ny=y+dy[k];

            if(nx<0 || ny<0 || nx>=n || ny>=m)
                continue;

            if(grid[nx][ny]=='#')
                continue;

            if(playerTime[nx][ny]!=-1)
                continue;

            if(playerTime[x][y]+1>=monsterTime[nx][ny])
                continue;

            playerTime[nx][ny]=playerTime[x][y]+1;
            parent[nx][ny]={x,y};

            if(k==0) moveTaken[nx][ny]='U';
            if(k==1) moveTaken[nx][ny]='D';
            if(k==2) moveTaken[nx][ny]='L';
            if(k==3) moveTaken[nx][ny]='R';

            q.push({nx,ny});

            if(nx==0 || nx==n-1 || ny==0 || ny==m-1){

                string ans;

                int cx=nx;
                int cy=ny;

                while(make_pair(cx,cy)!=start){
                    ans.push_back(moveTaken[cx][cy]);
                    auto p=parent[cx][cy];
                    cx=p.first;
                    cy=p.second;
                }

                reverse(ans.begin(),ans.end());

                cout<<"YES\n";
                cout<<ans.size()<<"\n";
                cout<<ans<<"\n";
                return 0;
            }
        }
    }

    cout<<"NO\n";
}
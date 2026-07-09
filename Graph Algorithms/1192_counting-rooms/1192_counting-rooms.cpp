#include <bits/stdc++.h>
using namespace std;
vector<int> row = {-1 ,1,0,0};
vector<int> col = {0 ,0,-1,1};

void traverse( vector<vector<bool>> &vis , vector<vector<char>> &arr , queue<pair<int,int>> &q){
    int n = arr.size();
    int m = arr[0].size();
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i =0; i<4; i++){
            int newx = x+row[i];
            int newy = y+col[i];
            pair<int,int> p = {newx,newy};
            if(newx>= 0 && newx<n && newy >=0 && newy<m && arr[newx][newy] == '.' && !vis[newx][newy]){
                q.push({newx,newy});
                vis[newx][newy] = true;
            }
        }
    }
}
int main() {
    int n, m ;
    cin>>n>>m;
    // track down all the positions of rooms by . 
    // then apply traversal to traverse all components .

    vector<vector<char>> arr(n, vector<char>(m));
    vector<pair<int,int>> pos;
    for(int i =0;i<n; i++){
        for(int j =0; j<m; j++){
            char x; cin>>x;
            arr[i][j] = x;
            if(x == '.'){
                pos.push_back({i,j});
            }
        }
    }
    int sz = pos.size();
    // cout<<sz<<endl;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    queue<pair<int,int>> q;
    int cnt =0;
    for(int i =0; i<sz; i++){
        if(!vis[pos[i].first][pos[i].second]){
            cnt++;
            q.push(pos[i]);
            vis[pos[i].first][pos[i].second] = true;
            traverse(vis, arr, q);
        }
    }
    cout<<cnt<<endl;
    // return cnt;
}

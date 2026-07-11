#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m,q;
    cin>>n>>m>>q;

    const long long INF=1e18;
    vector<vector<long long>> dist(n+1,vector<long long>(n+1,INF));

    for(int i=1;i<=n;i++) dist[i][i]=0;

    while(m--){
        int a,b;
        long long c;
        cin>>a>>b>>c;
        dist[a][b]=min(dist[a][b],c);
        dist[b][a]=min(dist[b][a],c);
    }

    for(int via=1;via<=n;via++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][via]==INF||dist[via][j]==INF) continue;
                dist[i][j]=min(dist[i][j],dist[i][via]+dist[via][j]);
            }
        }
    }

    while(q--){
        int a,b;
        cin>>a>>b;
        if(dist[a][b]==INF) cout<<-1<<endl;
        else cout<<dist[a][b]<<endl;
    }

    return 0;
}
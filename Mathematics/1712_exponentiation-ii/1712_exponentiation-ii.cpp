#include <bits/stdc++.h>
using namespace std;

long long convert(long long x , long long y , long long mod){
    long long ans = 1;
    while(y){
        if(y&1 ) ans*=x;
        ans%=mod;
        x*=x;
        x%=mod;
        y>>=1;
    }
    return ans%mod;
}


int main() {
    long long n ; cin>>n;
    while(n--){
        long long  x, y, z;
        cin>>x>>y>>z;

        y  = convert(y,z , 1e9+6);
        cout<<convert(x, y, 1e9+7)<<endl;
    }

    return 0;
}

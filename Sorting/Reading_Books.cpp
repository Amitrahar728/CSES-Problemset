#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<long long> arr;
    long long sum = 0;
    long long maxi = -1e18;

    for(int i =0 ;i<n; i++){
        long long x; cin>>x;
        sum+=x;
        maxi = max(maxi , x);
        arr.push_back(x);
    }
    long long total = max(2*maxi , sum);
    cout<<total<<endl;
}
#include <bits/stdc++.h>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;

ll MOD = 998244353;
double eps = 1e-12;

#define ll long long
#define for1(i,e) for(ll i = 0; i < e; i++)
#define for2(i,s,e) for(ll i = s; i < e; i++)
#define rfor1(i,s) for(ll i = s; i >= 0; i--)
#define rfor2(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define print(x) cout<<x<<endl;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define vec(arr)
bool custom(pair<ll,ll> a , pair<ll,ll> b){
    return a.second<b.second;
}
int main(){
    ll n; 
    cin>>n;
    vector<pair<ll,ll>> arr;
    while(n--){
        ll a,b;
        cin>>a>>b;
        arr.push_back({a,b});
    }
    sort(all(arr), custom);
    // for(int i =0; i<arr.size(); i++){
    //     cout<<arr[i].first<<" "<<arr[i].second<<endl;
    // }

    ll i =0;
    ll maxi= 1;
    ll cnt = 1;
    if(n == 0){
        maxi =0;
    }
    long long time = arr[0].second;
    for(int i =1; i<arr.size(); i++){
            if(arr[i].first>=time){
                maxi++;
                time = arr[i].second;
            }
    }
        
    cout<<maxi<<endl;
}
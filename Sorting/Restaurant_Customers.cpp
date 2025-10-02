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

int main(){
    // ll n ; cin>>n;
    // vector<pair<ll,ll>> alls;
    // bool check = true;
    // if(n == 0){
    //     cout<<0<<endl;
    //     check = false;
    // }

    // while(n-- && check ){
    //     ll x, y;
    //     cin>>x>>y;
    //     alls.push_back({x,y});
    // }
    // sort(all(alls));
    // // for(int k =0; k<alls.size(); k++){
    // //     cout<<alls[k].first<<" "<<alls[k].second<<endl;
    // // }
    // ll i =0; ll j ;
    // ll maxi = 1;
    // while(i<alls.size()-1){
    //     j =i+1;
    //     while(alls[i].first< alls[j].first && alls[j].first<alls[i].second && j<alls.size()){
    //         ll len = j-i+1;
    //         maxi = max(maxi , len);
    //         // cout<<maxi<<endl;
    //         j++;
    //     }
    //     if(j == alls.size()){
    //         break;
    //     }
    //     // cout<<"next"<<endl;
    //     i++;
    // }
    // cout<<maxi<<endl;
    // return 0;
    // Sweep line algorithm 
    ll n;
    cin>>n;

    vector<pair<ll, int>> events;

    for (ll i = 0; i < n; ++i) {
        ll a, b;
        if (!(cin >> a >> b)) break;
        
        events.push_back({a, 1});
        events.push_back({b, -1});
    }

    sort(events.begin(), events.end(), [](const pair<ll, int>& A, const pair<ll, int>& B) {
        if (A.first != B.first) {
            return A.first < B.first;
        }
        return A.second > B.second; 
    });

    int maxi = 0;
    int current_customers = 0;

    for (const auto& event : events) {
        current_customers += event.second;
        maxi = max(maxi, current_customers);
    }

    cout << maxi << endl;
}
// 2 43
// 12 21
// 33 89
// 34 64
// 39 86
// 42 99
// 45 84
// 47 97
// 50 80
// 72 82
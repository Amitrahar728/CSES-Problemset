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
    ll n , m , k;
    cin>>n>>m>>k;
    vector<ll> arr;
    for1(i,n){
        ll x; cin>>x;
        arr.pb(x);
    }
    vector<ll> arr2;
    for1(i , m){
        ll x;
        cin>>x;
        arr2.pb(x);
    }
    sort(all(arr));
    sort(all(arr2));
    ll i =0;
    ll j =0;
    ll cnt =0;
    
    while(i<n && j<m){
        if(arr[i]-k <= arr2[j] && arr[i]+k>=arr2[j]){
            cnt++;
            // cout<<"move in both arr"<<endl;
            i++;
            j++;
        }
        else {
            if(arr[i]>arr2[j]){
                // cout<<"move in arr"<<endl;
                j++;
            }
            else{
                // cout<<"move in arr2"<<endl;
                i++;
            }
        }

    }
    cout<<cnt<<endl;
    // return 0
}
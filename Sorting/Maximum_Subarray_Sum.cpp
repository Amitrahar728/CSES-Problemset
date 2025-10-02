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
    ll n ; cin>>n;
    vector<ll> arr;
    for(ll i =0; i<n; i++){
        ll x; cin>>x;
        arr.push_back(x);
    }
    ll res = arr[0];           
    
    
    ll maxEnding = arr[0];     

    for (ll i = 1; i < arr.size(); i++){

        maxEnding = max(arr[i], maxEnding + arr[i]); // if sum negative hojaye tohh yaha se again start krdo 

        res = max(res,maxEnding);

    }
    cout<<res<<endl;
}


//The idea of Kadane's algorithm is to traverse over the array from left to right and for each element, 
//find the maximum sum among all subarrays ending at that element. The res will be the maximum of all these values.


// Choice 1: Extend the maximum sum subarray ending at the previous element by adding the current element to it.
//  If the maximum subarray sum ending at the previous index is positive, then it is always better to extend the subarray.

// Choice 2: Start a new subarray starting from the current element. If the maximum subarray sum ending at the previous index is negative, 
// it is always better to start a new subarray from the current element.
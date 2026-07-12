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
    int n ;
    cin>>n;
    vector<pair<pair<int,int>,int>> arr;
    int i =0;
    while(n--){
        int a , b;
        cin>>a>>b;
        arr.push_back({{a,b},i});
        i++;
    }
    // sort(arr.begin(), arr.end()/;
    vector<int> ans;
    int rooms = 1;
    ans.push_back(rooms);
    int mini = arr[0].first.second;
    for(int i =1; i<n; i++){
        if(arr[i].first.first <= arr[i-1].first.second){
            rooms++;
            mini = max(mini,)
            ans.push_back(rooms);

        }
        else if()
    }
    
}
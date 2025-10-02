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
    ll n, m;
    cin>>n>>m;

    vector<int> values(n + 1);
    vector<int> position(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> values[i];
        position[values[i]] = i;
    }

    int count = 1;
    for (int i = 1; i < n; i++) {
        count += (position[i] > position[i + 1]);
    }

    set<pair<int, int> > updatedPairs;

    for (ll i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;

        if (l == r) {
            cout << count << "\n";
            continue;
        }
        
        updatedPairs.clear();

        if (values[l] + 1 <= n)
            updatedPairs.insert(
                { values[l], values[l] + 1 });
        if (values[l] - 1 >= 1)
            updatedPairs.insert(
                { values[l] - 1, values[l] });
        if (values[r] + 1 <= n)
            updatedPairs.insert(
                { values[r], values[r] + 1 });
        if (values[r] - 1 >= 1)
            updatedPairs.insert(
                { values[r] - 1, values[r] });

        for (auto swapped : updatedPairs)
            count -= position[swapped.first]
                     > position[swapped.second];

        swap(values[l], values[r]);

        position[values[l]] = l;
        position[values[r]] = r;

        for (auto swapped : updatedPairs)
            count += position[swapped.first]
                     > position[swapped.second];

        cout << count << "\n";
    }
    return 0;
}
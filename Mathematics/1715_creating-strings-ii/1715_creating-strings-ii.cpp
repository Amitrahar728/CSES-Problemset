#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s ; cin>>s;

    map<char , int> mpp;
    for(char c: s){
        mpp[c]++;
    }
    
    return 0;
}

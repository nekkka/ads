#include <bits/stdc++.h>
using namespace std;

long long mod=1e15+7;

int main(){
    string s;
    cin >> s;

    unordered_map<long long, bool> was;
    vector<long long> subs;
    for(int i = 0; i < s.size(); i++){
        long long h = 0;
        long long p = 1;
        for(int j = i; j < s.size(); j++){
            h = (h + (s[j]) * p) % mod;
            if(was.find(h) == was.end()){
                subs.push_back(h);
                was[h] = true;
            }
            p = (p * 31);
        }
    }

    cout << subs.size();
}
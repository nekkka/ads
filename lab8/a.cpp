#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
long long MOD = 1e9 + 7;
long long X = 11;

long long Hashcode(string s) {
    long long hash = 0;
    long long curX = 1;
    for (int i = 0; i < s.size(); i++) {
        long long curHash = (s[i] - 47 ) * curX % MOD;
        hash = (hash + curHash) % MOD;
        curX = (curX * X) % MOD;
    }
    return hash;
}


int main(){
    int n;
    cin>>n;
    vector<string> v;
    unordered_map<string, long long> m;
    for(int i = 0; i < n*2; i++){
        string s;
        cin >> s;
        v.push_back(s);
        m[s] = Hashcode(s);
    }
    for(int i = 0; i<v.size();i++){
        if(m.find(v[i]) != m.end()){
            cout<<"Hash of string \""<<v[i]<<"\" is "<<m[v[i]]<<endl;
        }
       }
}
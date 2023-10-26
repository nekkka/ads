#include <iostream>
#include <vector>
using namespace std;

long long M = 1e15 + 7;
long long X = 31;
vector<long long> hashes;

long long hashString(string &s, int &l, int &r) {
    long long hash = 0;
    long long cur = 1;
    for (int i = l; i < r + 1; i++) {
        long long curHash = ((s[i] - 96) * cur) % M;
        hash = (hash + curHash) % M;
        cur = (cur * X) % M;
    }
    return hash;
}

void getPrefix(string &s) {
    long long curX = 1;
    for (int i = 0; i < s.size(); i++) {
        hashes[i] = (s[i] - 'a' + 1) * curX % M;
        if (i != 0) {
            hashes[i] = (hashes[i] + hashes[i - 1]) % M;
        }
        curX = (curX * X) % M;
    }
}

int rabinKarp(string &s, int &l, int &r) {
    long long small = hashString(s, l, r);
    int res = 0;
    for (int i = 0; i < s.size() - r + l; i++) {
        long long dif = hashes[i + r - l];
        if (i != 0) {
            dif -= hashes[i - 1];
            if (dif < 0) dif += M;
            small = (small * X) % M;
        }
        if (small == dif) {
            res++;
        }
    }
    return res;
}


int main() {

    string s;
    cin >> s;
    hashes.resize(s.size());
    getPrefix(s);
    int n;
    cin >> n;
    while(n--){
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        cout << rabinKarp(s, l, r) << "\n";
    }
}
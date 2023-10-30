#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

long long MOD = 1e9 + 15;  
long long X = 31;

long long otvet(string str) {
    unordered_map<long long, bool> hashes;
    for (long long i = 0; i < str.size(); i++) {
        long long d = 0;
        for (long long j = i; j < str.size(); j++) {
            d = (X * d + str[j]) % MOD;

            if (hashes.find(d) == hashes.end()) {
                hashes[d] = true;
            }
        }
    }
    return hashes.size();
}

int main() {
    string s;
    cin >> s;
    cout << otvet(s) << endl;
}

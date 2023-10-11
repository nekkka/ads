#include <bits/stdc++.h>
using namespace std;

bool check(vector<long long> arr, long long mid, int k){
    long long cnt = 0;
    for (auto i : arr){
        if(i%mid==0){
            cnt+=(i/mid);
        }else{
        cnt+=(i/mid)+1;
        }
    }
    return cnt <= k;
}


int main(){
    long long n, k;
    cin >> n >> k;
    vector<long long> a;
    long long l = 0;
    long long r = 0;
    for (long long i = 0; i < n; i++){
            int val; cin>>val;
        a.push_back(val);
        if(r<val) r=val;
    }
    while(l+1<r){
        long long m = l + (r - l)/2;
        if (check(a, m, k)){

            r = m;
        }
        else l = m;
    }
    cout << r;
    return 0;
}

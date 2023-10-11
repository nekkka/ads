#include <iostream>
using namespace std;

bool check(long long arr[], int n, long long mid, long long k){
    for(int i=-1;i<n-mid;i++){
            long long sum=0;
            if(i==-1){
                sum=arr[i+mid];
            }else{ sum=arr[i+mid]-arr[i];}

            if(sum>=k) return true;
    }
    return false;
}


int main(){
    long long n, k;
    cin >> n >> k;
    long long a[n];
    long long ap[n];
    long long l = 1;
    long long r = n;
    for (long long i = 0; i < n; i++){
        cin >> a[i];
        if(i==0){
            ap[i]=a[i];
        }else{
        ap[i]=ap[i-1]+a[i];
        }
    }

    long long ans;

   while(l<=r){
        long long m = l + (r - l)/2;
        if (check(ap,n, m, k)){
                ans=m;
            r = m-1;
        }
        else l = m+1;
    }
    cout<<ans;
    return 0;
}

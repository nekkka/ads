#include <iostream>
using namespace std;

bool check(int arr[], int n, long long mid, int k){
    long long cnt = 0;
    long long sum = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] > mid) return false;
        else if (sum + arr[i] > mid){
            sum = arr[i];
            cnt++;
        }
        else sum += arr[i];
    }
    cnt++;
    return cnt <= k;
}


int main(){
    int n, k;
    cin >> n >> k;
    int a[n];
    long long l = 0;
    long long r = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        r += a[i];
    }
    long long ans = 0;
    while(l <= r){
        long long mid = l + (r - l)/2;
        if (check(a, n, mid, k)){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans;
    return 0;
}

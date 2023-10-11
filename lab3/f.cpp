#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int BinarySearch(int a[], int power,int n) {
    int l = 0;
    int r =  n - 1;
    while (l <= r) {
        int mid = l + (r - l)/ 2;
        if (power >= a[mid]) {
            l = mid + 1;
        }
        else if (power <= a[mid]) {
            r = mid - 1;
        }
        else if (power == a[mid]) {
            return mid;
        }
    }
    return l;
}


int main () {
    int n; cin >> n;
    int a[n];
    int aprefix[n];
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a[i]=x;
    }
    sort(a, a + n);
    aprefix[0]=a[0];
    for(int i=1;i<n;i++){
        aprefix[i]=a[i]+aprefix[i-1];
    }

    int round; cin >> round;

    for (int i = 0; i < round; i++) {
        int x; cin >> x;
        int ans = BinarySearch(a, x,n);

        cout << ans << " " << aprefix[ans-1] << endl;
    }
}

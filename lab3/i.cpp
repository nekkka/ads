#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int x;
    cin >> x;
    int l = 0;
    int r = n - 1;
    bool ans = false; 

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (x > a[mid]) {
            l = mid + 1;
        } else if (x < a[mid]) { 
            r = mid - 1;
        } else {
            ans = true;
            break; 
        }
    }

    if (ans) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}

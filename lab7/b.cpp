#include <iostream>

using namespace std;

void merge(int * a, int l1, int r1, int l2, int r2){
    int n1 = r1 - l1 + 1;
    int L[n1];
    for(int i = 0; i < n1; ++i){
        L[i] = a[l1 + i];
    }

    int n2 = r2 - l2 + 1;
    int R[n2];
    for(int i = 0; i < n2; ++i){
        R[i] = a[l2 + i];
    }

    int i = l1;
    int i1 = 0;
    int i2 = 0;

    while(i1 < n1 && i2 < n2){
        if(L[i1] < R[i2]){
            a[i++] = L[i1++];
        }else {
            a[i++] = R[i2++];
        }
    }

    //copy rest of L
    while(i1 < n1){
        a[i++] = L[i1++];
    }

    //copy rest of R
    while(i2 < n2){
        a[i++] = R[i2++];
    }

}

void msort(int * a, int l, int r){
    if(l < r){
        int m = l + (r - l) / 2;
        msort(a, l, m);
        msort(a, m + 1, r);
        merge(a, l, m , m + 1, r);
    }
}

int main(){
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int m; cin >> m;

    int b[m];

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    int merged[n+m];
    int i = 0;
    int i1 = 0;
    int i2 = 0;

    while(i1 < n && i2 < m){
        if(a[i1] < b[i2]){
            merged[i++] = a[i1++];
        }else {
            merged[i++] = b[i2++];
        }
    }

    while(i1 < n){
        merged[i++] = a[i1++];
    }

    while(i2 < m){
        merged[i++] = b[i2++];
    }
    for(int i=0;i<n+m;i++){
        cout<<merged[i]<<" ";
    }


    return 0;
}

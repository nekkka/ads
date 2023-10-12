#include <iostream>
#include <algorithm>
using namespace std;

void heapify_up(int *a, int &n, int v){
    if(v!=1 && a[v]>a[v/2]){
        swap(a[v], a[v/2]);
        heapify_up(a,n,v/2);
    }
    /*while (v!=1 && a[v]>a[v/2]){
        swap(a[v], a[v/2]);
        v = v/2;
    }*/
}

void push(int *a, int &n, int key){
    n++;
    a[n]=key;
    heapify_up(a,n,n);
}

void print(int *a, int n, int v, int tab =0){
    for (int i=0; i<tab; i++){
        printf("\t");   
    }
    printf("%d\n", a[v]);
    if (2*v<=n)print(a,n,2*v,tab+1);
    if (2*v+1<=n) print(a,n,2*v+1,tab+1);
}

int top(int *a, int &n){
    return a[1];
}


void heapify_down(int *a, int &n, int v){
    int mx = v;
    if( 2*v <=n && a[mx] < a[2*v]){
        mx = 2 * v;         
    }

    if (2*v+1 <=n && a [mx] < a[2*v+1]){
        mx = 2*v+1;
    }
    if (mx = v) return;
    swap(mx, a[v]);
    heapify_down(a, n, mx);
}

void pop(int *a, int &n){
    swap(a[1], a[n]);
    n--;
    heapify_down(a,n, 1);
}

int main(){
    int n=0;
    int a[n];

}
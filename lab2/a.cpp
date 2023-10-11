#include <iostream>
#include <cassert>
#include <cmath>
#include <climits>
using namespace std;


struct node {
  int data;
  node *nxt = 0;

  node() {
    data = 0;
  }
  node(int _data) {
    data = _data;
  }

  node(int _data, node *_nxt) {
    data = _data;
    nxt = _nxt;
  }

};

int main(){
    int n;
    cin >> n;
    int beg;
    cin >> beg;
    node* head = new node(beg);
    node* cur = head; 
    for ( int i  = 0 ; i < n - 1 ; i++ ){
        int x; 
        cin>>x;   
        node* newNode = new node(x);
        cur->nxt = newNode;
        cur = cur->nxt ;    
    }

   int k;
   cin >> k;
   int minDiff = INT_MAX , pos = 0; 
    for (int i  = 0 ; i < n ; i++){
        if ( abs(k - head->data) < minDiff ){
            minDiff = abs(k - head->data) ;
            pos = i;
        }
        head = head->nxt ; 
    }
    cout<<pos;

}
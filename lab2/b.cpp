#include <iostream>
#include <cassert>
#include <cmath>
#include <climits>


using namespace std;


struct node {
  string data;
  node *nxt = 0;

    node() : data(" "), nxt(nullptr) {}
    node(string x) : data(x), nxt(nullptr) {}
    node(string x, node *next) : data(x), nxt(next) {}
};


int main(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    node* head = new node(s);
    node* cur = head; 

    for ( int i  = 0 ; i < n - 1 ; i++ ){
        string x; 
        cin>>x;   
        node* newNode = new node(x);
        cur->nxt = newNode;
        cur = cur->nxt;    
    }
    
    cur->nxt = head;
    node* spl = head;
    
    for(int i = 0; i < k-1; i++){
        spl = spl->nxt;
    }
    node* current = spl->nxt;
    spl->nxt = nullptr;
    
    while(current){
        cout << current->data << " ";
        current = current->nxt;
    }
    
}

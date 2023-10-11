#include <iostream>
#include <cassert>
#include <cmath>
#include <climits>
using namespace std;

struct Node{
    string val;
    Node *next;
    Node (string newVal){
        this->val = newVal;
        this->next = NULL;
    }

};
int main(){
    Node *cur;
    Node *head;
    Node *a;
    int n,k;
    cin>>n>>k;
    for(int i=0; i<n; i++){
        string val; cin>>val;
        if (i==0){
            head = new Node(val);
            cur = head;
        }
        else {
            a = new Node (val);
            cur->next = a;
            cur=cur-> next;
        }
    }
 








return 0;
}
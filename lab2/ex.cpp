
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
    int n;
    cin>>n;
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



    int x;
    cin>>x;
    int size = 0;
    Node* end = head;
    cur = head;
    Node* prev = NULL;
    while(end) {
        if(end->next == NULL) break;
        end = end->next;
        size++;
    }

    for(int i = 0; i < size + 1 - x; i++) {
        prev = cur;
        cur = cur->next;
    }
    
    end->next = head;
    prev->next = NULL;
    while(head){
        cout<<head->val;
        head = head->next;
    }
    head = cur;
    

return 0;
}
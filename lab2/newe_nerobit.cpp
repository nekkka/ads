#include <iostream>
#include <algorithm>
#include <vector>
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
    vector<string> uniqueElements;
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
            uniqueElements.push_back(cur->val);
        }
        else {
            a = new Node (val);
            cur->next = a;
            cur=cur-> next;
        }
    }
    cur = head;

    while (cur != 0) {
            
        auto it = find(uniqueElements.begin(), uniqueElements.end(), cur->val);
        
        if (it == uniqueElements.end()) {
            uniqueElements.push_back(cur->val);
        }
        cur = cur->next;
    }
    cout << "All in all: " << uniqueElements.size() << endl;
    cout << "Students: " << endl;
    reverse(uniqueElements.begin(), uniqueElements.end());
    for (const string& student : uniqueElements) {
        cout << student << endl;
    }     

    return 0;

}
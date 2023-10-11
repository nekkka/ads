#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct node {
    string data;
    node* nxt = NULL;
    node() {
        data = "";
    }
    node(string _data) {
        this->data = _data;
    }
    node(string _data, node* _nxt) {
        data = _data;
        nxt = _nxt;
    }
};

int main() {
    vector<string> uniqueElements;
    int n;
    cin >> n;
    string beg;
    cin >> beg;
    node* head = new node(beg);
    node* cur = head;
    uniqueElements.push_back(beg);

    for (int i = 0; i < n - 1; i++) {
        string x;
        cin >> x;
        node* newNode = new node(x);
        cur->nxt = newNode;
        cur = cur->nxt;
    }
    
    cur = head;

    while (cur != nullptr) {
           
        if (uniqueElements.back()!=cur->data) {
            uniqueElements.push_back(cur->data);
        }
        cur = cur->nxt;
    }   

    cout << "All in all: " << uniqueElements.size() << endl;
    cout << "Students: " << endl;
    reverse(uniqueElements.begin(), uniqueElements.end());
    for (const string& student : uniqueElements) {
        cout << student << endl;
    }     

    return 0;
}

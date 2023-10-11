#include <iostream>
using namespace std;

struct node {
    int data;
    node* nxt = NULL;
    node() {
        data = 0;
    }
    node(int _data) {
        data = _data;
    }
    node(int _data, node* _nxt) {
        data = _data;
        nxt = _nxt;
    }
};

int main() {
    int n;
    cin >> n;
    int beg;
    cin >> beg;
    node* head = new node(beg);
    node* cur = head;
    for (int i = 0; i < n - 1; i++) {
        int x;
        cin >> x;
        node* newNode = new node(x);
        cur->nxt = newNode;
        cur = cur->nxt;
    }

    node* current = head;
    int position = 1;
    while (current != NULL) {
        if (position % 2 == 1) {
            cout << current->data << " ";
        }
        current = current->nxt;
        position++;
    }

    return 0;
}

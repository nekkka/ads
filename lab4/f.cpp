#include <iostream>

using namespace std;

struct Node{
    int key;
    Node *left;
    Node *right;
    Node(int val) {
        this->key = val;
        this->left = NULL;
        this->right = NULL;
    }
};


void insert(Node* &root, int key) {
    if (root == NULL)
    {
        root = new Node(key);
        return;
    }
    else if (root -> key > key)
    {
        insert(root -> left, key);
    }
    else
    {
        insert(root -> right, key);
    }
}
int cnt=0;
void count(Node *root) {
    if(root==NULL) return;
    else{
        if(root->left !=NULL && root->right !=NULL) cnt++;
        count(root->left);
        count(root->right);

    }
}

int main() {
    int n; cin >> n;

    Node *root = NULL;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        insert(root, x);
    }

    count(root);
    cout<<cnt;

}

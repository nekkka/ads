#include <iostream>

using namespace std;
struct Node {
    int key;
    Node* left;
    Node* right;
    Node () {
        left = NULL;
        right = NULL;
    }
    Node (int key) {
        this->key = key;
        left = NULL;
        right = NULL;
    }
};

void insert(Node* &root, int key) {
    if (root == NULL)
    {
        root = new Node(key);
        return;
    }

    if (root -> key > key)
    {
        insert(root -> left, key);
    }

    else
    {
        insert(root -> right, key);
    }
}

void print(Node* root){
    if(root == NULL) return;
    else{
      cout<<root->key<<" ";
      print(root->left);
      print(root->right);
    }

}

void search (Node* root, int key) {
    if (root -> key == key) {
        print(root);
    }
    else if (root -> key > key) {
        search(root -> left, key);
    }
    else {
        search(root -> right, key);
    }
}


int main () {
    Node *root = new Node();
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        insert(root, x);
    }
int key;
cin>>key;
    search(root,key);
}

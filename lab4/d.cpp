#include <iostream>
#include <map>
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

map<int,int>k; //[лвл, сумма]
int mx=0; //макс лвл

void search (Node* root, int key) {
    if (root==NULL)return;
    else{
        mx=max(key,mx);
        k[key]+=root->key;
    search(root -> left, key+1);
    search(root -> right, key+1);
    }
}


int main () {
    Node *root = NULL;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        insert(root, x);
    }
    search(root,1);
    cout<<mx<<endl;
    for(int i=1;i<=mx;i++){
        cout<<k[i]<<" ";
    }
}

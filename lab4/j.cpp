#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void print(Node* root){
    if(root == NULL) return;
    else{
      cout<<root->data<<" ";
      print(root->left);
      print(root->right);
    }

};

void insert(Node* &root, int key) {
    if (root == NULL) {
        root = new Node(key);
        return;
    }
    else if (root->data > key) {
        insert(root->left, key);
    }
    else {
        insert(root->right, key);
    }
}



Node* constructBalancedBST(vector<int>& vec, int start, int end) {
    if (start > end) return NULL;

    int mid = start + (end - start) / 2;
    Node* root = new Node(vec[mid]);

    root->left = constructBalancedBST(vec, start, mid-1);
    root->right = constructBalancedBST(vec, mid+1, end);

    return root;
}
void inOrder(Node* root, vector<int>& vec){
        if (root == NULL) return;
        inOrder(root -> left,vec);
        vec.push_back(root -> data);
        inOrder(root -> right,vec);
    }

int main() {
    Node *root = NULL;
    int n;
    cin >> n;
    vector<int> vec;

    for (int i = 0; i < pow(n,2)-1; i++) {
        int x;
        cin >> x;
        insert(root, x);
    }

    inOrder(root,vec);
    Node* newroot = constructBalancedBST(vec, 0, vec.size() - 1);
    print(newroot);
    
return 0;
}

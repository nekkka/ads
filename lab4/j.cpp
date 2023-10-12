#include <iostream>
#include <vector>
#include <algorithm>
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

int leftHeight(Node *root) {
    if (root == NULL) return 0;
    return 1 + leftHeight(root->left);
}

int rightHeight(Node *root) {
    if (root == NULL) return 0;
    return 1 + rightHeight(root->right);
}

Node* constructBalancedBST(vector<int>& vec, int start, int end) {
    if (start > end) return NULL;

    int mid = (start + end) / 2;
    Node* root = new Node(vec[mid]);

    root->left = constructBalancedBST(vec, start, mid - 1);
    root->right = constructBalancedBST(vec, mid + 1, end);

    return root;
}

int main() {
    Node *root = NULL;
    int n;
    cin >> n;
    vector<int> vec;

    for (int i = 0; i < pow(n,2)-1; i++) {
        int x;
        cin >> x; vec.push_back(x);
        insert(root, x);
    }
    int left_height = leftHeight(root);
    int right_height = rightHeight(root);
    if (abs(left_height-right_height)<=1){
        for (auto i : vec) {
        cout << i << " ";
    }
    }
    else{
        sort(vec.begin(), vec.end());
        Node* newroot = constructBalancedBST(vec, 0, vec.size() - 1);
        print(newroot);
    }

return 0;
}

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

void insert(Node* &root, int key, int z) {
    if (z==0){
        root->left=new Node(key);
    }
    else {
         root->right = new Node(key);
    }
    
}

map<int,int>k;
int mx=0;
void count(Node* root,int level){
    if(root == NULL) return;
    else{
        k[level]++;
        mx=max(mx,k[level]);
      count(root->left,level+1);
      count(root->right,level+1);

    }

}


void search (Node* root, int key,int key2,int dir) {
    if (root==NULL)return;
    else{
    if(root->key==key){
        insert(root,key2,dir);
    }
    search(root -> left,key,key2,dir);
    search(root -> right,key,key2,dir);
    }
}


int main () {
    Node *root = NULL;
    int n; cin >> n;
    for (int i = 0; i < n-1; i++) {
    int x,y,z;
    cin>>x>>y>>z;
    if(root==NULL){
        root=new Node(x);
    }
    search(root,x,y,z);
    
    }
    count(root,1);
    cout<<mx;
}

#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node *left, *right;
    Node(int value)
    {
        this -> val = value;
        this -> left = NULL;
        this -> right = NULL;
    }
};


    void push(Node *&root, int val)
    {
        if (root == NULL)
            root = new Node(val);
        if (val < root->val)
            push(root->left, val);
        if (val > root->val)
            push(root->right, val);
    }


void sum_node(Node* root, int& acc_sum){
    if (root == NULL)  return;

    sum_node(root->right,acc_sum);
    root->val += acc_sum;
    acc_sum = root->val;

    cout << acc_sum << " ";

    sum_node(root->left, acc_sum);
}
int main()
{
    Node *root=NULL;
    int n, x;
    cin >> n;
    int accsum=0;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        push(root, x);
    }

   sum_node(root,accsum);

}

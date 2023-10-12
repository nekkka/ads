#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
    int multiplicity;
    Node (int key) {
        this -> val = key;
        this -> left = NULL;
        this -> right = NULL;
        this -> multiplicity = 1;
    }
};



Node* add(Node* root, int key) {
	if (root == NULL) {
		return new Node(key);

	} else if(root->val == key) {
        root->multiplicity++;
    }

    else if (root->val > key) {
		if (root->left == NULL) {
			root->left = new Node(key);
		} else {
			root->left = add(root->left, key);
		}
	} 
    
    else if (root->val < key) {
		if (root->right == NULL) {
			root->right = new Node(key);
		} else {
			root->right = add(root->right, key);
		}
	}
	return root;
}

Node* getMin(Node* root) {
	while (root->left != NULL) {
		root = root->left;
	}
	return root;
}


Node* find (Node * root, int key) {
	if (root == NULL) {
		return NULL;
	} else if (root->val == key) {
		return root;
	} else if (root->val < key) {
		return find(root->right, key);
	} else {
		return find(root->left, key);
	}
}


Node *remove(Node * root, int key) {
    if (root == NULL) {
        return NULL;
    }

    else if (root ->val > key) {
        root -> left = remove(root -> left, key);
        return root;
    }

    else if (root -> val < key) {
        root -> right = remove(root -> right, key);
        return root;
    }

    else if (root -> val == key) {
        if (root -> multiplicity == 0)  {
            if (root -> left == NULL && root -> right == NULL) {
                delete root;
                return NULL;
            } else if (root -> right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            } else if (root -> left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else {
                Node* temp = getMin(root->right);
                root->val = temp->val;
                root->right = remove(root->right, temp->val);
                return root;
            }
        }
        else root->multiplicity--;
        return root;
    }
    return NULL;
}


void solution (Node* &root, int val, string s) {
    if (s == "insert") {
        root = add(root, val);
    } else if (s == "delete") {
        root = remove(root, val);
    } else if (s == "cnt") {
        Node *finded = find(root, val);
        if (finded == NULL) cout << 0 << "\n";
        else cout << finded->multiplicity << "\n";
    }

}

int main () {
    int n;
    cin >> n;
    Node *root = NULL;

    for (int i = 0; i < n; i++) {
        string s;
        int key;
        cin >> s >> key;

        solution(root, key, s);
    }
}

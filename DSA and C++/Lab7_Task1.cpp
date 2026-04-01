#include <iostream>
using namespace std;

struct bst {
    int data;
    bst *left = NULL;
    bst *right = NULL;
};
bst *root = NULL;
void insert(int val) {
    bst *curr = new bst;
    curr->data = val;
    if (root == NULL) {
        root = curr;
        return;
    }
    bst *p = root, *q;
    while (p != NULL) {
        q = p;
        if (val > p->data)
            p = p->right;
        else
            p = p->left;
    }
    if (val > q->data)
        q->right = curr;
    else
        q->left = curr;
}
void Preorder_NRL(bst *root) {
    if (root != NULL) {
        cout << root->data << " ";
        Preorder_NRL(root->right);
        Preorder_NRL(root->left);
    }
}
void Inorder_RNL(bst *root) {
    if (root != NULL) {
        Inorder_RNL(root->right);
        cout << root->data << " ";
        Inorder_RNL(root->left);
    }
}
void Postorder_RLN(bst *root) {
    if (root != NULL) {
        Postorder_RLN(root->right);
        Postorder_RLN(root->left);
        cout << root->data << " ";
    }
}
int main() {
    insert(50); insert(30); insert(70);
    insert(20); insert(40); insert(60); insert(80);
    cout << "Preorder(NRL): ";
    Preorder_NRL(root);
    cout << "Inorder(RNL): "<<endl;
    Inorder_RNL(root);
    cout << "Postorder(RLN): "<<endl;
    Postorder_RLN(root);
    return 0;
}
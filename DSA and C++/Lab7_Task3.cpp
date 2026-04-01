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
bst* findMin(bst* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}
bst* deleteNode(bst* root, int key) {
    if (root == NULL)
        return NULL;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        // One child
        else if (root->left == NULL) {
            bst* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            bst* temp = root->left;
            delete root;
            return temp;
        }
        else {
            bst* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}
void Inorder(bst *root) {
    if (root != NULL) {
        Inorder(root->left);
        cout << root->data << " ";
        Inorder(root->right);
    }
}
int main() {
    insert(50); insert(30); insert(70);
    insert(20); insert(40); insert(60); insert(80);
    cout << "Before Deletion (Inorder): ";
    Inorder(root);
    root = deleteNode(root, 50);
    cout << "\nAfter Deletion (Inorder): ";
    Inorder(root);
    return 0;
}
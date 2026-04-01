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
int leafCount = 0;
void printLeafNodes(bst *root) {
    if (root != NULL) {
        if (root->left == NULL && root->right == NULL) {
            cout << root->data << " ";
            leafCount++;
        }
        printLeafNodes(root->left);
        printLeafNodes(root->right);
    }
}
int main() {
    insert(50); insert(30); insert(70);
    insert(20); insert(40); insert(60); insert(80);
    cout << "Leaf Nodes: ";
    printLeafNodes(root);
    cout << "Total Leaf Nodes: " << leafCount <<endl;
    return 0;
}
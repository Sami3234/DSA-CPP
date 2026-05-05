#include <iostream>
#include <queue>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* n = new Node();
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void levelOrder(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if (temp->left != NULL)
            q.push(temp->left);

        if (temp->right != NULL)
            q.push(temp->right);
    }
}

int main() {
    Node* root = newNode(30);
    root->left = newNode(20);
    root->right = newNode(40);
    root->left->left = newNode(10);
    root->left->right = newNode(25);
    root->right->right = newNode(50);
    levelOrder(root);
    return 0;
}
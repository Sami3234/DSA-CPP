#include <iostream>
#include <queue>
using namespace std;

struct node {
    int data;
    node *left = NULL;
    node *right = NULL;
};
node* root = NULL;
node* insert(node* root, int val) {
    if (root == NULL) {
        node* temp = new node;
        temp->data = val;
        return temp;
    }
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}
// TASK 1:
void BFS_iterative(node* root) {
    if (root == NULL) return;
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        node* temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
    }
}
int height(node* root);
void printLevel(node* root, int level) {
    if (root == NULL) return;

    if (level == 1)
        cout << root->data << " ";
    else {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}
void BFS_recursive(node* root) {
    int h = height(root);
    for (int i = 1; i <= h; i++) {
        printLevel(root, i);
    }
}
// TASK 2:
int height(node* root) {
    if (root == NULL)
        return 0;
    int leftH = height(root->left);
    int rightH = height(root->right);
    return max(leftH, rightH) + 1;
}
// TASK 3:
int countNodes(node* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
//TASK 4:
int sumNodes(node* root) {
    if (root == NULL)
        return 0;
    return root->data + sumNodes(root->left) + sumNodes(root->right);
}
// TASK 5:
int findMax(node* root) {
    if (root == NULL)
        return -1;
    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);
    return max(root->data, max(leftMax, rightMax));
}
// TASK 6:
int findMin(node* root) {
    if (root == NULL)
        return 999999;
    int leftMin = findMin(root->left);
    int rightMin = findMin(root->right);
    return min(root->data, min(leftMin, rightMin));
}
int main() {

    root = insert(root, 50);
    root = insert(root, 20);
    root = insert(root, 70);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 60);
    root = insert(root, 80);
    cout << "BFS (Iterative): ";
    BFS_iterative(root);
    cout << "\nBFS (Recursive): ";
    BFS_recursive(root);
    cout << "\nHeight of Tree: " << height(root);
    cout << "\nTotal Nodes: " << countNodes(root);
    cout << "\nSum of Nodes: " << sumNodes(root);
    cout << "\nMaximum Value: " << findMax(root);
    cout << "\nMinimum Value: " << findMin(root);
    return 0;
}
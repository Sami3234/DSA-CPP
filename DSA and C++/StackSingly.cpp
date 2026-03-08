#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};
class StackList {
private:
    Node* topNode;
public:
    StackList() {
        topNode = nullptr;
    }
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
    }
    void pop() {
        if (topNode == nullptr) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }
    void display() const {
        if (topNode == nullptr) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = topNode;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    ~StackList() {
        while (topNode != nullptr) {
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }
};

int main() {
    StackList stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "Stack using singly linked list:" << endl;
    stack.display();

    stack.pop();
    cout << "After pop:" << endl;
    stack.display();

    return 0;
}

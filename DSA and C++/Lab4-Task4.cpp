#include <iostream>
#include <vector>
using namespace std;

class StackUsingVector {
private:
    vector<int> arr;

public:
    void push(int value) {
        arr.push_back(value);
    }

    void pop() {
        if (arr.empty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        arr.pop_back();
    }

    void display() const {
        if (arr.empty()) {
            cout << "Stack is empty" << endl;
            return;
        }

        for (int i = static_cast<int>(arr.size()) - 1; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class StackUsingLinkedList {
private:
    Node* topNode;

public:
    StackUsingLinkedList() {
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

    ~StackUsingLinkedList() {
        while (topNode != nullptr) {
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }
};

int main() {
    cout << "Stack using vector:" << endl;
    StackUsingVector stack1;
    stack1.push(10);
    stack1.push(20);
    stack1.push(30);
    stack1.display();
    stack1.pop();
    stack1.display();

    cout << "\nStack using singly linked list:" << endl;
    StackUsingLinkedList stack2;
    stack2.push(100);
    stack2.push(200);
    stack2.push(300);
    stack2.display();
    stack2.pop();
    stack2.display();

    return 0;
}

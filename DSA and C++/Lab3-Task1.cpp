#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node * next;
    Node * prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};
class DoublyList {
public:
    Node* head;
    DoublyList() {
        head = nullptr;
    }
    void push_end(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << "<=>";
            temp = temp->next;
        }
        cout <<"nullptr"<< endl;
    }
    void reverse() {
        Node* temp = head;
        Node* prevNode = nullptr;

        while (temp != nullptr) {
            prevNode = temp->prev;
            temp->prev = temp->next;
            temp->next = prevNode;
            temp = temp->prev;
        }
        if (prevNode != nullptr) {
            head = prevNode->prev;
        }
    }
};
int main() {
    DoublyList list;
    list.push_end(1);
    list.push_end(2);
    list.push_end(3);
    list.push_end(4);
    list.print();
    list.reverse();
    list.print();
    return 0;
}

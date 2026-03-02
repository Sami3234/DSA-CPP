#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int v) {
        data = v;
        next = nullptr;
    }
};

class CircularList {
public:
    Node* head;

    CircularList() {
        head = nullptr;
    }

    void insert_at_specific(int v, int pos) {
        Node* newNode = new Node(v);
        if (pos <= 1 || head == nullptr) {
            if (head == nullptr) {
                head = newNode;
                head->next = head;
                return;
            }
            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }
            newNode->next = head;
            head = newNode;
            last->next = head;
            return;
        }
        Node* temp = head;
        int i = 1;
        while (i < pos - 1 && temp->next != head) {
            temp = temp->next;
            i++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void delete_front() {
        if (head == nullptr) 
            return;
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        Node* del = head;
        head = head->next;
        last->next = head;
        delete del;
    }

    void delete_end() {
        if (head == nullptr) return;

        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != head) {
            temp = temp->next;
        }
        Node* del = temp->next;
        temp->next = head;
        delete del;
    }

    void delete_specific_pos(int pos) {
        if (head == nullptr || pos <= 0) 
            return;
        if (pos == 1) {
            delete_front();
            return;
        }

        Node* temp = head;
        int i = 1;
        while (i < pos - 1 && temp->next != head) {
            temp = temp->next;
            i++;
        }

        if (temp->next == head) return;
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }

    int search(int val) {
        if (head == nullptr) return -1;

        Node* temp = head;
        int pos = 1;
        do {
            if (temp->data == val) return pos;
            temp = temp->next;
            pos++;
        } while (temp != head);

        return -1;
    }

    void update(int v1, int v2) {
        if (head == nullptr) return;

        Node* temp = head;
        do {
            if (temp->data == v1) {
                temp->data = v2;
                return;
            }
            temp = temp->next;
        } while (temp != head);
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "" << endl;
    }
};

int main() {
    CircularList cl;

    cl.insert_at_specific(10, 1);
    cl.insert_at_specific(20, 2);
    cl.insert_at_specific(30, 3);
    cl.insert_at_specific(15, 2);
    cl.display();
    cl.delete_front();
    cl.display();

    cl.delete_end();
    cl.display();

    cl.delete_specific_pos(2);
    cl.display();

    cout << "Search" << cl.search(20) << endl;
    cl.update(20, 200);
    cl.display();

    return 0;
}

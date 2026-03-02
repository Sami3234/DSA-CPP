#include <iostream>
using namespace std;

class SNode {
public:
    int data;
    SNode* next;
    SNode(int v) {
        data = v;
        next = nullptr;
    }
};

class DNode {
public:
    int data;
    DNode* next;
    DNode* prev;
    DNode(int v) {
        data = v;
        next = nullptr;
        prev = nullptr;
    }
};

class SinglyList {
public:
    SNode* head = nullptr;
    void push_end(int v) {
        SNode* n1 = new SNode(v);
        if (!head)
         {
            head = n1; return;
        }
        SNode* t = head;
        while (t->next) t = t->next;
        t->next = n1;
    }
    void display() {
        for (SNode* t = head; t; t = t->next)
            cout << t->data << " -> ";
        cout << "nullptr" << endl;
    }
};

class DoublyList {
public:
    DNode* head = nullptr;
    void push_end(int v) {
        DNode* n1 = new DNode(v);
        if (!head) 
        { 
            head = n1; return; 
        }
        DNode* t = head;
        while (t->next) t = t->next;
        t->next = n1;
        n1->prev = t;
    }
    void fromSingly(SinglyList& s) {
        for (SNode* t = s.head; t; t = t->next)
            push_end(t->data);
    }
    void display() {
        for (DNode* t = head; t; t = t->next)
            cout << t->data << " <=> ";
        cout << "nullptr" << endl;
    }
};

int main() {
    SinglyList s;
    s.push_end(1);
    s.push_end(2);
    s.push_end(3);
    s.push_end(4);
    s.push_end(5);
    s.display();

    DoublyList d;
    d.fromSingly(s);
    d.display();
}

#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node(int val){
            data = val;
            next = nullptr;
        }
};
class List{
    Node * head;
    Node* tail;
public:
    List(){
        head = tail = nullptr;
    }
    void push_front(int val){
        Node *newNode = new Node(val);
        if(head == nullptr){
            head = tail = newNode;
            return;
        }

    }
    void print(){
        Node * temp =head;
        while (temp != nullptr){
            cout<< temp -> data << "->";
            temp = temp -> next;
        }
        cout << "Null";
    }
};
int main(){
    List ll;
    ll.push_front(1);
    ll.print();
    return 0;

};
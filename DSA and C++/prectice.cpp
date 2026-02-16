#include <iostream>
using namespace std;
 
class node{
    public:
    int data;
    node* next;

    node(int value){
        data = value;
        next = nullptr;
    }
};
class pointer {
    node* head;

    public:
        pointer(){
            head = nullptr;
        }
};

void pushend(){
    node *n1 = new node(5);

    if (head == nullptr){
        head = next = n1;

    }
    else{
        head ->next = n1;
        tail =n1;
    }
}


#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node*next;

    node(int value){
        data= value;
        next= nullptr;

        
    }

};

class linkedList {
    node*head;
    public:

    linkedList(){
        head= nullptr;

    }
    void insertat(int value){
        node* newnode= new node (value);
        newnode->next = head;
        head = newnode;
    }
    void display(){
        node* temp= head;
        while (temp!= nullptr){
            cout<< temp->data<<"--->";
            temp= temp->next;
        }
        cout<<"nullptr"<<endl;
    }
};

int main(){
    linkedList list;

    list.insertat(10);
    list.insertat(20);

    list.display();
    return 0;
}
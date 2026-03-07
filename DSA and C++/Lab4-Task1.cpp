#include <iostream>
using namespace std;
class Node{
    public: 
        int data;
        Node * next;
        Node(int v){
            data = v;
            next = nullptr;
        }
};
class CircularList{
    public:
        Node *head;
        CircularList(){
            head = nullptr;

        }
        void insert(int v){
            Node* newNode = new Node(v);
            if (head == nullptr){
                head = newNode;
                head-> next = head;
            
            }else{
                Node* temp = head;
                while (temp ->next != head){
                    temp = temp->next;
                }
                temp-> next = newNode;
                newNode -> next =head;
            }
        }
        void display(){
            if (head == nullptr){
                cout << "List is empty"<<endl;
                return;
            }
            Node*temp=head;
            do{
                cout << temp -> data <<"";
                temp = temp->next;

            }while(temp != head);
            cout <<endl;
        }
        void delete_even(){
            if(head == nullptr)
            return;
            Node* current = head;
            Node*prev = nullptr;
            Node* last = head;
            while(last->next != head){
                last = last ->next;
            }
            do{
                if (current ->data %2==0){
                    if(current == head){
                        head = current->next;
                        last->next =head;
                        delete current;
                        current = head;
                    }else{
                        prev = current;
                        current = current->next;
                    }

                }
            }while(current != head && head != nullptr);
        }
        void delete_odd(){
            if(head == nullptr)
            return;
            Node* current = head;
            Node* prev = nullptr;
            Node*Last = head;
            while(Last ->next !=head){
                Last = Last ->next;
            }
            do{
                if(current ->data %2 != 0){
                    if(current == head){
                        head = current -> next;
                        Last ->next = head;
                        delete current;
                        current = head;
                    }else{
                        prev -> next = current ->next;
                        delete current;
                        current = prev -> next;
                    }

                }else{
                    prev = current;
                    current = current -> next;
                }

            }while(current != head && head != nullptr);
        }
};
int main(){
    CircularList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    list.insert(6);
    list.display();
    list.delete_odd();
    list.display();
}
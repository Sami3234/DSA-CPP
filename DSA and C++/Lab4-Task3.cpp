#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int v){
            data = v;
            next = nullptr;
        }
};

class LinkedList{
    public:
        Node* head;
        LinkedList(){
            head = nullptr;
        }

        void insert(int v){
            Node* newNode = new Node(v);
            if(head == nullptr){
                head = newNode;
            }else{
                Node* temp = head;
                while(temp->next != nullptr){
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }

        void display(){
            if(head == nullptr){
                cout << "List is empty" << endl;
                return;
            }

            Node* temp = head;
            while(temp != nullptr){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }

        void delete_even_position(){
            if(head == nullptr){
                return;
            }

            Node* current = head;
            Node* prev = nullptr;
            int position = 1;

            while(current != nullptr){
                if(position % 2 == 0){
                    prev->next = current->next;
                    Node* delNode = current;
                    current = current->next;
                    delete delNode;
                }else{
                    prev = current;
                    current = current->next;
                }
                position++;
            }
        }
};

int main(){
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    list.insert(6);
    list.display();

    list.delete_even_position();
    cout << "After deleting even nodes:";
    list.display();

    return 0;
}

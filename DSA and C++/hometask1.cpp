#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;
    Node(int value) {
        data = value;
        next= nullptr;
    }
};
class LinkedList {
    private:
    Node *head;
    public:
    LinkedList() {
        head = nullptr;
    }
    void insertPosition(int value, int position){
        if (position < 1) {
            cout << "Invalid position"<<endl;
            return;
        }
        Node* newNode = new Node(value);
        if (position == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node *temp = head;
        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout<< "Invalid position"<<endl;
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        temp->next= newNode;
    }
    void searchAtPosition(int position){
        if (position < 1) {
            cout << "Invalid position"<<endl;
            return;}
        Node *temp= head;
         for (int i = 1; i < position && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr){
            cout << "Invalid position"<<endl;
        }else{
            cout << "Value at position " << position << " is: " << temp->data << endl;
        } 
    }
    void updatePosition(int value, int position){

        if (position < 1) {
            cout << "Invalid position"<<endl;
            return;
        }
        Node* temp = head;
        for (int i = 1; i < position && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr){
            cout <<"Invalid position"<<endl;
        } else {
            temp->data = value;
            cout <<"Node updatd successfully"<<endl;
        }
    }
    void display(){
        if (head == nullptr) {
           cout <<"List is emtpy"<<endl;
            return;
        }
        Node *temp = head;
        while (temp != nullptr) {
            cout<< temp->data << "->";
            temp = temp->next;
        }
        cout << "nullptr"<<endl;
    }
};
int main(){
    LinkedList list;
    int choice, value, position;
    do {
        cout << "1. Insert"<<endl;
        cout<< "2. Search"<<endl;
        cout << "3. Update"<<endl;
        cout << "4. Display"<<endl;
        cout << "5.Exit"<<endl;
        cout << "Enter  choice :"<<endl;
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value:"<<endl;
                cin >> value;
                cout<< "Enter position :"<<endl;
                cin >> position;
                list.insertPosition(value, position);
                list.display();
                break;
            case 2:
                cout << "Enter position:"<<endl;
                cin >> position;
                list.searchAtPosition(position);
                break;
            case 3:
                cout << "Enter new value:"<<endl;
                cin >> value;
                cout << "Enter positon: "<<endl;
                cin >> position;
                list.updatePosition(value, position);
                list.display();
                break;
            case 4:
                list.display();
                break;
            case 5:
                cout<< "Exitingg"<<endl;
                break;
            default:
                cout << "Invalid choise"<<endl;
        } 
    } while (choice != 5);
    return 0;
}
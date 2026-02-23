#include <iostream>
using namespace std;
class nodetype {
public:
    int data;
    nodetype* next;
};

nodetype* first = nullptr;
nodetype* last = nullptr;

void insert_end(){
    nodetype *p;
    p = new nodetype;
    cout <<"Enter the data in node:"<<endl;
    cin >> p->data;
    p->next = nullptr;

    if (first == nullptr){
        first = last = p;
    } else {
        last->next = p;
        last = p;
    }
}

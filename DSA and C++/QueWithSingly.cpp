#include <iostream>
using namespace std;
class QueWithSingly
{
    struct Node
    {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };
public:
    int size; 
    int count;
    Node* front;
    Node* rear;
    QueWithSingly(int s)
    {
        size = s;
        count = 0;
        front = rear = nullptr;
    }
    bool isEmpty()
    {
        return front == nullptr;
    }
    bool isFull()
    {
        return count == size;
    }
    void enqueue(int n)
    {
        if (isFull())
        {
            cout << "Queue is Full" << endl;
            return;
        }
        Node* temp = new Node(n);
        if (isEmpty())
        {
            front = rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
        count++;
    }
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty " << endl;
            return -1;
        }
        int x = front->data;
        Node* del = front;
        front = front->next;
        delete del;
        count--;
        if (front == nullptr)
            rear = nullptr;
        return x;
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty " << endl;
            return;
        }

        Node* cur = front;
        int i = 0;
        while (cur != nullptr)
        {
            cout << "value at index " << i << " is: " << cur->data << endl;
            cur = cur->next;
            i++;
        }
    }
    QueWithSingly()
    {
        while (!isEmpty())
            dequeue();
    }
};
int main()
{
    QueWithSingly mq(6);
    mq.enqueue(34);
    mq.enqueue(44);
    mq.enqueue(54);
    mq.display();
    cout << "dequeue element is :" << mq.dequeue() << endl;
    mq.display();
    return 0;
}
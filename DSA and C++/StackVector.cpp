#include <iostream>
#include <vector>
using namespace std;

class StackUsingVector {
private:
    vector<int> arr;
public:
    void push(int value) {
        arr.push_back(value);
    }
    void pop() {
        if (arr.empty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        arr.pop_back();
    }
    void display() const {
        if (arr.empty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        for (int i = static_cast<int>(arr.size()) - 1; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    StackUsingVector stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    cout << "Stack using vector:" << endl;
    stack.display();
    stack.pop();
    cout << "After pop:" << endl;
    stack.display();
    return 0;
}

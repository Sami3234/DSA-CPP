#include <algorithm>
#include <iostream>
using namespace std;

int H[50];
int heapSize = -1;
int parent(int i)
{
    return (i - 1) / 2;
}
void shiftUp(int i)
{
    while (i > 0 && H[parent(i)] < H[i]) {
        swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}
void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}
int main() {
    insert(10);
    insert(20);
    insert(5);
    for (int i = 0; i <= heapSize; i++) {
        cout << H[i] << " ";
    }
    cout << '\n';
    return 0;
}